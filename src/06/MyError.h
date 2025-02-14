#ifndef _MYERROR_H_
#define _MYERROR_H_
#include <iostream>
using namespace std;

void my_print_error(const string &s_err){
	cerr << "ERR:" << s_err << endl;
}
#endif