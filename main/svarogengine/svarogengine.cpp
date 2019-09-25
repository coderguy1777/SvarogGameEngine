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
        "uniform vec4 float_tst;\n"
        "uniform float time;\n"
        "void main()\n"
        "{\n"
        "   frag_color = vec4(sin(abs(time)), float_tst.y, float_tst.z, 1.0);\n"
        "}\n\0";
    
    ShaderGeneration ab("shader_frag.glsl", 400, 1, true);
    ArrayList<const char*>xss;
    xss.add("#version 400\n");
    xss.add("layout (location = 0) in vec3 aPos;\n");
    xss.add("out frag_color;\n");
    xss.add("uniform vec4 float_tst;\n");
    xss.add("uniform float time;\n");
    xss.add("void main()\n");
    xss.add("{\n");
    xss.add("   frag_color=vec4(sin(abs(time)), float_tst.y, float_tst.z, 1.0);\n");
    xss.add("}\n\0");
    ab.write_file(xss);
    if(ab.get_success() == 1) {
        spdlog::info("Shader written.");
    } else if(ab.get_success() != 1) {
        spdlog::info("WRITE_FAIL");
    }

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
    glEnable(GL_BLEND);

    test_1->use();
    while(EngineWindow::getInstance()->get_state()) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(1.0, 0.0, 0.0, 1.0);
        float xx = glfwGetTime();
        float y = sin(xx / 2.0f) * 500.0f;
        glUniform4f(glGetUniformLocation(test_1->get_shader_id(), "float_tst"), 0.0f, y, 0.0f, 1.0f);
        glUniform1f(glGetUniformLocation(test_1->get_shader_id(), "time"), xx);
        x.get(0)->get_mesh().draw();
        EngineWindow::getInstance()->OnUpdate();
    }
    x.get(0)->get_mesh().del_buffers();
    glDeleteShader(vert_mat.get_shader_id());
    glDeleteShader(frag_mat.get_shader_id());
}

SvarogEngine* SvarogEngine::engine_instance = 0;