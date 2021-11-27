#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>

double compute_median(std::vector<double> data){
    int check = data.size() % 2;//0 or 1.
    std::nth_element(data.begin(), data.begin() + (data.size() / 2 + 1), data.end());
    double max_size = 0.0, max_size_2 = 0.0, median;
    for(std::vector<double>::iterator it = data.begin(); it < (data.begin() + (data.size() / 2 + 1)); it++){
        if(max_size < *it){
            max_size_2 = max_size;
            max_size = *it;
        }else if(max_size_2 < (*it))max_size_2 = *it;
        else;
    }
    //calculate the median
    if(check == 0)median = (max_size + max_size_2) / 2;
    else median = max_size;
    return median;
}
std::vector<double> compute_k_closest(int K, std::vector<double> origin_data){
    if(K > origin_data.size()){
        std::cout << "over size about K you input!" << std::endl;
        std::exit(1);
    }
    double origin_median = compute_median(origin_data);
    std::cout << "origin_median : " << origin_median << std::endl;
    int plus;
    std::vector<double> result;
    std::function<bool(double,double)> func = [&](double a,double b){return abs(origin_median - a) > abs(origin_median - b);};
    std::priority_queue<double, std::vector<double>, decltype(func)> q(func);
    for(std::vector<double>::iterator it = origin_data.begin(); it != origin_data.end(); it++)q.push(*it);
    for(int i = 0; i < K; i++){
        result.push_back(q.top());
        q.pop();
    }
    return result;
}

int main(void){
    //test compute_median code
    std::vector<double> data;
    int K;
    double data_arr[] = {7.0,14.0,10.0,12.0,2.0,11.0,29.0,3.0,4.0};
    for(int i = 0; i < sizeof(data_arr)/sizeof(data_arr[0]); i++)data.push_back(data_arr[i]);
    std::cout << "Please input the number you want output" << std::endl;
    std::cout << ">>>";
    std::cin >> K;
    std::vector<double> result_main = compute_k_closest(K, data);
    std::cout << "result : {";
    for(std::vector<double>::iterator it = result_main.begin(); it != result_main.end(); it++){
        if(it == (result_main.end() - 1))std::cout << *it ;
        else std::cout << *it << ", ";
    }
    std::cout << "}" << std::endl;
}