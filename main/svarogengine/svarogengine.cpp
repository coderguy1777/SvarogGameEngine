#include "svarogengine.h"
// note to self: 
// in order to use the imgui docking, dockspace is needed in this case
// by including the imgui_internal.h header file to use the given methods
// for docking in this case.
#if defined(IMGUI_IMPL_OPENGL_LOADER_GLAD)
#include<glad/glad.h>
#endif
#include<experimental/optional>

#include <boost/thread.hpp>
SvarogEngine* SvarogEngine::getInstanceEngine() {
    if(!engine_instance) {
        engine_instance = new SvarogEngine;
    }
    return engine_instance;
}

void SvarogEngine::InitGuiManager() {
    SLabEditorGUI::getSlabEditor()->init_editor();
}

void SvarogEngine::InitThreadManager() {
    spdlog::info("THREAD_MANAGER_READY.");
}

void SvarogEngine::InitMaterialManager() {
    spdlog::info("MATERIAL_MANAGER_READY.");
}

void SvarogEngine::InitRenderManager() {
    spdlog::info("RENDER_TASK_MANAGER_READY.");
    RenderTaskManager::getRenderManager()->set_render_state(1);
}

void SvarogEngine::InitContext() {
    spdlog::info("WINDOW CONTEXT INITIALIZED");
    EngineWindow::getInstance()->VSYNC_on();
}

void SvarogEngine::InitMonitor() {
    spdlog::info("WINDOW MONITOR INITIALIZED");
    svarog_monitor->init_monitor();
}

void SvarogEngine::RunEngine() {
    EngineWindow::getInstance()->SvarogAppLoop();
    InitContext();  
    InitMonitor();
    InitRenderManager();
    std::string vert_shader, frag_shader;
    std::ifstream vert, frag;
    vert.exceptions(std::ifstream::failbit);
    frag.exceptions(std::ifstream::failbit);

    try {
        vert.open("/home/jordan/Documents/SvarogGameEngine/render-pipeline/shader/engine_shader/mainvertex_shader.glsl");
        frag.open("/home/jordan/Documents/SvarogGameEngine/render-pipeline/shader/engine_shader/mainfragment_shader.glsl");
        std::stringstream m_vert, m_frag;
        m_vert << vert.rdbuf();
        m_frag << frag.rdbuf();
        vert.close();
        frag.close();
        vert_shader = m_vert.str();
        frag_shader = m_frag.str();
    } catch (ifstream::failure e) {
        std::cout << e.what() << '\n';
    }


    const char* vert_s = vert_shader.c_str();
    const char* frag_s = frag_shader.c_str();
    VertexShader vert_m;
    vert_m.set_code(vert_s);
    vert_m.set_use_state();
    vert_m.compile_shader();
    FragmentShader frag_m; 
    frag_m.set_code(frag_s);
    frag_m.set_use_state();
    frag_m.compile_shader();
    ShaderProgram * test_prg = new ShaderProgram();
    test_prg->bind_shaders(vert_m, frag_m);

    

    float vertices[] = {
        0.5f, 0.5f, -0.5f,
        0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, 0.5f , -0.5f, 
        0.5f, 0.5f, -0.5f,
    };        
    
    unsigned int poss[] = {  
        0, 1, 3,  
        1, 2, 3,
        0, 1, 4,
    };

    SvarogShape mesh_tst;
    std::vector<float>vertt;
    std::vector<unsigned int>pos;

    for(int i = 0; i < 15; i++) {
        vertt.push_back(vertices[i]);
    }
    for(int j = 0; j < 9; j++) {
        pos.push_back(poss[j]);
    }
    
    mesh_tst.pass_position_data(pos);
    mesh_tst.pass_vert_data(vertt);
    mesh_tst.init();
    // renderable obj debug.
    RenderObj s;
    s.set_mesh_id(1);
    s.set_mesh_name(String("Debug_Mesh"));
    s.input_mesh(mesh_tst);
    s.set_render_flags(3, 49L, true, false, false);
    RenderObj y;
    y.set_mesh_id(20);
    y.set_mesh_name(String("Debug_Mesh_2"));
    y.input_mesh(mesh_tst);
    y.set_render_flags(10, 200L, false, false, true);
    RenderTaskManager::getRenderManager()->add_thread_task(s);
    RenderTaskManager::getRenderManager()->add_thread_task(y);

    // debug im gui context
    ImGuiInit::make_imgui_context(static_cast<GLFWwindow*>(EngineWindow::getInstance()->getWindow()), "#version 400");
    ImGuiInit::make_imgui_style(0);
    ImGuiInit::imgui_ini_use(false);
    SvarogMaterial mat_a(*test_prg);
    mat_a.set_material_name("Default");
    mat_a.set_mesh(s);
    mat_a.set_material_roughness(0.5f);
    mat_a.set_material_specular(-0.2f);

    if(SLabEditorGUI::getSlabEditor()->color_picker_is_active()) {
        spdlog::info("Is active");
        auto m_values = SLabEditorGUI::getSlabEditor()->get_current_color_values();
    }
    ShaderManager::getShaderManager()->add_new_material(mat_a);
    Camera * engine_cam = new Camera();
    engine_cam->set_main_state(true);
    engine_cam->update_camera_vec(0.0f, 1.0f, 0.0f);

    engine_cam->translate_camera();

    auto cam_mat = engine_cam->get_cam_mat();
    while(EngineWindow::getInstance()->get_state()) {
        glm::mat4 trans = cam_mat;
        glUniformMatrix4fv(glGetUniformLocation(test_prg->get_shader_id(), "transform"), 1, GL_FALSE, glm::value_ptr(trans));
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_LIGHTING | GL_COLOR_MATERIAL);
        glClearColor(1.0, 0.0, 0.0, 1.0);
        ImGuiInit::init_imgui_frames();
        RenderTaskManager::getRenderManager()->add_thread_task(s);
        RenderTaskManager::getRenderManager()->run_all_tasks();
        ShaderManager::getShaderManager()->render_materials();

        InitGuiManager();
        //dbg_win->render_frames();
        ImGuiInit::init_imgui_render();
        EngineWindow::getInstance()->OnUpdate();
    }
    RenderTaskManager::getRenderManager()->run_optimize_tasks();
    ImGuiInit::init_imgui_shutdown();
}
SvarogEngine* SvarogEngine::engine_instance = 0;