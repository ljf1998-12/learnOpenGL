//全红窗口
#define GLEW_STATIC //静态连接grew
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
using namespace std;
void my_display(GLFWwindow* window) {
    glClearColor(1.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
}
int main(void) {
    if (!glfwInit()) { exit(EXIT_FAILURE); }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    GLFWwindow* window = glfwCreateWindow(600, 600, "Chapter2 - program1", NULL, NULL);
    glfwMakeContextCurrent(window);
    if (glewInit() != GLEW_OK) { exit(EXIT_FAILURE); }
    glfwSwapInterval(1); 
    int i = 0;
    if(!glfwWindowShouldClose(window) && i<=1){
        my_display(window);
        glfwSwapBuffers(window);
        ++i;
    }
    while (!glfwWindowShouldClose(window)) {
        //my_display(window);
        //glfwSwapBuffers(window);
        glfwPollEvents();
    }
    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl; //输出OpenGL版本
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}