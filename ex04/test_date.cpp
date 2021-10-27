#include "Date.h"
#include <iostream>

int main(void) {
    Date d;
    d.set(2, 28, 2009);
    d.print(); /*初期設定の表示*/

    d.inc_day();
    d.print();
    d.inc_month(); 
    d.print(); 

    d.inc_year();
    d.print();
}
