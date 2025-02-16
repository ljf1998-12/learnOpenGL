#ifndef _PROCESS_ERROR_H_
#define _PROCESS_ERROR_H_
#include <iostream>
using namespace std;

void my_print_error(const string &s_err){
	cerr << "ERR:" << s_err << endl;
}
void my_print_message(const string &s_message){
	cout << "INFO:" << s_message << endl;
}
#endif