// palindrome.cpp

// COMPLETE include necessary headers
#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include <sstream>
// define functions if necessary 
bool alpha(char c){
    if(0 == std::isalpha(c)){
        return true;
    }else return false;
}
bool isPalindrome(std::string sentence){
    //erase the space like ' ' from sentence
    sentence.erase(std::remove_if(sentence.begin(), sentence.end(), alpha), sentence.end());
    //This code change to small char from big char
    transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower);
    //Check the whether sentence equal palindrome
    if(equal(sentence.begin(), sentence.begin() + sentence.size()/2, sentence.rbegin())){
        return true;
    }else return false;
}

int main(void) {
    // COMPLETE 
    // Add tests for testing your implementation of isPalindrome()
    //std::string str = "Don't nod";
    std::string str;
    std::cout << "Please input the sentence you want to try" << std::endl;
    std::cout << ">>>";
    getline(std::cin, str);
    if(isPalindrome(str)){
        std::cout << str << " is palindrome" << std::endl;
    }else std::cout << str << " is not palindrome" << std::endl;
}