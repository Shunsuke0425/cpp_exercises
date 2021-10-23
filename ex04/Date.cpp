#include <iostream>
#include "Date.h"
void Date::set(int m, int d, int y){
    month = m;
    day = d;
    year = y;
}

void Date::print() const{
    std::cout << "month is : " << month << std::endl;
}

int Date::get_month() const{
    return 0;
}

int Date::get_year() const{
    return 0;
}

int Date::get_day() const{
    return 0;
}

void Date::inc_day() {}

void Date::inc_month() {}

void Date::inc_year() {}