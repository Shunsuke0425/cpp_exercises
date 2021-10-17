#include <iostream>
#include "intStr.h"
int strToInt(const char *string){
    while(*string != '\0'){
        number += *string - '0';
        number *= 10;
        string++; 
    }
    number /= 10;
    return number;
}
char* intToStr(int number){
    int count = 0;
    if(number == 0){
        count++;
    }else{
        while(number != 0){
            count++;
            number = number / 10;
        }
    }
    char *string = (char*)malloc(count * 4);
    for(int i=0; i<count; i++){
        digit = number % 10;
        string[(count-1)-i] = '0' + digit;
        number /=10;
    }
    return string;
}
/*Now, I'm going to modify this code.*/ 