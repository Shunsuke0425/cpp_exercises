#ifndef DATE_H
#define DATE_H

class Date {
public:
    Date() {}
    void set(const int m, const int d, const int y);
    void print() const;
    int get_month() const;
    int get_day() const;
    int get_year() const;
    void inc_day(); 
    void inc_month();
    void inc_year();
    int leap_year(int test_year) const; /*うるう年の計算を行う関数*/
    private:
    int month, day, year;
    int flag; /*うるう年だった場合、１になる*/
};

#endif
