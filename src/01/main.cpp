#include <iostream>
#include <glad/glad.h> //先包含glad, 后包含glfw
#include <GLFW/glfw3.h>
using namespace std;

static void error_callback(int error, const char *description){
	fprintf(stderr, "Error: %s\n", description);
}
static void my_print_error(const string &s_err){
	cerr << "ERR:" << s_err << endl;
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){//ESC按键回调函数
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}
void framebuffer_size_callback(GLFWwindow *window, int width, int height);

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
	glfwSetErrorCallback(error_callback);
	if(!glfwInit()){
		my_print_error("glfwInit");
		return -1;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //设置opengl主版本
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); //设置opengl次版本
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //设置OpenGL核心模式

	GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL); //创建窗口和上下文
	if (window == NULL)
	{
		my_print_error("glfwCreateWindow");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window); //设置当前上下文
	
	glfwSetKeyCallback(window, key_callback); //设置GLFW按键回调

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) //加载glad
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	while (!glfwWindowShouldClose(window))
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate(); //终止GLFW
	return 0;
}
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
	glViewport(0, 0, width, height);
}
