#include "svarogengine.h"
SvarogEngine* SvarogEngine::getInstanceEngine() {
    if(!engine_instance) engine_instance = new SvarogEngine; return engine_instance;
}

void SvarogEngine::is_check() {

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
    VertexShader * vert_mat = new VertexShader();
    vert_mat->init_state(2);
    vert_mat->set_use_state();
    vert_mat->set_code("#version 400\nlayout (location = 0) in vec3 aPos;\nvoid main() {\n// transform applied\n\tgl_Position=aPos;\n};");
    vert_mat->compile_shader();
    FragmentShader * frag_mat = new FragmentShader();
    frag_mat->init_state(1);
    frag_mat->set_use_state();
    frag_mat->set_code("#version 400\nout vec3 frag_colour;\nvoid main() {\n\tfrag_colour=vec3(1.0f, 0.0f, 0.0f);\n};");
    frag_mat->compile_shader();

    GLuint shader_test = glCreateProgram();
    glAttachShader(shader_test, vert_mat->get_shader_id());
    glAttachShader(shader_test, static_cast<unsigned int>(frag_mat->get_shader_id()));
    glLinkProgram(shader_test);
    int success;
    char info[512];
    glGetShaderiv(shader_test, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(shader_test, 512, NULL, info);
        spdlog::error("ERROR: SHADER_PROGRAM FAILURE");
        EngineWindow::getInstance()->end();
    }
    glDeleteShader(vert_mat->get_shader_id());
    glDeleteShader(frag_mat->get_shader_id());

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
        glUseProgram(shader_test);
        EngineWindow::getInstance()->OnUpdate();
    }
}

SvarogEngine* SvarogEngine::engine_instance = 0;