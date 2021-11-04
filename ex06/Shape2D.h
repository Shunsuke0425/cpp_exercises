#pragma once
#include <iostream>
class Shape2D{
    public:
    std::string get_name() const{
        return name;
    }
    virtual float compute_area() const = 0;
    virtual Shape2D* create() const = 0;
    virtual Shape2D* clone() const = 0;
    ~Shape2D();
    std::string name;
    float height, width, radius;
};