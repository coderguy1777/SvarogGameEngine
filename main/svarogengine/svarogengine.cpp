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

    VertexShader vert_mat;
    vert_mat.init_state(2);
    vert_mat.set_use_state();
    vert_mat.set_code(shader_tst_1);
    FragmentShader frag_mat;
    frag_mat.init_state(1);
    frag_mat.set_use_state();
    frag_mat.set_code(shader_tst_2);
    vert_mat.compile_shader();
    frag_mat.compile_shader();
    ShaderProgram* test_1 = new ShaderProgram();
    test_1->bind_shaders(vert_mat, frag_mat);

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
    test_1->use();
    ImGuiInit::make_imgui_context(static_cast<GLFWwindow*>(EngineWindow::getInstance()->getWindow()), "#version 400");
    ImGuiInit::make_imgui_style(2);
    while(EngineWindow::getInstance()->get_state()) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(1.0, 0.0, 0.0, 1.0);
        // shader & imgui test.
        // TODO: design engine gui and docks.
        float xx = glfwGetTime();
        float x_1 = 0.5f;
        float x_2 = 0.4f;
        float x_3 = 1.0f;
        float y = sin(xx / 2.0f) * 500.0f;
        glUniform4f(glGetUniformLocation(test_1->get_shader_id(), "float_tst"), 0.0f, y, 0.0f, 1.0f);
            glUniform1f(glGetUniformLocation(test_1->get_shader_id(), "r"), x_1);
            glUniform1f(glGetUniformLocation(test_1->get_shader_id(), "g"), x_2);
        glUniform1i(glGetUniformLocation(test_1->get_shader_id(), "b"), x_3);
        ImGuiInit::init_imgui_frames();
        
        ImGui::Begin("Hello");
        
        static float check_val = 0.f;
        ImGui::SliderFloat("SliderTest", &check_val, 0.0f, 1.0f);
        glUniform1f(glGetUniformLocation(test_1->get_shader_id(), "b"), check_val);
        ImGui::End();

        x.get(0)->get_mesh().draw();
        ImGuiInit::init_imgui_render();
        EngineWindow::getInstance()->OnUpdate();
    }
    x.get(0)->get_mesh().del_buffers();
    glDeleteShader(vert_mat.get_shader_id());
    glDeleteShader(frag_mat.get_shader_id());
    ImGuiInit::init_imgui_shutdown();
}
SvarogEngine* SvarogEngine::engine_instance = 0;