// COMPLETE 
// Include the proper headers headers
#include "find_k.h"

int main(void) {
    // COMPLETE 
    // Add code to test your implementation of the function find_k_closest()
    Point pointer_1(1.0, 6.0, 11.0);
    Point pointer_2(2.0, 7.0, 12.0);
    Point pointer_3(3.0, 8.0, 13.0);
    Point pointer_4(4.0, 9.0, 14.0);
    Point pointer_5(5.0, 10.0, 15.0);
    std::vector<Point> data;
    data.push_back(pointer_1);
    data.push_back(pointer_2);
    data.push_back(pointer_3);
    data.push_back(pointer_4);
    data.push_back(pointer_5);
    std::vector<double> result;
    std::cout << "Please input the point's number that you want output" << std::endl;
    std::cout << ">>>";
    int number;
    std::cin >> number;
    if(number > 5){
        std::cout << "out of range!" << std::endl;
        std::exit(1);
    }
    result = find_k_closest_2(number, data);
    /////////////////////////////////
    std::cout << number << " point's distance from origin" << std::endl;
    for(std::vector<double>::iterator it = result.begin(); it != result.end(); it++){
        std::cout << *it << std::endl;
    }
}