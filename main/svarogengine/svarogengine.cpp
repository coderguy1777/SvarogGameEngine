#include "svarogengine.h"

SvarogEngine* SvarogEngine::getInstanceEngine() {
    if(!engine_instance) engine_instance = new SvarogEngine; return engine_instance;
}

void SvarogEngine::InitContext() {
    EngineWindow::getInstance()->VSYNC_on();
    EngineWindow::getInstance()->set_statee();
}

void SvarogEngine::InitMonitor() {
    svarog_monitor->init_monitor();
}

void SvarogEngine::RunEngine() {
    EngineWindow::getInstance()->SvarogAppLoop();
    InitContext();
    InitMonitor();

    Material matA("/home/jordan/Documents/SvarogGameEngine/main/shaders/VertexShader.glsl", "/home/jordan/Documents/SvarogGameEngine/main/shaders/FragmentShader.glsl");
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
        matA.setFloat("xPOs", 0.5f);
        drawer2.drawFunc();
        glUseProgram(matA.shaderID);
        EngineWindow::getInstance()->OnUpdate();
    }
}

SvarogEngine* SvarogEngine::engine_instance = 0;