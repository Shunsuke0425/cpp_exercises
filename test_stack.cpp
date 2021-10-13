// test_stack.cpp
// Insert the relevant headers here
#include "stack.h"
#include <iostream>
#include <string>
using namespace std;

int main(void){
    Stack stack;
    if(stack.empty() == true) cout << "Now, stack is empty" << endl;

    int top_size = 0;
    string name;
    cout << "入力する文字列の個数を入力してください。" << endl;
    cin >> top_size;
    cout << "文字列を入力してください。" << endl;
    for(int i = 0; i< top_size; i++){
        cout << "top_size " << i << " : ";
        cin >> name;
        stack.push(name);
    }
    cout << "スタックの出力を行います。" << endl;
    for(int i = 0; i < top_size; i++){
        cout << "top_size " << stack.size() << " : " << stack.top() << endl;
        stack.pop();
    }
}