#include "Polygon.h"
#include "Shape2D.h"
#include <iostream>
#include <string>
std::string Polygon::get_name() const{
    return name;
}
float Polygon::compute_area() const{
    float answer = 0;
    Point2D test[n];
    for(int i = 0; i < n; i++){
        answer += (test[i].x * test[i+1].y) -  (test[i].y * test[i+1].x);
    }
    return answer;
}
Polygon::Polygon(){};
Polygon::Polygon(int N, Point2D point[]){
    Point2D test[N];
    n = N;
    for(int i = 0; i < N; i++ ){
        test[i].x = point[i].x;
        test[i].y = point[i].y;
    }
}
Polygon::~Polygon(){}