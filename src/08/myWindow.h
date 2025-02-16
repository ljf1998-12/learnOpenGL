#ifndef _MY_WINDOW_H
#define _MY_WINDOW_H

#define GLFW_INCLUDE_NONE //允许glfw头文件包含顺序任意
#include <GLFW/glfw3.h>

class myWindow
{
public:
//默认窗口长宽
myWindow(const int width=800, const int hight=600):scrWidth{width},scrHight{hight}{
}
bool init();
bool windowShouldBeClosed();
void teminate();

private:
//窗口长宽不可变
const int scrWidth;
const int scrHight;
GLFWwindow *pglfwWindow;
bool bglfwNeedTerminate=false;

void set_bglfwNeedTerminate();
};

#endif