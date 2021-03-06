#include <iostream>
#include "Rectangle.h"
#include "Circle.h"
#include "Shape2D.h"
float Rectangle::compute_area() const{
    return height * width;
}
Rectangle* Rectangle::create() const{
    return new Rectangle;
}
Rectangle* Rectangle::clone() const{
    return new Rectangle(*this);
}
Rectangle::~Rectangle(){};
Rectangle::Rectangle(){
    name = "Rectangle";
    height = 0.0;
    width = 0.0;
    left_corner.x = 0.0;
    left_corner.y = 0.0;
}
std::string Rectangle::get_name() const{
    return name;
}
Rectangle::Rectangle(Point2D size_corner, float size_h, float size_w){
    left_corner.x = size_corner.x;
    left_corner.y = size_corner.y;
    height = size_h;
    width = size_w;
    name = "Rectangle";
}