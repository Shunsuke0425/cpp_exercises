#include <iostream>
class Mat4x4{
    public:
    Mat4x4();
    Mat4x4(double another[4][4]);
    Mat4x4 operator*(const Mat4x4& another) const;
    bool operator==(const Mat4x4& another) const;
    Mat4x4 operator-(const Mat4x4& another) const;
    Mat4x4 operator-();
    Mat4x4 operator+(const Mat4x4& another) const;
    Mat4x4 operator+=(const Mat4x4& another);
    Mat4x4 operator-=(const Mat4x4& another);
    double& operator()(int another_i,int another_i2);
    double operator()(const int another_i,const int another_i2) const;
    friend std::ostream& operator<<(std::ostream& ost, const Mat4x4& another);
    double Mat[4][4];
};