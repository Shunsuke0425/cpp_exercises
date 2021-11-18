#include "EFP.h"
#include <iostream>
int main(void){
    EFP formula;
    std::string input;
    std::cout << "Please input the fully parenthesized arithmetic expressions." << std::endl;
    std::cout << ">>>";
    getline(std::cin, input);//空白込みで計算式を受け取る
    formula.evaluateFP(input);
    std::cout << "result value is : " << formula.operands_stack.top() << std::endl;
}