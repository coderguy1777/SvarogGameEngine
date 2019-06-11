#include "core/String.h"
#include "main/color/Color.h"
#include<glad/glad.h>
#include<GLFW/glfw3.h>
namespace enginecore {
    int width, height = 0;
    const char *shader="#version 400\n"
    "in vec3 vp;"
    "void main() {"
    "  gl_Position = vec4(vp, 1.0);"
    "}";
    const char *fragmentShaderSource = "#version 400\n"
    "out vec4 frag_colour;"
    "void main() {"
    "  frag_colour = vec4(0.5, 0.2, 0.2, 0.0);"
    "}";
    void framebuffersizecallback(GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    }

    void processInput(GLFWwindow* window) {
        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, true);
        }

        if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
            std::cout << "A Key pressed?" << std::endl;
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

        // compiling of shader
        GLuint VertShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(VertShader, 1, &shader, NULL);
        glCompileShader(VertShader);

        // shader success
        int success;
        char infolog[512];
        glGetShaderiv(VertShader, GL_COMPILE_STATUS, &success);
        if(!success) {
            glGetShaderInfoLog(VertShader, 512, NULL, infolog);
            cout << "SHADER FAILED, '\n'INFO ON FAILURE:'\n'" << infolog << endl;
        }
        GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragShader, 1, &fragmentShaderSource, NULL);
        glCompileShader(fragShader);
        glGetShaderiv(fragShader, GL_COMPILE_STATUS, &success);
        if(!success) {
            glGetShaderInfoLog(fragShader, 512, NULL, infolog);
            cout << "SHADER FAILED, '\n'INFO ON FAILURE:'\n'" << infolog << endl;
        }
        // compiling of shader program
        GLuint shaderProgram = glCreateProgram();

        // attaching of shaders
        glAttachShader(shaderProgram, VertShader);
        glAttachShader(shaderProgram, fragShader);
        glLinkProgram(shaderProgram);
        glGetShaderiv(shaderProgram, GL_LINK_STATUS, &success);
        if(!success) {
            glGetProgramInfoLog(shaderProgram, 512, NULL, infolog);
            cout << "Shader program compile failed. '\n' info on crash:'\n'" << infolog << endl;
        }

        // making of shape
        float verticies[] {
            -0.5, -0.5, 0.0,
            0.5, -0.5, 0.0,
            0.0, 0.5, 0.0,
        };
        unsigned int VBO, VAO;
        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);

        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3* sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
        while(!glfwWindowShouldClose(window)) {
            processInput(window);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            Rgb test(255.0f, 0.0f, 0.0f);
            glClearColor(test.redval/255, test.greenval, test.blueval, 0.0f);
            glUseProgram(shaderProgram);
            glBindVertexArray(VAO);
            glDrawArrays(GL_TRIANGLES, 0, 3);
            glfwSwapBuffers(window);
            glfwPollEvents();
        }
        glfwTerminate();
    }
}