#include <iostream>
#include "Mat4x4.h"
Mat4x4::Mat4x4(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(i == j){
                Mat[i][j] = 1.0;
            }else{
                Mat[i][j] = 0.0;
            }
        }
    }
}
Mat4x4::Mat4x4(double another[4][4]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            Mat[i][j] = another[i][j];
        }
    }
}
Mat4x4 Mat4x4::operator*(const Mat4x4& another) const{
    Mat4x4 result;
    for(int i = 0; i < 4; i++ ){
        for(int j = 0; j < 4; j++ ){
            result.Mat[i][j] = 0.0;
            for(int k = 0; k < 4; k++){
                result.Mat[i][j] += Mat[i][k] * another.Mat[k][j];
            }
        }
    }
    return result;
}
bool Mat4x4::operator==(const Mat4x4& another) const{
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if((*this).Mat[i][j] != another.Mat[i][j])return false;
        }
    }
    return true;
}
Mat4x4 Mat4x4::operator-(const Mat4x4& another) const{
    Mat4x4 result;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            result.Mat[i][j] = Mat[i][j] - another.Mat[i][j];
        }
    }
    return result;
}
Mat4x4 Mat4x4::operator-(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            Mat[i][j] = 0.0 - Mat[i][j];
        }
    }
    return *this;
}
Mat4x4 Mat4x4::operator+(const Mat4x4& another) const{
    Mat4x4 result;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            result.Mat[i][j] = Mat[i][j] + another.Mat[i][j];
        }
    }
    return result;
}
Mat4x4 Mat4x4::operator+=(const Mat4x4& another){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            Mat[i][j] = Mat[i][j] + another.Mat[i][j];
        }
    }
    return *this;
}
Mat4x4 Mat4x4::operator-=(const Mat4x4& another){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            Mat[i][j] = Mat[i][j] - another.Mat[i][j];
        }
    }
    return *this;
}
double& Mat4x4::operator()(int another_i,int another_i2){
    return Mat[another_i][another_i2];
}
double Mat4x4::operator()(const int another_i,const int another_i2) const{
    return Mat[another_i][another_i2];
}
std::ostream& operator<<(std::ostream& ost, const Mat4x4& another){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            ost << another.Mat[i][j] << " ";
        }
        ost << std::endl;
    }
    return ost;
}