//
// Created by Matyas Kondert on 10/19/2022.
//

#include <random>
#include <iomanip>
#include "Matrix.h"


int Matrix::getRows() const { return this->mRows;}
int Matrix::getCols() const { return this->mCols;}

Matrix::Matrix(int mRows, int mCols)
{
    this->mRows = mRows;
    this->mCols = mCols;
    mElements = new double*[mRows];
    for (int i=0;i<mRows;i++)
    {
        mElements[i] = new double[mCols];
    }
}

Matrix::Matrix(const Matrix &what)
{
    mRows=what.mRows;
    mCols=what.mCols;
    mElements = new double*[mRows];
    for (int i=0;i<mRows;i++)
    {
        mElements[i] = new double[mCols];
        for (int j=0;j<mCols;j++){
            mElements[i][j] = what.mElements[i][j];
        }
    }
}

Matrix::~Matrix()
{
    for (int i=0;i<mRows;i++)
    {
        delete[] mElements[i];
    }
}

Matrix::Matrix( Matrix &&what)
{
    mRows=what.mRows;
    mCols=what.mCols;
    mElements = new double*[mRows];
    for (int i=0;i<mRows;i++)
    {
        mElements[i] = new double[mCols];
        for (int j=0;j<mCols;j++){
            mElements[i][j] = what.mElements[i][j];
        }
    }
    delete what.mElements;
    what.mRows = 0;
    what.mCols = 0;
}

void Matrix::fillMatrix(double value)
{
    for (int i=0;i<mRows;i++){
        for (int j=0;j<mCols;j++){
            mElements[i][j] = value;
        }
    }
}

void Matrix::randomMatrix(int a, int b)
{
    for (int i=0;i<mRows;i++){
        for (int j=0;j<mCols;j++){
            random_device rd; // seed the random number generator named rd
            mt19937 mt(rd());
            uniform_real_distribution<double> dist(a, b); // return a number in the given range

            mElements[i][j] = dist(mt);
        }
    }
}

void Matrix::printMatrix(ostream &os) const
{
    for (int i=0;i<mRows;i++){
        for (int j=0;j<mCols;j++){
            os<<mElements[i][j]<<" ";
        }
        os<<'\n';
    }
}

bool Matrix::isSquare() const
{
    return mRows==mCols;
}

Matrix operator+(const Matrix &x, const Matrix &y)
{
    if (x.mRows != y.mRows || x.mCols != y.mCols)
        throw out_of_range("Matrix parameters Dont match1");
    Matrix m(x.mRows,x.mCols);
    for (int i=0;i<x.mRows;i++){
        for (int j=0;j<x.mCols;j++){
            m.mElements[i][j] = x.mElements[i][j] + y.mElements[i][j];
        }
    }
    return m;
}

Matrix &Matrix::operator=(const Matrix &mat)
{
    if (mRows != mat.mRows || mCols != mat.mCols)
        throw out_of_range("Matrix parameters Dont match2");
    mRows=mat.mRows;
    mCols=mat.mCols;
    mElements = new double*[mRows];
    for (int i=0;i<mRows;i++)
    {
        mElements[i] = new double[mCols];
        for (int j=0;j<mCols;j++){
            mElements[i][j] = mat.mElements[i][j];
        }
    }
    return *this;
}

Matrix &Matrix::operator=(Matrix &&mat)
{
    if (mRows != mat.mRows || mCols != mat.mCols)
        throw out_of_range("Matrix parameters Dont match3");
    mRows=mat.mRows;
    mCols=mat.mCols;
    mElements = new double*[mRows];
    for (int i=0;i<mRows;i++)
    {
        mElements[i] = new double[mCols];
        for (int j=0;j<mCols;j++){
            mElements[i][j] = mat.mElements[i][j];
        }
    }
    delete mat.mElements;
    mat.mRows = 0;
    mat.mCols = 0;
    return *this;
}

Matrix operator*(const Matrix &x, const Matrix &y)
{
    if (x.mCols != y.mRows)
        throw out_of_range("Matrix parameters Dont match4");
    Matrix m(x.mRows,y.mCols) ;
    for (int i=0;i<x.mRows;i++){
        for (int j=0;j<y.mCols;j++){
            double sz = 0;
            for (int k=0;k<x.mCols;k++){
                sz += x.mElements[i][k]*y.mElements[k][j];
            }
            m.mElements[i][j] = sz;
        }
    }
    return m;
}

istream &operator>>(istream &is, Matrix &mat)
{
    for (int i=0;i<mat.mRows;i++){
        for (int j=0;j<mat.mCols;j++){
            is>>mat.mElements[i][j];
        }
    }
    return is;
}

ostream &operator<<(ostream &os, const Matrix &mat)
{
    for (int i=0;i<mat.mRows;i++){
        for (int j=0;j<mat.mCols;j++){
            os<<mat.mElements[i][j]<<' ';
        }
    }
    return os;
}

double *Matrix::operator[](int index)
{
    return mElements[index];
}

double *Matrix::operator[](int index) const
{
    return mElements[index];
}













