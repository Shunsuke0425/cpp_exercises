#include "Circle.h"
#include "Shape2D.h"
#include "Rectangle.h"
#include <iostream>
#include <string>
#define pi 3.14
float Circle::compute_area() const{
    return radius * radius * pi;
}
Circle* Circle::create() const{
    return new Circle;
}
Circle* Circle::clone() const{
    return new Circle(*this);
}
Circle::Circle(){
    center.x = 0.0;
    center.y = 0.0;
    name = "Circle";
    radius = 0.0;
}
Circle::~Circle(){};
std::string Circle::get_name() const{
    return name;
}
Circle::Circle(Point2D point_center, float size_r){
    center.x = point_center.x;
    center.y = point_center.y;
    radius = size_r;
    name = "Circle";
}