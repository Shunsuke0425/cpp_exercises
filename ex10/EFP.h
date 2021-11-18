#include <iostream>
#include <stack>
class EFP{
    public:
    double evaluateFP(std::string);
    std::stack<double> operands_stack;
    std::stack<std::string> operations_stack;
};