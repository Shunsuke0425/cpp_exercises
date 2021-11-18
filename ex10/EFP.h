#include <iostream>
#include <stack>
#include <map>
#include <sstream>
class EFP{
    public:
    double evaluateFP(std::string);
    //double evaluate(std::string);
    std::stack<double> operands_stack;
    std::stack<std::string> operations_stack;
    //std::map<std::string, int> ope;
};