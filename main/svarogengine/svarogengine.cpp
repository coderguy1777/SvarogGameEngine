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
    static const char* shader_tst_1[] = {
        "#version 400                           \n"
        "layout (location=0) in vec3 aPos;      \n"
        "void main() {                          \n"
        "   gl_Position=aPos;                   \n"
        "};                                     \n"
    };

    static const char* shader_tst_2[] = {
        "#version 400                                               \n"
        "layout (location=0) out vec3 frag_colour;                  \n"
        "void main()                                                \n"
        "{                                                          \n"
        "   frag_colour=vec3(1.0, 1.0, 0.0);                        \n"
        "};                                                         \n"
    };

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
}

SvarogEngine* SvarogEngine::engine_instance = 0;