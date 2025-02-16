#include <iostream>
#include <glad/glad.h> //先包含glad, 后包含glfw
#include <GLFW/glfw3.h>
using namespace std;

//输出错误信息
static void my_print_error(const string &s_err){
	cerr << "ERR:" << s_err << endl;
}
//glfw错误回调
static void error_callback(int error, const char *description){
	fprintf(stderr, "Error: %s\n", description);
}
//glfw按键回调
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){//ESC按键回调函数
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

//窗口长宽
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main(){
    //设置glfw错误回调
    glfwSetErrorCallback(error_callback);
    //glfw初始化
	if(!glfwInit()){
		my_print_error("glfwInit");
		return -1;
	}
    //设置OpenGL上下文版本和模式
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //设置opengl主版本
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); //设置opengl次版本
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //设置OpenGL核心模式
    //创建窗口和上下文
	GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL); 
	if (window == NULL)
	{
		my_print_error("glfwCreateWindow");
		glfwTerminate();
		return -1;
	}
    //设为当前上下文
    glfwMakeContextCurrent(window); 
    //加载glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {//加载glad
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
    //设置GLFW按键回调
    glfwSetKeyCallback(window, key_callback); 
    //设置缓冲区交换机制
    glfwSwapInterval(1); 
    //设置OpenGL默认底色
    glClearColor(1.0, 0.0, 0.0, 1.0);
    //清空缓冲区
    glClear(GL_COLOR_BUFFER_BIT);
    //交换缓冲区
    glfwSwapBuffers(window);
    while (!glfwWindowShouldClose(window)){
        //处理屏幕事件
        glfwPollEvents();
    }
    //关闭窗口
    glfwDestroyWindow(window);
    //终止glfw
    glfwTerminate();
    //程序退出
    exit(EXIT_SUCCESS);
}