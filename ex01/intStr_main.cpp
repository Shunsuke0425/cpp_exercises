#include <iostream>
#include <stdlib.h>
#include "intStr.h"
int main(void){
    cout << "文字列を入力する場合は0,\n";
    cout << "数字の列を入力する場合は1を入力してください。" << endl;
    cin >> check;
    while(cin.get(Char[i])){
        i++;
        if(i==30 || Char[i-1] == '\n')break;
    }
    p = Char;
    if(check==0){
        Char[i]= '\0';
        strToInt(p);
    }
    else {
        for(j=0;j<i;j++){
            a = Char[i];
            Sum += temp_int*a;
            temp_int *= 10;
        }
        result_str = *(intToStr(Sum));
    }
    if(check==0)for(j = 0; j < i; j++)cout << Char[j];
    else cout << result_str << endl;
}
