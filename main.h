#include "core/String.h"
#include "main/Color.h"
#include<glad/glad.h>
#include<GLFW/glfw3.h>
namespace enginecore {
    Rgb bgcolor(0.0f, 0.0f, 0.0f);
    int width, height = 0;

    void setBGcolor_vals(float r, float g, float b) {
        bgcolor.setRVal(r);
        bgcolor.setGVal(g);
        bgcolor.setBVal(b);
    }
    
    void framebuffersizecallback(GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    }

    void processInput(GLFWwindow* window) {
        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, true);
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
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        
        GLFWwindow* window = glfwCreateWindow(width, height, title.str, NULL, NULL);
        if(window == NULL) {
            glfwTerminate();
        }
        glfwMakeContextCurrent(window);
        glfwSetFramebufferSizeCallback(window, framebuffersizecallback);

        if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
            cout << "glad not processed" << endl;
            glfwTerminate();
        }

        while(!glfwWindowShouldClose(window)) {
            processInput(window);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            Rgb test(255.0f, 0.0f, 0.0f);
            glClearColor(test.redval/255, test.greenval, test.blueval, 0.0f);
            glfwSwapBuffers(window);
            glfwPollEvents();
        }
        glfwTerminate();
    }
}