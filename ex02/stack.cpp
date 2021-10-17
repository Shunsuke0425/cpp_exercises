#include <iostream>
#include <string>
#include "stack.h"
size_t max_size();

using namespace std;
bool Stack::empty(){
    if(_top == -1) return true;
    else return false;
}
bool Stack::full(){
    if(_top == _data->max_size()-1) return true;
    else return false;
}

int Stack::size(){
    if(_top == -1) return 0;
    else return _top;
}

void Stack::push(string str){
    if(full() == true)cout << "Now, stack is full" << endl;
    else _data[++_top] = str;
}

void Stack::pop(){
    bool status = empty();
    if(status == true)cout << "Now, stack is empty!!" << endl;
    else _top--;
}

string Stack::top(){
    return _data[_top];
}
