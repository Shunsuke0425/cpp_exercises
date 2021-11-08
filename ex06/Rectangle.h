#pragma once
#include <iostream>
#include "Shape2D.h"
#include "Point2D.h"
class Rectangle:public Shape2D,Point2D{
    public:
    //Constructor
    Rectangle();
    std::string get_name() const override;
    float compute_area() const override;
    Shape2D* create() const override;
    Shape2D* clone() const override;
    void Set(const float size_h, const float size_w, const float size_corner) override;
    ~Rectangle();
};