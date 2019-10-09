#include "svarogengine.h"
#if defined(IMGUI_IMPL_OPENGL_LOADER_GLAD)
#include<glad/glad.h>
#endif

SvarogEngine* SvarogEngine::getInstanceEngine() {
    if(!engine_instance) engine_instance = new SvarogEngine; return engine_instance;
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
    const char* shader_tst_1 = "#version 400\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position=vec4(aPos, 1.0);\n"
        "}\0";
    
    const char* shader_tst_2 ="#version 400\n"
        "out vec4 frag_color;\n"
        "uniform float r;\n"
        "void main()\n"
        "{\n"
        "   frag_color = vec4(r, 0.5, 1.0, 1.0);\n"
        "}\n\0";
    SvarogMaterial ac;
    ac.write_shader(shader_tst_1, shader_tst_2);
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
    std::vector<float>vert;
    std::vector<unsigned int>pos;

    for(int i = 0; i < 18; i++) {
        vert.push_back(vertices[i]);
    }
    for(int j = 0; j < 9; j++) {
        pos.push_back(poss[j]);
    }
    mesh_tst.pass_position_data(pos);
    mesh_tst.pass_vert_data(vert);
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
    while(EngineWindow::getInstance()->get_state()) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(1.0, 0.0, 0.0, 1.0);
        ac.run();
        ImGuiInit::init_imgui_frames();
        test->begin_gui_frame();
        {
            ImGui::SetCursorPos(ImVec2(10, 10));
            SvarogButton a(100, 60, "Debug_Button", true);
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