#include "Polygon.h"
#include <iostream>
#include <string>
std::string Polygon::get_name() const{
    return name;
}
float Polygon::compute_area() const{
    float answer = 0;
    for(int i = 0; i < n-1; i++){
        answer += (test[i+1].x * test[i].y) -  (test[i+1].y * test[i].x);
    }
    return answer / 2;
}
Polygon* Polygon::create() const{
    return new Polygon;
}
Polygon* Polygon::clone() const{
    return new Polygon(*this);
}
Polygon::Polygon(){
    name = "Polygon";
}
Polygon::Polygon(int N, Point2D *point){
    std::cout << std::endl;
    for(int i = 0; i < N; i++){
        test[i].x = point[i].x;
        test[i].y = point[i].y;
    }
    n = N;
}
Polygon::~Polygon(){}