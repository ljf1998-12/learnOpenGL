#ifndef _MY_LOG_H_
#define _MY_LOG_H_
#define LOG_INFO(msg) print_log(__FILE__,__LINE__,INFO,msg);
#define LOG_ERR(msg) print_log(__FILE__,__LINE__,ERR,msg);

#include<string>
#include<fstream>
#include<sstream>
#include<ctime>
using namespace std;

enum log_level{
    INFO = 1,
    ERR = 2
};
string current_time(){
    time_t now = time(0);
    tm tstruct = *localtime(&now);
    char buf[64];
    strftime(buf,sizeof(buf),"%Y-%m-%d %X",&tstruct);
    return string(buf);
}

void print_log(const char *file,const int lineNumber,const log_level level, const string msg){
    stringstream log;
    if(INFO == level){
        log << "INFO ";
    }
    else if (ERR == level)
    {
        log << "ERR ";
    }
    log << current_time() << ' ';
    log << file << ':' << lineNumber << ' ';
    log << msg;
    ofstream logfile("D:\\OneDrive\\learnopengl\\src\\09\\mylog",ios::out|ios::app);
    if(logfile.is_open()){
        logfile << log.str() << endl;
    }
    else{
        cout << log.str() << endl; 
    }
}

#endif