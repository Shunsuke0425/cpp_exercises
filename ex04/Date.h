#ifndef DATE_H
#define DATE_H

class Date {
public:
    Date() {}
    void set(int m, int d, int y);
    void print() const;
    int get_month() const;
    int get_day() const;
    int get_year() const;
    void inc_day(); 
    void inc_month();
    void inc_year();
    private:
    int month, day, year;
};

#endif
