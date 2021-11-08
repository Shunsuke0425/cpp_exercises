#include <iostream>
#include "Point2D.h"
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
void Rectangle::Set(const float size_h, const float size_w, const float size_corner){
    height = size_h;
    width = size_w;
    left_corner = size_corner;
}
Rectangle::~Rectangle(){};
Rectangle::Rectangle(){
    name = "Rectangle";
    height = 0.0;
    width = 0.0;
    left_corner = 0.0;
}
std::string Rectangle::get_name() const{
    return name;
}