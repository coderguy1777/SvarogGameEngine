#include "libs.h"
namespace enginecore {
    KeyEvt event;
    int width, height = 0;
    float num = 0.0f;

    void increaseNum(int fac) {
        num += fac;
        cout << "NUM is: " << num << endl;
    }
    void framebuffersizecallback(GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    }

    void processInput(GLFWwindow* window) {
        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, true);
        }

        if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
            KeyBoard::keyProcess(0);
            num -= 0.01f;
        }

        if(glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS) {
            KeyBoard::keyProcess(1);
            num += 0.1f;
            randoms();
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

        // shaders
        String vertexpath("/home/jordan/Documents/SvarogGameEngine/main/shaders/VertexShader.glsl");
        String fragmentpath("/home/jordan/Documents/SvarogGameEngine/main/shaders/FragmentShader.glsl");
        Material test3(vertexpath.str, fragmentpath.str);
        
        // verticies
        float verticies[] {
            0.5f,  0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
           -0.5f, -0.5f, 0.0f,
           -0.5f,  0.5f, 0.0f 
        };
        // triangle indicies
        unsigned int indicies[] {
            0, 1, 3,
            1, 2, 3
        };
        unsigned int VBO, VAO, EBO;
        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicies), indicies, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3* sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);

        // shader transform
      
        // window loop
        while(!glfwWindowShouldClose(window)) {
            processInput(window);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glClearColor(1.0, 0.0, 1.0, 1.0);
            glm::mat4 translae = glm::mat4(1.0f);
            translae = glm::translate(translae, glm::vec3(-0.5f, 0.0f, num));
            translae = glm::rotate(translae, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
            glUseProgram(test3.shaderID);
            unsigned int trans = glGetUniformLocation(test3.shaderID, "transform");
            glUniformMatrix4fv(trans, 1, GL_FALSE, glm::value_ptr(translae));
            glBindVertexArray(VAO);
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
            glfwSwapBuffers(window);
            glfwPollEvents();
        }
        // deletes buffers
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
        glDeleteBuffers(1, &EBO);
        glfwTerminate();
    }
}