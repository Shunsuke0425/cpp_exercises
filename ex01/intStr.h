#include <iostream>
using namespace std;
class intStr{
    public:
    char* intToStr(int);
    int strToInt(char*);
    protected:
    int number = 0; 
    int digit = 0;
    int count = 0;
    int flag = 0; 
    int char_number = 0;
    int temp;
};