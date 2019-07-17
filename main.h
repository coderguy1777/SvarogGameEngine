#include "libs.h"
namespace enginecore {
    KeyEvt event;
    int width, height = 0;
    void framebuffersizecallback(GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    }

    void processInput(GLFWwindow* window) {
        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, true);
        }

        if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
            cout << event.KEY_PRESSED(0) << endl;
        }
    }

    void initializeWindow(int w, int h, String title) {
        #ifdef __APPLE__ 
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        #endif
        width = w;
        height = h;
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_ANY_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        GLFWwindow* window;
        window = glfwCreateWindow(width, height, title.str, NULL, NULL);
        glfwMakeContextCurrent(window);
        glfwSetFramebufferSizeCallback(window, framebuffersizecallback);
        if(window == NULL) {
            glfwTerminate();
        }
        if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
            cout << "glad not processed" << endl;
            glfwTerminate();
        }

        String vertexpath("/home/jordan/Documents/SvarogGameEngine/main/shaders/VertexShader.glsl");
        String fragmentpath("/home/jordan/Documents/SvarogGameEngine/main/shaders/FragmentShader.glsl");
        Material test3(vertexpath.str, fragmentpath.str);
        float verticies[] {
            -0.5, -0.5, 
            0.5, -0.5, 
            0.0, 0.5,
        };
        unsigned int VBO, VAO;
        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);
        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2* sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
        while(!glfwWindowShouldClose(window)) {
            processInput(window);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glClearColor(1.0, 0.0, 1.0, 1.0);
            glUseProgram(test3.shaderID);
            glBindVertexArray(VAO);
            glDrawArrays(GL_TRIANGLES, 0, 3);
            glfwSwapBuffers(window);
            glfwPollEvents();
        }
        glDeleteVertexArrays(1, &VAO);
        glDeleteVertexArrays(1, &VBO);
        glfwTerminate();
    }
}