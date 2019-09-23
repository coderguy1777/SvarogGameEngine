#include "svarogengine.h"

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
        "void main()\n"
        "{\n"
        "   frag_color=vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
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

    std::vector<float>vertexdata;
    std::vector<unsigned int>posdata;
    for(int i = 0; i < 18; i++) {
        vertexdata.push_back(vertices[i]);
    }

    for(int j = 0; j < 9; j++) {
        posdata.push_back(poss[j]);
    }
    Shape drawer2(vertexdata, posdata);
    drawer2.noEBO();
    while(EngineWindow::getInstance()->get_state()) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(1.0, 0.0, 0.0, 1.0);
        drawer2.drawFunc();
        glUseProgram(test_1->get_shader_id());
        EngineWindow::getInstance()->OnUpdate();
    }
    glDeleteShader(vert_mat.get_shader_id());
    glDeleteShader(frag_mat.get_shader_id());
}

SvarogEngine* SvarogEngine::engine_instance = 0;