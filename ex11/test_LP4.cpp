#include <iostream>
#include <sstream>
#include "LP4.h"
int main(void){
    int size, count = 0;
    std::string input,str;
    double data[100];
    //iterator変数の宣言と代入
    //std::vector<double>::iterator it = arr.begin();
    std::cout << "Please input numbers with blank!" << std::endl;
    std::cout << ">>>";
    getline(std::cin, input);
    std::stringstream SS(input);
    while(getline(SS, str, ' ')){
        data[count] = std::stod(str);
        count++;
        if(count > 100){
            std::cout << "size over error" << std::endl;
            std::exit(1);
        }
    }
    /*********************************/
    //input vector arr
    std::vector<double> arr(count);
    for(int i = 0; i < count; i++)arr[i] = data[i];
    /*********************************/
    //Check the before arr concept
    std::cout << "before array concept:" << std::endl
    << "{ ";
    for(std::vector<double>::iterator it = arr.begin(); it != arr.end(); it++){
        std::cout << *it << ", ";
    }
    std::cout << "}" << std::endl;
    //This code used the sort function
    LP4::sort(arr.begin(), arr.end());
    /*********************************/
    //Check the after arr concept
    std::cout << "after array concept:" << std::endl
    << "{ ";
    for(std::vector<double>::iterator it = arr.begin(); it != arr.end(); it++){
        std::cout << *it << ", ";
    }
    std::cout << "}" << std::endl;
};