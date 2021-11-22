#include "EFP.h"
#include <iostream>
int main(void){
    EFP formula;
    double result;
    std::string input;
    std::cout << "Please input the fully parenthesized arithmetic expressions." << std::endl;
    std::cout << ">>>";
    getline(std::cin, input);//空白込みで計算式を受け取る
    result = formula.evaluate(input);
    std::cout << "result value is : " << result << std::endl;
}