#include "inc.h"
void inc(double& point){
    point++;
}
void inc(double* point){
    (*point)++;
}