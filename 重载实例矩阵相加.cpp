/*
 * @Author: your name
 * @Date: 2020-03-17 18:04:28
 * @LastEditTime: 2020-04-01 11:03:42
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /test/test.cpp
 */

#include <iostream>

constexpr int row = 2;
constexpr int col = 3;

using std::istream;
using std::ostream;

class Matrix {
   public:
    Matrix() {}
    friend istream &operator>>(istream &, Matrix &);
    friend ostream &operator<<(ostream &, Matrix &);

    Matrix &operator+=(Matrix m) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                matrix[i][j] += m.matrix[i][j];
            }
        }
        return *this;
    }

   private:
    int matrix[row][col];
};

istream &operator>>(istream &input, Matrix &m) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            input >> m.matrix[i][j];
        }
    }
    return input;
}

ostream &operator<<(ostream &output, Matrix &m) {
    for (int i = 0; i < row; i++) {
        
        std::cout << " | ";
        for (int j = 0; j < col; j++) {
            output << m.matrix[i][j] <<" ";
        }
        std::cout << " | " <<std::endl;
    }
}

Matrix operator+(Matrix a, Matrix b) { return a += b; }

int main() {
    Matrix a, b, c;
    std::cin >> a >> b;
    c = a + b;
    std::cout << c;
}