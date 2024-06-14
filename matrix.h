#pragma once
#include"ArraySequence.h"

template<class T>
class Matrix {
    private:
        ArraySequence<ArraySequence<T>> baseMatrix;
        size_t size;
    public:
        Matrix() {
            ArraySequence<ArraySequence<T>> tmpMatrix(0);
            baseMatrix = tmpMatrix;
        };
        Matrix(size_t size) {
            ArraySequence<ArraySequence<T>> tmpMatrix(size);
            for (size_t i = 0; i != size; ++i) {
                ArraySequence<T> tmpVec(size);
                tmpMatrix[i] = tmpVec;
            }
            baseMatrix = tmpMatrix;
        };
        template<size_t n, size_t m> 
        Matrix(T (&items)[n][m], size_t size) {
            this->size = size;
            ArraySequence<ArraySequence<T>> tmpMatrix(size);
            for (size_t i = 0; i != size; ++i) {
                ArraySequence<T> tmpVec(items[i], size);
                tmpMatrix[i] = tmpVec;
            }
            baseMatrix = tmpMatrix;
        };
        size_t const getSize() const {
            return size;
        }
        Matrix Add(const Matrix& other) {
            for (size_t i = 0; i != size; ++i) {
                for (size_t j = 0; j != size; ++j) {
                    this->baseMatrix[i][j] += other.baseMatrix[i][j];
                }
            }
            return *this;
        }
        Matrix Multiply(const int& k) {
            for (size_t i = 0; i != size; ++i) {
                for (size_t j = 0; j != size; ++j) {
                    this->baseMatrix[i][j] *= k;
                }
            }
            return *this;
        }
        Matrix Transponation(const int& k) {
            for (size_t i = 0; i != size; ++i) {
                for (size_t j = 0; j != size; ++j) {
                    swap(this->baseMatrix[i][j], this->baseMatrix[j][i]);
                }
            }
            return *this;
        }
        Matrix SwapLines(const int& index1, const int& index2) {
            for (size_t i = 0; i != size; ++i) {
                for (size_t j = 0; j != size; ++j) {
                    swap(this->baseMatrix[index1][j], this->baseMatrix[index2][j]);
                }
            }
            return *this;
        }
        Matrix AddLineToLine(const int& index1, const int& index2, const int& k) {
            for (size_t i = 0; i != size; ++i) {
                for (size_t j = 0; j != size; ++j) {
                    this->baseMatrix[index1][j] += this->baseMatrix[index2][j] * k;
                }
            }
            return *this;
        }
        ~Matrix () {
            delete baseMatrix;
        }
        ArraySequence<T> operator[] (size_t index) const {
            return this->baseMatrix[index];
        }
        Matrix<T>& operator= (const Matrix& other) {
            this->baseMatrix = other.baseMatrix;
            this->size = other.getSize();
            return *this;
        }
        Matrix<T> operator+ (const Matrix& other) const {
            Matrix<T> tmp(this->getSize());
            tmp = *this;
            return tmp.Add(other);
        }
        Matrix<T> operator* (const int& k) const {
            Matrix<T> tmp(this->getSize());
            tmp = *this;
            return tmp.Multiply(k);
        }
        Matrix<T> operator- (const Matrix& other) const {
            Matrix<T> tmp(this->getSize());
            tmp = *this;
            return tmp.Add(other*(-1));
        }
};
