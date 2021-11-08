// exception.cpp
#include <stdexcept>
#include <cstdio>
#include <iostream>

using namespace std;

class LogFile{
    FILE* f;
    public:
    void doSomeComputation() {   
        throw runtime_error("failure during doing some computation");
    }
    LogFile(const char* a, const char* b){
        f = fopen(a,b);
        if(f==NULL){
            doSomeComputation();
        }
    }
    ~LogFile(){
        fclose(f);
    }
    int fputs(const char* str, FILE* f);
};

void example() {
    FILE* logfile = fopen("logfile.txt", "w+");
    if (!logfile) {
    throw runtime_error("failed to open file");
    }

    fputs("log - 1", logfile);

 // Call a function that performs some computation and may throw 
 // an exception
//doSomeComputation();
LogFile f("logfile.txt","w+");

    fputs("log - 2", logfile);
        
    cout << "closing logfile" << endl;
    fclose(logfile);
}

int main(void) {
    cout << "Calling example()" << endl;
    example();
    cout << "After calling example()" << endl;
    return 0;
}