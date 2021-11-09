#pragma once
#include <iostream>
#include "Shape2D.h"
class Rectangle:public Shape2D{
    public:
    //Constructor
    Rectangle();
    Rectangle(Point2D size_corner, float size_h, float size_w);
    std::string get_name() const override;
    float compute_area() const override;
    Rectangle* create() const override;
    Rectangle* clone() const override;
    ~Rectangle() override;
};