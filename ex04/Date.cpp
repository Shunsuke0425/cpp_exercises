#include <iostream>
#include "Date.h"
void Date::set(const int m, const int d, const int y){
    month = m;
    day = d;
    year = y;
    flag = leap_year(year);
}

void Date::print() const{
    std::cout << "year : " << year << " month : " << month << " day : " << day << std::endl;
}

int Date::get_month() const{
    return month;
}

int Date::get_year() const{
    return year;
}

int Date::get_day() const{
    return day;
}

void Date::inc_day(){
    if( (((month == 4) || (month == 6) || (month == 9) || (month == 11)) && (day == 30))
                || ((month == 2) && (day == 29))
                || ((flag == 1) && (month == 2) && (day == 28))
                || (month == 1) || (((month == 3) || (month == 5) || (month == 7) || (month == 8) || ( month == 10)) && (day == 31)) )
    {
        month++;
        day = 1;
    }else if((month == 12) && (day == 31)){
        month = 1;
        day = 1;
        inc_year();
    }else day++;
}

void Date::inc_month(){
    if(month == 1){
        month++;
        if((day == 31) && (flag == 1)){
            day = 28;
        }else if(day == 31){
            day = 29;
        }else;
    }else if(((month == 3) || (month == 5) || (month == 7) || (month == 8) || ( month == 10)) && (day == 31)){
        month++;
        day = 30;
    }else if(month == 12){
        month  = 1;
        if(day == 31)day = 30;
        inc_year();
    }else month++;
}

void Date::inc_year(){
    year++;
    flag = leap_year(year);
    if((flag == 1) && (month == 2) && (day == 29)){
        month++;
        day = 1;
    }
}

int Date::leap_year(int test_year) const{
    if(((test_year%4) == 0) && ((test_year%100) != 0) || ((test_year%400) == 0)){
        return 1;
    }
    else return 0;
}