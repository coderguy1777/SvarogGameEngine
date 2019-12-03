#include "svarogengine.h"
#if defined(IMGUI_IMPL_OPENGL_LOADER_GLAD)
#include<glad/glad.h>
#endif
#include <boost/thread.hpp>
SvarogEngine* SvarogEngine::getInstanceEngine() {
    if(!engine_instance) {
        engine_instance = new SvarogEngine;
    }
    return engine_instance;
}

void SvarogEngine::InitGuiManager() {
    bool btn_val, btn_val2;
    String debug_name = String("Debug");
    ImGuiLayer* debug_layer = new ImGuiLayer(debug_name, 3);
    debug_layer->pass_frame_data(Layer_Pos::FRAME_LEFT, false, false);
    debug_layer->add_button(ButtonData{String("Test_Button"), btn_val, ButtonPosition{100, 100}, 0});
    debug_layer->add_button(ButtonData{String("Test_Button2"), btn_val2, ButtonPosition{150, 150}, 1});
    std::function<void()>labels;
    debug_layer->add_label(LabelData{String("Label_1"), labels, LabelPosition{30, 30}, 30});
    ClassString* debug_class_str = debug_layer->get_layer_name();
    SvarogGuiFrame ca(true, true, String("Debug_Frame"), 300, 600);
    bool is_right = (debug_class_str->get_class_id() <= 5 || debug_class_str->get_class_id() >= 0) ? true : false;
    bool is_left = (debug_class_str->get_class_id() >= 6 || debug_class_str->get_class_id() <= 10) ? true : false;
    ca.set_frame_pos(false, 200.0f, 0);
    debug_layer->init_all();  
    String debug_2 = String("Debug_2");
    ImGuiLayer * debug_layer_2 = new ImGuiLayer(debug_2, 2);
    debug_layer_2->pass_frame_data(Layer_Pos::FRAME_RIGHT, false, false);
    bool btn_val_3, btn_val_4;
    debug_layer_2->add_button(ButtonData{String("Test2_Button"), btn_val_3, ButtonPosition{90, 50}, 0});
    debug_layer_2->add_button(ButtonData{String("Test3_Button"), btn_val_4, ButtonPosition{50, 74}, 2});
    debug_layer_2->init_all();
    SvarogGuiFrame * test = new SvarogGuiFrame(true, true, "Shaders", 300, 300);
    test->add_gui_layer(*debug_layer);
    test->add_gui_layer(*debug_layer_2);
    test->set_frame_pos(false, 100, 0);
    char* debug = new char[3];
    debug[0] = 'e';
    debug[1] = 'd';
    SvarogGuiWindow * dbg_win =  new SvarogGuiWindow();
    ca.add_gui_layer(*debug_layer);
    ca.add_gui_layer(*debug_layer_2);

    dbg_win->insert_to_stack(ca);
    dbg_win->insert_to_stack(*test);
    GuiTaskManager::getGuiManagerInstance()->add_thread_task(*dbg_win);

    /*
    if(GuiTaskManager::getGuiManagerInstance()->get_task_amount() > 0) {
        spdlog::info("GUI_MANAGER_READY.");
    } else {
        spdlog::error("GUI TASKS NOT ADDED SUCCESSFULLY");
        exit(0);
    }
    */
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

    float vertices[] = {
        0.5f, 0.5f, -0.5f,
        0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, 0.5f , -0.5f, 
        1.0f, 1.5f, -1.5f,
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

    //RenderTaskManager::getRenderManager()->add_thread_task(s);
    // debug im gui context
    ImGuiInit::make_imgui_context(static_cast<GLFWwindow*>(EngineWindow::getInstance()->getWindow()), "#version 400");
    ImGuiInit::make_imgui_style(0);
    ImGuiInit::imgui_ini_use(false);
    


    test_prg->use();
    while(EngineWindow::getInstance()->get_state()) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(1.0, 0.0, 0.0, 1.0);
        ImGuiInit::init_imgui_frames();
        RenderTaskManager::getRenderManager()->add_thread_task(s);
        RenderTaskManager::getRenderManager()->run_all_tasks();
        InitGuiManager();
        GuiTaskManager::getGuiManagerInstance()->run_all_tasks();
        //dbg_win->render_frames();
        ImGuiInit::init_imgui_render();
        EngineWindow::getInstance()->OnUpdate();
    }
    RenderTaskManager::getRenderManager()->run_optimize_tasks();
    ImGuiInit::init_imgui_shutdown();
}
SvarogEngine* SvarogEngine::engine_instance = 0;