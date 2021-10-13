#include <iostream>
#include "stack.h"
using namespace std;
bool Stack::empty(){
    if(_top == 0) return true;
    else return false;
}
bool Stack::full(){
    if(_top == sizeof(_data)) return true;
    else return false;
}

int Stack::size(){
    return _top;
}

void Stack::push(string str){
    if(full() == true)cout << "Now, stack is full" << endl;
    else _data[++_top] = str;
}

void Stack::pop(){
    bool status = empty();
    _top--;
}

string Stack::top(){
    return _data[_top];
}
