#include "svarogengine.h"
#if defined(IMGUI_IMPL_OPENGL_LOADER_GLAD)
#include<glad/glad.h>
#endif
SvarogEngine* SvarogEngine::getInstanceEngine() {
    if(!engine_instance) {
        engine_instance = new SvarogEngine;
    }
    return engine_instance;
}

void SvarogEngine::InitContext() {
    EngineWindow::getInstance()->VSYNC_on();
}


void SvarogEngine::InitMonitor() {
    svarog_monitor->init_monitor();
}

void SvarogEngine::RunEngine() {
    EngineWindow::getInstance()->SvarogAppLoop();
    InitContext();
    InitMonitor();
    std::string vert_shader, frag_shader;
    std::ifstream vert, frag;
    vert.exceptions(std::ifstream::failbit);
    frag.exceptions(std::ifstream::failbit);
    try {
        vert.open("/home/jordan/Documents/SvarogGameEngine/render-pipeline/shader/engine_shader/mainvertex_shader.glsl");
        frag.open("/home/jordan/Documents/SvarogGameEngine/render-pipeline/shader/engine_shader/mainfragment_shader.glsl");
        std::stringstream aa, aba;
        aa << vert.rdbuf();
        aba << frag.rdbuf();
        vert.close();
        frag.close();
        vert_shader = aa.str();
        frag_shader = aba.str();
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
    SvarogMaterial debug_mat;
    debug_mat.is_assigned_to_mesh();
    debug_mat.set_material_name("frag_color");
    debug_mat.set_rgb(Rgb(1.0, 0.5, 1.0));
    debug_mat.set_primary_color_model(COLOR_MODEL::RGB_MODEL);
    ShaderGeneration::generateShaderCode()->input_mat(debug_mat);
    ShaderGeneration::generateShaderCode()->make_shaders();
    ShaderGeneration::generateShaderCode()->send_shaders();

    float vertices[] = {
        0.5f,  0.5f, -0.5f, 
        0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, 0.5f , -0.5f, 
        0.5f, -0.5f , 0.5f, 
        0.5f, 0.5f , 0.5f, 
    };        
    
    unsigned int poss[] = {  
        0, 1, 3,  
        1, 2, 3,
        0, 1, 2,
    };

    SvarogShape mesh_tst;
    std::vector<float>vertt;
    std::vector<unsigned int>pos;

    for(int i = 0; i < 18; i++) {
        vertt.push_back(vertices[i]);
    }
    for(int j = 0; j < 9; j++) {
        pos.push_back(poss[j]);
    }
    mesh_tst.pass_position_data(pos);
    mesh_tst.pass_vert_data(vertt);
    mesh_tst.init();
    // renderable obj debug.
    RenderObj* s = new RenderObj();
    s->set_mesh_id(1);
    s->set_mesh_name(String("Debug_Mesh"));
    s->input_mesh(mesh_tst);
    // debug im gui context
    ImGuiInit::make_imgui_context(static_cast<GLFWwindow*>(EngineWindow::getInstance()->getWindow()), "#version 400");
    ImGuiInit::make_imgui_style(0);
    SvarogGuiFrame * test = new SvarogGuiFrame(true, true, "Shaders", 500, 500);
    char* debug = new char[3];
    debug[0] = 'e';
    debug[1] = 'd';
    while(EngineWindow::getInstance()->get_state()) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(1.0, 0.0, 0.0, 1.0);
        test_prg->use();
        ImGuiInit::init_imgui_frames();
        test->begin_gui_frame();
        {
            ImGui::SetCursorPos(ImVec2(10, 10));
            SvarogButton dbg_btn(100, 60, "Debug_Button", true);
            SvarogInputText ad("Steve", debug ,3);
            static float size_m = 0.0f;
            ImGui::SliderFloat("Debug_Slider", &size_m, 0.0f, 1.0f);
        }
        test->end_gui_frame();
        s->get_mesh().draw();
        ImGuiInit::init_imgui_render();
        EngineWindow::getInstance()->OnUpdate();
    }
    s->get_mesh().del_buffers();
    ImGuiInit::init_imgui_shutdown();
}
SvarogEngine* SvarogEngine::engine_instance = 0;
