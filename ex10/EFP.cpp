#include  "EFP.h"
double  EFP::evaluateFP(std::string operation){
    double value1, value2, result;
    std::string str, check_operation;
    std::stringstream SS(operation);//stringstream型に変換する
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
double EFP::evaluate(std::string operation){
    double value1, value2, result, pre_result;
    std::stringstream S2(operation);
    std::string str, confirm, pre1, pre2, pre_ope;
    int check_pre, left_pre = 0;
    std::map<std::string, int> ope;
    ope["+"] = 1;
    ope["-"] = 1;
    ope["*"] = 2;
    ope["/"] = 2;
    ope["("] = 3;
    while(getline(S2, str, ' ')){
        if(ope.find(str) != ope.end()){
            check_pre  = ope[str];
            //Now, this if code is that when operations_stack still have 1 operation.
            if((left_pre < check_pre) && (operations_stack.size() == 0)){
                operations_stack.push(str);
                left_pre = check_pre;
            }
            //Now, maybe this code is called, when operations_stack have over 2 operations.
            else if(check_pre <= left_pre){
                value2 = operands_stack.top();
                operands_stack.pop();
                value1 = operands_stack.top();
                operands_stack.pop();
                pre_ope = operations_stack.top();
                operations_stack.pop();
                if((*pre_ope.c_str()) == '+'){
                    result = value1 + value2;
                }else if((*pre_ope.c_str()) == '-'){
                    result = value1 - value2;
                }else if((*pre_ope.c_str()) == '*'){
                    result = value1 * value2;
                }else if((*pre_ope.c_str()) == '/'){
                    result = value1 / value2;
                }else;
                operands_stack.push(result);
                left_pre  = check_pre;
                operations_stack.push(str);
            }else if(check_pre > left_pre){
                //this code is that I want to confirm that next operation is (.
                getline(S2, confirm, ' ');
                if(ope.find(confirm) == ope.end()){
                    value2 = std::stod(confirm);
                    value1 = operands_stack.top();
                    operands_stack.pop();
                    if((*str.c_str()) == '+')pre_result = value1 + value2;
                    else if((*str.c_str()) == '-')pre_result = value1 - value2;
                    else if((*str.c_str()) == '*')pre_result = value1 * value2;
                    else if((*str.c_str()) == '/')pre_result = value1 / value2;
                    else;
                    operands_stack.push(pre_result);
                }
                //This code is finding the '(' operation then.
                else if(ope[confirm] == 3){
                    getline(S2, pre1, ' ');
                    getline(S2, pre_ope, ' ');
                    getline(S2, pre2, ' ');
                    value1 = std::stod(pre1);
                    value2 = std::stod(pre2);
                    if((*pre_ope.c_str()) == '+')pre_result = value1 + value2;
                    else if((*pre_ope.c_str()) == '-')pre_result = value1 - value2;
                    else if((*pre_ope.c_str()) == '*')pre_result = value1 * value2;
                    else if((*pre_ope.c_str()) == '/')pre_result = value1 / value2;
                    else;
                    std::cout << pre_result << std::endl;
                    operands_stack.push(pre_result);
                    operations_stack.push(str);
                    //To delete the ')' operation. ignore this.
                    std::string trash;
                    getline(S2, trash, ' ');
                }
                else;
            }
        }else operands_stack.push(std::stod(str));
    }
    while(operations_stack.size() != 0){
        str = operations_stack.top();
        operations_stack.pop();
        value2 = operands_stack.top();
        operands_stack.pop();
        value1 = operands_stack.top();
        operands_stack.pop();
        if((*str.c_str()) == '+')result = value1 + value2;
        else if((*str.c_str()) == '-')result = value1 - value2;
        else if((*str.c_str()) == '*')result = value1 * value2;
        else if((*str.c_str()) == '/')result = value1 / value2;
        else;
        operands_stack.push(result);
    }
    return operands_stack.top();
}