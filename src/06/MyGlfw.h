#ifndef _MYGLFW_H_
#define _MYGLFW_H_

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include"MyError.h"

static void error_callback(int error, const char *description){
	fprintf(stderr, "Error: %s\n", description);
}

class MyGlfw{
public:
MyGlfw(const int width=800, const int hight=600):scrWidth{width},scrHight{hight}{
}
bool init();

private:
	GLFWwindow *pwindow;
	const int scrWidth;
	const int scrHight;
};

#endif