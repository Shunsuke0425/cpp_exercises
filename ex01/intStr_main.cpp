#include <iostream>
#include <stdlib.h>
#include "intStr.h"
int main(void){
    intStr test;
    int temp_int = 1;
    int j, check, sample_int, Sum = 0;
    int result_int;
    char *result_str;
    std::string pre_string;
    std::cout << "文字列を入力する場合は0,\n";
    std::cout << "数字の列を入力する場合は1を入力してください。" << endl;
    cin >> check;
    if(check==0){
        std::cout <<  ">>>";
        cin >> pre_string;
        char *Char = &pre_string[0];
        result_int = test.strToInt(Char);
    }
    else {
        std::cout <<  ">>>";
        cin >> sample_int;
        result_str = test.intToStr(sample_int);
    }
    std::cout << "output is ";
    if(check==0)std::cout << result_int << std::endl;
    else std::cout << result_str << std::endl;
}
