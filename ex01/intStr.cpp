#include <iostream>
#include "intStr.h"
int intStr::strToInt(char *string){
    int number = 1;
    int check = 0;
    int i = 0;
    while(string[i] != '\0'){
        //std::cout << "number : " << number << std::endl;
        if(string[i] == '-'){
            check = 1;
        }else{
            number += (string[i] - 48);
            if(i == 0 || ((i == 1) && (check == 1)))number -= 1;
            number *= 10;
        }
        std::cout << number << std::endl;
        i++;
    }
    number /= 10;
    if(check == 1)number *= -1;
    return number;
}
char* intStr::intToStr(int n){
    int temp = n;
    int digit = 0;
    int count = 0;
    int flag = 0;
    //受け取った文字列が何桁分あるかをcountに算出する
    while(flag == 0){
        if(0 == n){
            flag = 1;
        }else{
            count++;
            n /= 10;
        }
    }
    char *string = (char*)malloc(count * 4);
    for(int i=0; i<count; i++){
        digit = temp % 10;
        string[(count-1)-i] = '0' + digit;
        temp /=10;
    }
    return string;
}
/*Now, I'm going to modify this code.*/ 