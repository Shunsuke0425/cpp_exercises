#pragma once
#include <iostream>
class Shape2D{
    public:
    virtual std::string get_name() const = 0;
    virtual float compute_area() const = 0;
    virtual Shape2D* create() const = 0;
    virtual Shape2D* clone() const = 0;
    virtual void Set(float size_h, float size_w, float size_corner){};
    virtual void Set(float size_r, float size_c){};
    ~Shape2D(){};
    std::string name;
    float height, width, radius;
};