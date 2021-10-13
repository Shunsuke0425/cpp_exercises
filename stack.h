#ifndef STACK_H
#define STACK_H

// Insert the relevant headers here 
#include <string>
#include <iostream>
class Stack {
public:
Stack(int max_size=100) : _max_size(max_size), 
_top(-1), _data(new std::string[max_size]) {}

~Stack() { delete[] _data; }

 // interface

 // check whether the stack is empty
bool empty();

 // check whether the stack is full
bool full();

 // return the number of elements
int size();

 // insert element on top
 // print an error message on std::cerr when overflow
void push(std::string);

 // remove element on top
 // print an error message on std::cerr when underflow
void pop();

 // acces the topmost element
std::string top();

private:
  int _max_size; // capacity of the fixed-size stack 
  int _top; // index to the top of the stack 
  std::string* _data; // data container 

};
#endif