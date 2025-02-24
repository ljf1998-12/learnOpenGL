#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <glad/glad.h> //先包含glad, 后包含glfw
#include <GLFW/glfw3.h>
using namespace std;
//渲染程序标识
static GLuint renderingProgram;
//顶点个数
#define numVAOs 1
//顶点数组
GLuint vao[numVAOs];
//窗口长宽
GLuint SCR_WIDTH = 800;
GLuint SCR_HEIGHT = 600;

bool init(GLFWwindow* window);
bool addShader(const string &shader_path, GLenum shaderType,GLuint vfProgram);
GLuint createShadersProgram(void);
static void my_print_error(const string &s_err);
static void error_callback(int error, const char *description);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
static bool read_shader_file(const string &shader_path, string &str_content);

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
        glfwTerminate();
		return -1;
	}
    //设置GLFW按键回调
    glfwSetKeyCallback(window, key_callback); 
    //设置缓冲区交换机制
    glfwSwapInterval(1); 
    if(init(window)){
        //设置OpenGL默认缓冲底色
        glClearColor(1.0, 0.0, 0.0, 1.0);
        //清空缓冲区
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(renderingProgram);
        glPointSize(30.0f); //设置点的大小为30
        glDrawArrays(GL_POINTS, 0, 1);
        //交换缓冲区
        glfwSwapBuffers(window);
    }
    while (!glfwWindowShouldClose(window)){
        //处理屏幕事件
        cout << "glfwPollEvents" << endl;
        glfwPollEvents();
    }
    //关闭窗口
    glfwDestroyWindow(window);
    //终止glfw
    glfwTerminate();
    //程序退出
    exit(EXIT_SUCCESS);
}
bool init(GLFWwindow* window) {
    //创建渲染程序并获取其标识符
    renderingProgram = createShadersProgram();
    if(false == renderingProgram){
        my_print_error("createShadersProgram");
        return false;
    }
    //创建顶点标识符数组
    glGenVertexArrays(numVAOs, vao);
    glBindVertexArray(vao[0]);
    return true;
}
bool addShader(const string &shader_path, GLenum shaderType,GLuint vfProgram) {
    string svshaderSource;
    if(!read_shader_file(shader_path,svshaderSource)){
        my_print_error("read_shader_file"+shader_path);
        return false;
    }
    cout << svshaderSource << endl;
    const char *vshaderSource = svshaderSource.c_str();
    GLuint shaderRefNum = glCreateShader(shaderType);
    glShaderSource(shaderRefNum, 1, &vshaderSource, NULL);
    glCompileShader(shaderRefNum);
    glAttachShader(vfProgram, shaderRefNum);
    return true;
}   
GLuint createShadersProgram() {
    GLuint vfProgram = glCreateProgram();
    const string vshader_path("D:\\OneDrive\\图片\\learnopengl\\src\\09\\vshaderSource.glsl");
    const string fshader_path("D:\\OneDrive\\图片\\learnopengl\\src\\09\\fshaderSource.glsl");
    if(!addShader(vshader_path,GL_VERTEX_SHADER,vfProgram)){
        my_print_error("addShader");
        return false;
    }
    if(!addShader(fshader_path,GL_FRAGMENT_SHADER,vfProgram)){
        my_print_error("addShader");
        return false;
    }
    glLinkProgram(vfProgram);
    cout << "vfProgram: " << vfProgram << endl;
    return vfProgram;
}
//输出错误信息
void my_print_error(const string &s_err){
	cerr << "ERR:" << s_err << endl;
}
//glfw错误回调
void error_callback(int error, const char *description){
	fprintf(stderr, "Error: %s\n", description);
}
//glfw按键回调
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){//ESC按键回调函数
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}
bool read_shader_file(const string &shader_path, string &str_content){
    str_content.clear();
    string str_line;
    ifstream istrm(shader_path, ios::in);
    if(istrm.is_open()){
        return false;
    }
    while(!istrm.eof()){
        getline(istrm, str_line);
        str_content.append(str_line+'\n');
    }
    return true;
} 