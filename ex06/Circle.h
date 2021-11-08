#pragma once
#include "Shape2D.h"
#include "Point2D.h"
#include "Rectangle.h"
#include <iostream>
#include <string>
class Circle:public Shape2D,Point2D{
    public:
    Circle();
    float compute_area() const override;
    Shape2D* create() const override;
    Circle* clone() const override;
    ~Circle();
    std::string get_name() const override;
    void Set(float size_r, float size_c) override;
};