#include <iostream>
#include <stack>
#include <map>
#include <sstream>
double calc(double operand1, double operand2, std::string operation){
    double result = 0;
    if((*operation.c_str()) == '+')result = operand1 + operand2;
    else if((*operation.c_str()) == '-')result = operand1 - operand2;
    else if((*operation.c_str()) == '*')result = operand1 * operand2;
    else if((*operation.c_str()) == '/')result = operand1 / operand2;
    else;
    return result;
}
double  evaluateFP(std::string operation){
    std::stack<double> operands_stack;//input the number
    std::stack<std::string> operations_stack;//input the operations
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
double evaluate(std::string operation){
    std::stack<double> operands_stack;//input the number
    std::stack<std::string> operations_stack;//input the operations
    double value1, value2, result, pre_result;
    std::stringstream S2(operation);
    std::string str, confirm, pre1, pre2, pre_ope;
    int check_pre, left_pre = 0;
    std::map<std::string, int> ope;
    ope["+"] = 1;
    ope["-"] = 1;
    ope["*"] = 2;
    ope["/"] = 2;
    ope["("] = 0;
    ope[")"] = 0;
    while(getline(S2, str, ' ')){
        if(ope.find(str) != ope.end()){
            check_pre  = ope[str];
            //Now, this if code is that when operations_stack still have 1 operation.
            if((check_pre == 0 )&& (str == "(")){
                operations_stack.push(str);
                //count equal number is "("
                int count = 1, 
                //count_f equal number is ")"
                count_f = 0;
                while(count != count_f){
                    getline(S2, str, ' ');
                    if(ope.find(str) != ope.end()){
                        if(str == "("){
                            operations_stack.push(str);
                            count++;
                        }else if((str == ")") && (operations_stack.top() == "(")){
                            operations_stack.pop();
                            count_f++;
                        }else if(str == ")"){
                            count_f++;
                            value2 = operands_stack.top();
                            operands_stack.pop();
                            value1 = operands_stack.top();
                            operands_stack.pop();
                            pre_ope = operations_stack.top();
                            operations_stack.pop();
                            operands_stack.push(calc(value1, value2, pre_ope));
                            operations_stack.pop();
                        }else operations_stack.push(str);
                    }else operands_stack.push(std::stod(str));
                }
            }else if((left_pre < check_pre) && (operations_stack.size() == 0)){
                operations_stack.push(str);
                left_pre = check_pre;
            }
            /*//Now, I try the code about like "( -4 )"
            else if((check_pre == 0) && (str == ")")){
                operations_stack.pop();
            }*/
            //Now, maybe this code is called, when operations_stack have over 2 operations.
            else if(check_pre <= left_pre){
                value2 = operands_stack.top();
                operands_stack.pop();
                value1 = operands_stack.top();
                operands_stack.pop();
                pre_ope = operations_stack.top();
                operations_stack.pop();
                operands_stack.push(calc(value1, value2, pre_ope));
                left_pre  = check_pre;
                operations_stack.push(str);
            }else if(check_pre > left_pre){
                //this code is that I want to confirm that next operation is (.
                getline(S2, confirm, ' ');
                if(ope.find(confirm) == ope.end()){
                    result = calc(operands_stack.top(), std::stod(confirm), str);
                    operands_stack.pop();
                    operands_stack.push(result);
                }
                //This code is finding the '(' operation then.
                else if((ope[confirm] == 0) && (confirm == "(")){
                    getline(S2, pre1, ' ');
                    getline(S2, pre_ope, ' ');
                    getline(S2, pre2, ' ');
                    operands_stack.push(calc(std::stod(pre1), std::stod(pre2), pre_ope));
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
        if(str == "("){}
        else{
            value2 = operands_stack.top();
            operands_stack.pop();
            value1 = operands_stack.top();
            operands_stack.pop();
            operands_stack.push(calc(value1, value2, str));
        }
    }
    return operands_stack.top();
}