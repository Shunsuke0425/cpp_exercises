#include <iostream>
#include <vector>
namespace LP4{
    template<class Fwdlt>void sort(Fwdlt begin, Fwdlt end){
        double temp;
        for(Fwdlt it_j = begin; it_j < (end-1); it_j++){
            for(Fwdlt it_i = begin; it_i < (end-1); it_i++){
                if(*it_i > *(it_i + 1)){
                    temp = *it_i;
                    *it_i = *(it_i + 1);
                    *(it_i + 1) = temp;
                }
            }
        }
    }
}