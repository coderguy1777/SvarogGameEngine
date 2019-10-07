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
        "}\n\0";
    
    const char* shader_tst_2 ="#version 400\n"
        "out vec4 frag_color;\n"
        "uniform vec4 float_tst;\n"
        "uniform float time;\n"
        "uniform float r, g, b;\n"
        "float time_2;\n"
        "void main()\n"
        "{\n"
        "   frag_color = vec4(r, g, b, 1.0);\n"
        "}\n\0";

    Rgb c(1.0f, 1.0f, 0.5f);
    SvarogMaterial ac(c);
    ac.add_code();
    ac.write_shader();

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
    RenderObj* s = new RenderObj();
    s->set_mesh_id(2);
    s->set_mesh_name(String("Hello"));
    s->input_mesh(mesh_tst);
    ArrayList<RenderObj*>x;
    x.add(s);
    ImGuiInit::make_imgui_context(static_cast<GLFWwindow*>(EngineWindow::getInstance()->getWindow()), "#version 400");
    ImGuiInit::make_imgui_style(0);
    ac.run();
    while(EngineWindow::getInstance()->get_state()) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(1.0, 0.0, 0.0, 1.0);
        // shader & imgui test.
        // TODO: design engine gui and docks.
        ImGuiInit::init_imgui_frames();
        ImGui::Begin("GUI_TEST");
        ImGui::SetCursorPos(ImVec2(10, 10));
        SvarogButton a(50, 60, "Custom class button", true);
        static float size_m = 0.0f;
        ImGui::SliderFloat("Test", &size_m, 0.0f, 1.0f);
        ImGui::End();
        float x_1 = 0.5f;
        float x_2 = 0.4f;
        float x_3 = 1.0f;
        float xx = glfwGetTime();
        float y= sin(xx/2.0f) * 20.0f;
        x.get(0)->get_mesh().draw();
        ImGuiInit::init_imgui_render();
        EngineWindow::getInstance()->OnUpdate();
    }
    x.get(0)->get_mesh().del_buffers();
    ImGuiInit::init_imgui_shutdown();
}
SvarogEngine* SvarogEngine::engine_instance = 0;