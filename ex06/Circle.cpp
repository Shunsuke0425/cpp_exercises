#include "Circle.h"
#include <iostream>
#define pi 3.14
float Shape2D::compute_area() const{
    return radius * radius * pi;
}
Circle::~Circle(){
    delete[] this;
}