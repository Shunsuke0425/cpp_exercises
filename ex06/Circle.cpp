#include "Circle.h"
#include "Shape2D.h"
#include "Rectangle.h"
#include "Point2D.h"
#include <iostream>
#include <string>
#define pi 3.14
float Circle::compute_area() const{
    return radius * radius * pi;
}
Shape2D* Circle::create() const{
    return new Circle;
}
Circle* Circle::clone() const{
    return new Circle(*this);
}
void Circle::Set(float size_r, float size_c){
    radius = size_r;
    center = size_c;
} 
Circle::Circle(){
    name = "Circle";
    center = 0.0;
    radius = 0.0;
}
Circle::~Circle(){};
std::string Circle::get_name() const{
    return name;
}