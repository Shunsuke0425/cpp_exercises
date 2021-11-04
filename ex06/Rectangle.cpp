#include <iostream>
#include "Rectangle.h"
#include "Shape2D.h"
float Rectangle::compute_area() const{
    return height * width;
}
Shape2D* Rectangle::create() const{
    Shape2D *new_Shape;
    return new_Shape;
}
Shape2D* Rectangle::clone() const{
    Shape2D *pre;
    (*pre).height = (*this).height;
    (*pre).width = (*this).width;
    return pre;
}
Rectangle::~Rectangle(){
    delete[] this;
}