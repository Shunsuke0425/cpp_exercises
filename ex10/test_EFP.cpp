#include "EFP.h"
#include <iostream>
int main(void){
    std::string input;
    std::cout << "Please input the fully parenthesized arithmetic expressions." << std::endl;
    std::cout << ">>>";
    getline(std::cin, input);//空白込みで計算式を受け取る
    std::cout << "result value is : " << evaluate(input) << std::endl;
}