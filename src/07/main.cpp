#include <iostream>
#include <glad/glad.h> //先包含glad, 后包含glfw
#include <GLFW/glfw3.h>
using namespace std;

//错误回调函数设置为静态
static void error_callback(int error, const char *description){
	fprintf(stderr, "Error: %s\n", description);
}
//输出错误信息
static void my_print_error(const string &s_err){
	cerr << "ERR:" << s_err << endl;
}
//按键事件回调函数
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){//ESC按键回调函数
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}
int main(){
    //设置GLFW错误回调函数
    glfwSetErrorCallback(error_callback);
    if(!glfwInit()){
		my_print_error("glfwInit");
		return -1;
	}
    

    return 0;
}