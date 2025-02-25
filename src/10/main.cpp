#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <glad/glad.h> //先包含glad, 后包含glfw
#include <GLFW/glfw3.h>
using namespace std;
bool read_shader_file(const string &shader_path, string &str_content);
int main(){
    string svshaderSource;
    const string shader_path{"D:\\OneDrive\\learnopengl\\glsl\\10\\fshaderSource.glsl"};
    if(!read_shader_file(shader_path,svshaderSource)){
        cout << "ERR: " << endl << svshaderSource << endl;
        return -1;
    }
    cout << svshaderSource << endl << "good" << endl;
    return 0;
}
bool read_shader_file(const string &shader_path, string &str_content){
    str_content.clear();
    string str_line;
    ifstream istrm(shader_path, ios::in);
    if(!istrm.is_open()){
        cout << "!istrm.is_open()"<<  shader_path << endl;
        return false;
    }
    while(!istrm.eof()){
        getline(istrm, str_line);
        str_content.append(str_line+'\n');
    }
    return true;
} 