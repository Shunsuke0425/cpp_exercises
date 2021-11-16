#include <iostream>
#include <stdlib.h>
#include <string>
#include "intStr.h"
int main(void){
    int temp_int = 1;
    int j = 0, check = 0, sample_int = 0, Sum = 0;
    int result_int;
    char *result_str;
    std::cout << "文字列を入力する場合は0,\n";
    std::cout << "数字の列を入力する場合は1を入力してください。" << std::endl;
    std::cin >> check;
    if(check==0){
        std::cout <<  ">>>";
        std::string C;
        std::cin >> C;
        int a = C.size();
        C[a+1] = '\0';
        const char* real_char = C.c_str();
        result_int = strToInt(real_char);
    }
    else {
        std::cout <<  ">>>";
        std::cin >> sample_int;
        result_str = intToStr(sample_int);
    }
    std::cout << "output is ";
    if(check==0)std::cout << result_int << std::endl;
    else std::cout << result_str << std::endl;
    delete[] result_str;
}
