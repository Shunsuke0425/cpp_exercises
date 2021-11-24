#include <iostream>
#include <vector>
namespace LP4{
    template<class Fwdlt>void sort(Fwdlt begin, Fwdlt end){
        double temp;
        int count = 0;
        for(Fwdlt it_j = (end-1); it_j > begin; it_j--){
            for(Fwdlt it_i = begin; it_i < (end-1); it_i++){
                if(*begin > *(begin + 1)){
                    temp = *begin;
                    *begin = *(begin + 1);
                    *(begin + 1) = temp;
                }
                *begin++;
                count++;
            }
            for(int k = 0; k < count; k++)*begin--;
            count = 0;
        }
    }
}