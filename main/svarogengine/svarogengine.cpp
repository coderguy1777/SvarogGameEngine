#include "svarogengine.h"

SvarogEngine* SvarogEngine::getInstanceEngine() {
    if(!engine_instance) engine_instance = new SvarogEngine; return engine_instance;
}


void SvarogEngine::InitContext() {
    EngineWindow::getInstance()->VSYNC_on();
}

void SvarogEngine::draw_meshes() {
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
    std::vector<float>a;
    std::vector<unsigned int>b;
    for(int i = 0; i < 18; i++) {
        a.push_back(vertices[i]);
    }
    for(int j = 0; j < 9; j++) {
        b.push_back(poss[j]);
    }
    mesh_tst.pass_position_data(b);
    mesh_tst.pass_vert_data(a);
    mesh_tst.init();

    SvarogShape tst_2; 
    tst_2.pass_position_data(b);
    tst_2.pass_vert_data(a);
    tst_2.init();
    
    RenderObj* s = new RenderObj();
    s->set_mesh_id(2);
    s->set_mesh_name(String("Hello"));
    s->input_mesh(mesh_tst);
    ArrayList<RenderObj*>x;

    x.add(s);
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
    SvarogShape mesh_tst;
    std::vector<float>a;
    std::vector<unsigned int>b;
    for(int i = 0; i < 18; i++) {
        a.push_back(vertices[i]);
    }
    for(int j = 0; j < 9; j++) {
        b.push_back(poss[j]);
    }
    mesh_tst.pass_position_data(b);
    mesh_tst.pass_vert_data(a);
    mesh_tst.init();

    SvarogShape tst_2; 
    tst_2.pass_position_data(b);
    tst_2.pass_vert_data(a);
    tst_2.init();
    
    RenderObj* s = new RenderObj();
    s->set_mesh_id(2);
    s->set_mesh_name(String("Hello"));
    s->input_mesh(mesh_tst);
    ArrayList<RenderObj*>x;

    x.add(s);
    while(EngineWindow::getInstance()->get_state()) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        x.get(0)->get_mesh().draw();
        glClearColor(1.0, 0.0, 0.0, 1.0);
        glUseProgram(test_1->get_shader_id());
        EngineWindow::getInstance()->OnUpdate();
    }
    x.get(0)->get_mesh().del_buffers();
    glDeleteShader(vert_mat.get_shader_id());
    glDeleteShader(frag_mat.get_shader_id());
}

SvarogEngine* SvarogEngine::engine_instance = 0;