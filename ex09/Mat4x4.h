#include <iostream>
template <class T, int N>
class Matrix{
    public:
    Matrix(){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(i == j){
                    Mat[i][j] = 1.0;
                }else{
                    Mat[i][j] = 0.0;
                }
            }
        }
    }
    Matrix(T another[N][N]){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                Mat[i][j] = another[i][j];
            }
        }
    }
    Matrix<T, N> operator*(const Matrix<T, N>& another) const{
        Matrix<T, N> result;
        for(int i = 0; i < N; i++ ){
            for(int j = 0; j < N; j++ ){
                result.Mat[i][j] = 0.0;
                for(int k = 0; k < N; k++){
                    result.Mat[i][j] += Mat[i][k] * another.Mat[k][j];
                }
            }
        }
        return result;
    }
    bool operator==(const Matrix<T, N>& another) const{
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if((*this).Mat[i][j] != another.Mat[i][j])return false;
            }
        }
        return true;
    }
    Matrix<T, N> operator-(const Matrix<T, N>& another) const{
        Matrix<T, N> result;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                result.Mat[i][j] = Mat[i][j] - another.Mat[i][j];
            }
        }
        return result;
    }
    Matrix<T, N> operator-(){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                Mat[i][j] = 0.0 - Mat[i][j];
            }
        }
        return *this;
    }
    Matrix<T, N> operator+(const Matrix<T, N>& another) const{
        Matrix<T, N> result;
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                result.Mat[i][j] = Mat[i][j] + another.Mat[i][j];
            }
        }
        return result;
    }
    Matrix<T, N> operator+=(const Matrix<T, N>& another){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                Mat[i][j] = Mat[i][j] + another.Mat[i][j];
            }
        }
        return *this;
    }
    Matrix<T, N> operator-=(const Matrix<T, N>& another){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                Mat[i][j] = Mat[i][j] - another.Mat[i][j];
            }
        }
        return *this;
    }
    T operator()(const int another_i, const int another_i2) const{
        return Mat[another_i][another_i2];
    }
    T operator()(int another_i,int another_i2){
        return Mat[another_i][another_i2];
    }
    T Mat[N][N];
};
template<class T, int N>
std::ostream& operator<<(std::ostream& ost, const Matrix<T, N>& another){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            ost << another.Mat[i][j] << " ";
        }
        ost << std::endl;
    }
    return ost;
};