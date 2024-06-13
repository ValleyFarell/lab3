#include<iostream>
#include"matrix.h"
using namespace std;

template<class T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& obj)
{
    for (size_t i = 0; i < obj.getSize(); ++i) {
        for (size_t j = 0; j < obj.getSize(); ++j) {
            os << obj[i][j] << " ";
        }
        os << endl;
    }
    return os;
}
int main() {
    int arr[3][3] = {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };
    size_t u = 3;
    Matrix<int> mat1(arr, u);
    Matrix<int> mat2(arr, u);
    cout << mat1 - mat2;
}
