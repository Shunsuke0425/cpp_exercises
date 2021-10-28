// test_ArrayStack.cpp
#include "ArrayStack.h"

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
    std::cout << stack1.top() << std::endl;
    test++;
}
//output the each stacks
top_size = stack1.size();
for(int i = 0; i < top_size; i++){
        std::cout << "top_size " << stack1.size() << " : " << stack1.top() << std::endl;
        stack1.pop();
}

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
top_size = stack2.size();
for(int i = 0; i < top_size; i++){
        std::cout << "top_size " << stack2.size() << " : " << stack2.top() << std::endl;
        stack2.pop();
}
return 0;
}