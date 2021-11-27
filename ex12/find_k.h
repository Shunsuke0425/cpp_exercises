#include <iostream>
#include <queue>
#include <cmath>
#include <list>
#include <vector>
struct Point{
    Point() : x(0.0), y(0.0), z(0.0) {}
    Point(double x, double y, double z) : x(x), y(y), z(z) {}
    double x, y, z;
};
struct Compare{
    bool operator()(Point a, Point b){
        double value1 = std::sqrt(std::pow(a.x, 2.0) + std::pow(a.y, 2.0) + std::pow(a.z, 2.0));
        double value2 = std::sqrt(std::pow(b.x, 2.0) + std::pow(b.y, 2.0) + std::pow(b.z, 2.0));
        if(value1 < value2)return true;
        else return false;
    }
};
double distance(Point data){
    double result = sqrt(std::pow(data.x, 2.0) + std::pow(data.y, 2.0) + std::pow(data.z, 2.0));
    return result;
}
std::vector<Point> find_k_closest(int K, std::vector<Point> list){
    std::priority_queue<Point, std::vector<Point>, Compare> queue_list;
    std::vector<Point> result;
    for(std::vector<Point>::iterator it = list.begin(); it < list.end(); it++)queue_list.push(*it);
    for(int i = 0; i < K; i++){
        result.push_back(queue_list.top());
        queue_list.pop();
    }
    return result;
}
std::vector<double> find_k_closest_2(int K, std::vector<Point> list){
    std::function<bool(double,double)> func = [](double a,double b){return a>b;};
    std::priority_queue<double, std::vector<double>, decltype(func)> queue_list_2(func);
    std::vector<double> result;
    for(std::vector<Point>::iterator it = list.begin(); it < list.end(); it++)queue_list_2.push(distance(*it));
    for(int i = 0; i < K; i++){
        result.push_back(queue_list_2.top());
        queue_list_2.pop();
    }
    return result;
};