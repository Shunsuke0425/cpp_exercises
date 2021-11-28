#pragma once
#include <iostream>
class Shape2D{
    public:
    virtual std::string get_name() const = 0;
    virtual float compute_area() const = 0;
    virtual Shape2D* create() const = 0;
    virtual Shape2D* clone() const = 0;
    virtual ~Shape2D(){};
    std::string name;
    float height, width, radius;
    int n;
};
struct Point2D{
    float x;
    float y;
    ~Point2D(){};
};