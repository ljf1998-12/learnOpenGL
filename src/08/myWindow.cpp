#include <iostream>
#include"myWindow.h"
#include"ProcessError.h"
static void error_callback(int error, const char *description){
	fprintf(stderr, "Error: %s\n", description);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){//ESC按键回调函数
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}
bool myWindow::init(){
    glfwSetErrorCallback(error_callback);
    if(!glfwInit()){
		my_print_error("glfwInit");
		return -1;
	}
    set_bglfwNeedTerminate();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //设置opengl主版本
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); //设置opengl次版本
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //设置OpenGL核心模式

	GLFWwindow *window = glfwCreateWindow(scrWidth, scrHight, "LearnOpenGL", NULL, NULL); //创建窗口和上下文
	if (window == NULL)
	{
		my_print_error("glfwCreateWindow");
		return -1;
	}
    glfwMakeContextCurrent(window); //设置当前上下文
	
	glfwSetKeyCallback(window, key_callback); //设置GLFW按键回调

}

bool myWindow::windowShouldBeClosed(){
    if(glfwWindowShouldClose(pglfwWindow)){
        return true;
    }
    return false;
}
void myWindow::teminate(){
    if(bglfwNeedTerminate){
        glfwTerminate();
        my_print_message("glfwTerminate");
    }
}
void myWindow::set_bglfwNeedTerminate(){
    bglfwNeedTerminate = true;
}