#pragma once
#include "Shape2D.h"
#include "Rectangle.h"
#include <iostream>
#include <string>
class Circle:public Shape2D,Point2D{
    public:
    Circle();
    Circle(Point2D point_center, float size_r);
    float compute_area() const override;
    Shape2D* create() const override;
    Circle* clone() const override;
    ~Circle() override;
    std::string get_name() const override;
};