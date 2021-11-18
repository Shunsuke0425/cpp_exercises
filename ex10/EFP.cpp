#include  "EFP.h"
double  EFP::evaluateFP(std::string operation){
    double value1, value2, result;
    std::string str, check_operation;
    std::stringstream SS(operation);//stringstream型に変換する
    std::cout << "clear!" << std::endl;
    while(getline(SS, str, ' ')){
        if((*str.c_str()) == '('){/* ignore it */}
        else if((*str.c_str()) == '+')operations_stack.push(str);
        else if((*str.c_str()) == '-')operations_stack.push(str);
        else if((*str.c_str()) == '*')operations_stack.push(str);
        else if((*str.c_str()) == '/')operations_stack.push(str);
        else if((*str.c_str()) == ')'){
            check_operation = operations_stack.top();
            operations_stack.pop();
            value2 = operands_stack.top();
            operands_stack.pop();
            value1 = operands_stack.top();
            operands_stack.pop();
            if((*check_operation.c_str()) == '+'){
                result = value1 + value2;
            }else if((*check_operation.c_str()) == '-'){
                result = value1 - value2;
            }else if((*check_operation.c_str()) == '*'){
                result = value1 * value2;
            }else if((*check_operation.c_str()) == '/'){
                result = value1 / value2;
            }else;
            operands_stack.push(result);
        }
        else operands_stack.push(std::stod(str));
    }
    return operands_stack.top();
}
/*EFP::ope = {
    {"+",1},
    {"-",1},
    {"*",2},
    {"/",2}
};
double evaluate(std::string operation){
}*/