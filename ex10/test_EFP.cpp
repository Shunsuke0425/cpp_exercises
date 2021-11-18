#include "EFP.h"
#include <iostream>
#include <sstream>
int main(void){
    EFP formula;
    std::string input, str, check_operation;
    std::cout << "Please input the fully parenthesized arithmetic expressions." << std::endl;
    std::cout << ">>>";
    getline(std::cin, input);
    std::stringstream SS(input);
    while(getline(SS, str, ' ')){
        if((*str.c_str()) == '('){/* ignore it */}
        else if((*str.c_str()) == '+')formula.operations_stack.push(str);
        else if((*str.c_str()) == '-')formula.operations_stack.push(str);
        else if((*str.c_str()) == '*')formula.operations_stack.push(str);
        else if((*str.c_str()) == '/')formula.operations_stack.push(str);
        else if((*str.c_str()) == ')'){
            check_operation = formula.operations_stack.top();
            formula.operations_stack.pop();
            try{
                formula.operands_stack.push(formula.evaluateFP(check_operation));
            }catch(std::invalid_argument e){
                std::cout << e.what() << std::endl;
            }
        }
        else formula.operands_stack.push(std::stod(str));
    }
    std::cout << "result value is : " << formula.operands_stack.top() << std::endl;
}