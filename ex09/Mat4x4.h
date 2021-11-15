#include <iostream>
template <class T, int N>
class Mat4x4{
    public:
    Mat4x4(){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(i == j){
                    Mat[i][j] = 1.0;
                }else{
                    Mat[i][j] = 0.0;
                }
            }
        }
    };
    Mat4x4(T another[N][N]){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                Mat[i][j] = another[i][j];
            }
        }
    };
    Mat4x4<T, N> operator*(const Mat4x4<T, N>& another){
        Mat4x4<T, N> result;
        for(int i = 0; i < N; i++ ){
            for(int j = 0; j < N; j++ ){
                result.Mat[i][j] = 0.0;
                for(int k = 0; k < N; k++){
                    result.Mat[i][j] += Mat[i][k] * another.Mat[k][j];
                }
            }
        }
        return result;
    };
    bool operator==(const Mat4x4<T, N>& another){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if((*this).Mat[i][j] != another.Mat[i][j])return false;
            }
        }
        return true;
    };
    Mat4x4<T, N> operator-(const Mat4x4<T, N>& another){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                Mat[i][j] = Mat[i][j] - another.Mat[i][j];
            }
        }
        return *this;
    };
    Mat4x4<T, N> operator-(){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                Mat[i][j] = 0.0 - Mat[i][j];
            }
        }
        return *this;
    };
    Mat4x4<T, N> operator+=(const Mat4x4<T, N>& another){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                Mat[i][j] = Mat[i][j] + another.Mat[i][j];
            }
        }
        return *this;
    };
    Mat4x4<T, N> operator-=(const Mat4x4<T, N>& another){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                Mat[i][j] = Mat[i][j] - another.Mat[i][j];
            }
        }
        return *this;
    };
    double operator()(const int another_i, const int another_i2){
        return Mat[another_i][another_i2];
    };
    friend std::ostream& operator<<(std::ostream& ost, const Mat4x4<T, N>& another){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                ost << another.Mat[i][j] << " ";
            }
            ost << std::endl;
        }
        return ost;
    };
    T Mat[N][N];
};