//
// Created by Matyas Kondert on 10/19/2022.
//

#ifndef LAB5_MATRIX_H
#define LAB5_MATRIX_H


#include <iostream>
#include <stdexcept>
using namespace std;
class Matrix {
public:
// Default constructor
    Matrix( int mRows = 10, int mCols =10);
// Copy constructor
    Matrix(const Matrix& what);
// Move constructor
    Matrix( Matrix&& what );
// Destructor
    ~Matrix();
//fills the matrix with identical elements
    void fillMatrix(double value);
//fills the matrix with random real numbers in the range [a, b)
    void randomMatrix(int a, int b); //fills
//prints the matrix
    void printMatrix(ostream& os = cout) const;
//checks whether this matrix is a square one
    bool isSquare() const;
    int getRows() const;
    int getCols() const;

    friend Matrix operator+(const Matrix& x, const Matrix& y);

    friend Matrix operator*(const Matrix& x, const Matrix& y);

    Matrix & operator=(const Matrix& mat);

    Matrix & operator=(Matrix&& mat);

    friend istream & operator>>(istream& is, Matrix& mat);
    friend ostream & operator<<(ostream& os, const Matrix& mat);

    double* operator[] (int index);

    double* operator[] (int index) const;



private:
//Data
    double ** mElements;
    int mRows; //number of rows
    int mCols; //number of columns
};



#endif //LAB5_MATRIX_H
