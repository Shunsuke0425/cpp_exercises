#include  "EFP.h"
double  EFP::evaluateFP(std::string operation){
    double value1, value2, result;
    value2 = operands_stack.top();
    operands_stack.pop();
    value1 = operands_stack.top();
    operands_stack.pop();
    if((*operation.c_str()) == '+'){
        result = value1 + value2;
        return result;
    }else if((*operation.c_str()) == '-'){
        result = value1 - value2;
        return result;
    }else if((*operation.c_str()) == '*'){
        result = value1 * value2;
        return result;
    }else if((*operation.c_str()) == '/'){
        result = value1 / value2;
        return result;
    }else;
    throw std::invalid_argument("failed!");
}