#include <iostream>
#include <stack>
#include <map>
#include <sstream>
class EFP
{
public:
    double evaluateFP(std::string);
    double evaluate(std::string);
    std::stack<double> operands_stack;//input the number
    std::stack<std::string> operations_stack;//input the operations
};