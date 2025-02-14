#ifndef _MYGLFW_H_
#define _MYGLFW_H_

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include"MyError.h"

class MyGlfw{
private:

public:
MyGlfw(){
    glfwSetErrorCallback(error_callback);
    if(!glfwInit()){
		my_print_error("glfwInit");
		return -1;
	}
}
bool init

}

#endif