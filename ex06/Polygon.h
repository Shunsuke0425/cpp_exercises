#include <iostream>
#include <string>
#include "Shape2D.h"
class Polygon:public Shape2D, Point2D{
    public:
    std::string get_name() const override;
    float compute_area() const override;
    Polygon();
    Polygon(int N, Point2D point[]);
    ~Polygon() override;
};