// test_ArrayStack.cpp
#include "ArrayStack.h"
#include <utility>

int main(void) {
double test = 1.0;
int top_size;
// Create an instance of ArrayStack named stack1 
//   using the default constructor
// Push 1.0, 2.0, 3.0, 4.0, 5.0 in this stack
ArrayStack stack1;
stack1.empty();
for(int i = 0; i < 5; i++){
    stack1.push(test);
    test++;
}
//output the each stacks
/*top_size = stack1.size();
for(int i = 0; i < top_size; i++){
        std::cout << "top_size " << stack1.size() << " : " << stack1.top() << std::endl;
        stack1.pop();
}*/

test = 1.0; //initialize the test value

// Create another instance of ArrayStack named stack2
//   using the other constructor, specify an original size of 5
// Push 1.0, 2.0, ..., 10.0 in this stack
ArrayStack stack2(5);
stack2.empty();
for(int i = 0; i < 10; i++){
    stack2.push(test);
    test++;
}
//output the each stacks
/*top_size = stack2.size();
for(int i = 0; i < top_size; i++){
        std::cout << "top_size " << stack2.size() << " : " << stack2.top() << std::endl;
        stack2.pop();
}*/

std::cout << "queation2 of exercise 5" << std::endl;
// Copy
ArrayStack stack3(stack1);
ArrayStack stack4 = stack2;

// Assignment
ArrayStack stack5;
stack5 = stack1;
ArrayStack stack6(10);
stack6 = stack6;

// COMPLETE 
// Show the content of the stacks 'stack1', 'stack3' and 'stack4' by calls to pop() and top() 
// (use a loop and the method ArrayStack::empty() for the termination condition)
//output the stack1
/*std::cout << "output the stack1" << std::endl;
while(stack1.empty() != true){
    std::cout << "top_size " << stack1.size() << " : " << stack1.top() << std::endl;
    stack1.pop();
}
//output the stack3
std::cout << "output the stack3" << std::endl;
while(stack3.empty() != true){
    std::cout << "top_size " << stack3.size() << " : " << stack3.top() << std::endl;
    stack3.pop();
}
//output the stack4
std::cout << "output the stack4" << std::endl;
while(stack4.empty() != true){
    std::cout << "top_size " << stack4.size() << " : " << stack4.top() << std::endl;
    stack4.pop();
}*/

std::cout << "question 3 of exercise 5" << std::endl;
 // Move
ArrayStack stack7 = std::move(stack5);

stack6 = std::move(stack2);

// COMPLETE 
// Show the content of the stacks 'stack5', 'stack7', 'stack6' and 'stack2'
// (use the same method as in question 2)
//output the stack5
std::cout << "output the stack5" << std::endl;
while(stack5.empty() != true){
    std::cout << "top_size " << stack5.size() << " : " << stack5.top() << std::endl;
    stack5.pop();
}
//output the stack7
std::cout << "output the stack7" << std::endl;
while(stack7.empty() != true){
    std::cout << "top_size " << stack7.size() << " : " << stack7.top() << std::endl;
    stack7.pop();
}
//output the stack6
std::cout << "output the stack6" << std::endl;
while(stack6.empty() != true){
    std::cout << "top_size " << stack6.size() << " : " << stack6.top() << std::endl;
    stack6.pop();
}
//output the stack2
std::cout << "output the stack2" << std::endl;
while(stack2.empty() != true){
    std::cout << "top_size " << stack2.size() << " : " << stack2.top() << std::endl;
    stack2.pop();
}

return 0;
}