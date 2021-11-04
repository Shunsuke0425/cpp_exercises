#pragma once
#include "Shape2D.h"
#include "Point2D.h"
#include <iostream>
class Circle:public Shape2D,Point2D{
    public:
    Circle(){
        name = "Circle";
        center = 0.0;
        radius = 0.0;
    }
    float compute_area() const;
    Shape2D* create() const;
    Shape2D* clone() const;
    ~Circle();
};