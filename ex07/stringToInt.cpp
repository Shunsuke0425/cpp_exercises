// stringToInt.cpp
#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>

using namespace std;

int stringToInt(const string& input) {
    stringstream instream;
    instream << input;
    int number;
    instream >> number;

    if (instream.fail()) {
    // Error: the input can not be converted
    //cerr << "input can not be converted to an int" << endl;
    throw invalid_argument("input can not be converted to an int");
    }

    char left;
    instream >> left;
    if (!instream.fail()) {
    // Error: there are some characters left after the int
    //cerr << "input can not be converted to an int" << endl;
    throw invalid_argument("input can not be converted to an int");
    /*Comment:自分の理解
    元々、-1が出力だったものをinvalid_argument("~")の型にしてthrowしておく。処理をそのまま送っている状態。
    returnは、戻り値を返す。throwは例外処理をそのまま返す。("~")の〜の部分ではcatchで捕まった時ようにe.what()で出力される文章を書いておく。
    */
    }

  // everything went fine: returns the int
    return number;
    }

int main(void) {
    try{
        string test1 = "11";
        cout << stringToInt(test1) << endl;
    }catch(invalid_argument e){
        cout << e.what() << endl;
    }

    try{
        string test2 = "cc11";
        cout << stringToInt(test2) << endl;
    }catch(invalid_argument e){
        cout << e.what() << endl;
    }
    try{
        string test3 = "11cc";
        cout << stringToInt(test3) << endl;
    }catch(invalid_argument e){
        cout << e.what() << endl;
    }
    return 0;
}