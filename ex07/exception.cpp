// exception.cpp
#include <stdexcept>
#include <cstdio>
#include <iostream>

void  doSomeComputation(){   
    throw std::runtime_error("failure during doing some computation");
}
class LogFile{
    FILE* file;
    public:
    LogFile(const char* a, const char* b):file(std::fopen(a, b)){
        if(file == NULL){
            throw std::runtime_error("failure opening the file");
        }
    }
    ~LogFile(){
        fclose(file);
    }
    void fputs(const char* str){
        std::fputs(str, file);
    }
    private:
    LogFile(const LogFile&);
    LogFile& operator=(const LogFile&);
};
void example() {
    try{
        LogFile* logfile = new LogFile("logfile.txt", "w+");
        (*logfile).fputs("log - 1");
        doSomeComputation();
        (*logfile).fputs("log - 2");
        std::cout << "closing logfile" << std::endl;
        delete logfile;
    }catch(std::runtime_error e){
        std::cout << e.what() << std::endl;
    }
}

int main(void) {
    std::cout << "Calling example()" << std::endl;
    example();
    std::cout << "After calling example()" << std::endl;
    return 0;
}