#pragma once
#include <iostream>
#include "Shape2D.h"
#include "Point2D.h"
class Rectangle:public Shape2D,Point2D{
    public:
    //Constructor
    Rectangle(){
        name = "Rectangle";
        height = 0.0;
        width = 0.0;
        left_corner = 0.0;
    }
    float compute_area() const;
    Shape2D* create() const;
    Shape2D* clone() const;
    ~Rectangle();
};