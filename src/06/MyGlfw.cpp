#include"MyGlfw.h"

bool MyGlfw::init(){
    glfwSetErrorCallback(error_callback);
    if(!glfwInit()){
		my_print_error("glfwInit");
		return -1;
	}
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //设置opengl主版本
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); //设置opengl次版本
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //设置OpenGL核心模式
    glfwCreateWindow(scrWidth, scrHight, "LearnOpenGL", NULL, NULL);
}