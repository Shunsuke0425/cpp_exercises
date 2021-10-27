#include <fstream>
#include <iostream>
#include <string>
#include "stack.h"
using namespace std;
int main(int argc, char *argv[]){
    ifstream readfile("Data.txt");
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
        if(max_length < str.length())max_length = str.length();
    }
    for(int i = 0; i < max_length; i++){
        cout << "-";
    }
    cout << "-" << endl;
    for(int i = 0; i < max_number; i++){
        cout << stack.top() << endl;
        stack.pop();
    }
    for(int i = 0; i < max_length; i++){
        cout << "-";
    }
    cout << "-" << endl;
}