#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include "stack.h"
using namespace std;
int main(int argc, char* argv[]){
    ifstream readfile(argv[1]);
    if(!readfile){
        cerr << "Cannot read!" << endl;
        exit(1);
    }
    Stack stack;
    string str;
    readfile >> str;
    int max_number = stoi(str);
    int max_length = 0;
    for(int i = 0; i < max_number; i++){
        readfile >> str;
        stack.push(str);
        if(max_length < str.size())max_length = str.size();
    }
    std::cout << std::setfill('-') << std::setw(max_length) << "-" << std::endl;
    for(int i = 0; i < max_number; i++){
        cout << stack.top() << endl;
        stack.pop();
    }
    std::cout << std::setfill('-') << std::setw(max_length) << "-" << std::endl;
}