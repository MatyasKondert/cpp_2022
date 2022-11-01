//
// Created by Matyas Kondert on 10/26/2022.
//

#include "Polynomial.h"

Polynomial::Polynomial(int degree, const double *coefficients)
{
    this->capacity=degree;
    this->coefficients = new double[degree];
    for (int i=0;i<=degree;i++){
        this->coefficients[i]=coefficients[i];
    }
}

Polynomial::Polynomial(const Polynomial &that)
{
    this->capacity=that.capacity;
    for (int i=0;i<=that.capacity;i++){
        this->coefficients[i]=that.coefficients[i];
    }
}

Polynomial::Polynomial(Polynomial &&that)
{
    this->capacity=that.capacity;
    for (int i=0;i<=that.capacity;i++){
        this->coefficients[i]=that.coefficients[i];
    }
    that.capacity = -1;
    that.coefficients = nullptr;
}

Polynomial::~Polynomial()
{
    this->capacity=-1;
    this->coefficients= nullptr;
}

int Polynomial::degree() const
{
    return this->capacity;
}

double Polynomial::evaluate(double x) const
{
    double counter = 0;
    for (int i=0;i<=this->capacity;i++){
        counter += pow(x,capacity-i)*this->coefficients[i];
    }
    return counter;
}

Polynomial Polynomial::derivative() const
{
    double* array = new double[this->capacity];
    for (int i=0;i<this->capacity;i++){
        array[i] = this->coefficients[i] * capacity - i;
    }

    Polynomial p(this->capacity-1, array);
    return p;
}

void Polynomial::print()
{
    for (int i=0;i<=this->capacity;i++){
        cout<<this->coefficients[i]<<"x^"<<capacity-i;
        if (i<this->capacity)
            cout<<"+";
    }
    cout<<'\n';
}

double Polynomial::operator[](int index) const
{
    return this->coefficients[index];
}

Polynomial operator-(const Polynomial &a)
{
    int degree=a.capacity;
    double* coef = new double[degree+1];
    for (int i=0;i<=a.capacity;i++){
        coef[i] = a.coefficients[i]*-1;
    }
    return Polynomial(degree, coef);
}

Polynomial operator+(const Polynomial &a, const Polynomial &b)
{
    int degree;
    if (a.capacity>b.capacity)
        degree = a.capacity;
    else
        degree = b.capacity;
    double* coef = new double[degree+1];
    for (int i=0;i<=degree;i++){
        if (a.capacity >= i && b.capacity >= i){
            coef[degree-i] = a.coefficients[a.capacity-i] + b.coefficients[b.capacity-i];
            continue;
        }
        if (a.capacity >= i){
            coef[degree-i] = a.coefficients[degree-i];
        }
        if (b.capacity >= i){
            coef[degree-i] = b.coefficients[degree-i];
        }
    }
    return Polynomial(degree, coef);
}

Polynomial operator-(const Polynomial &a, const Polynomial &b)
{
    int degree;
    if (a.capacity>b.capacity)
        degree = a.capacity;
    else
        degree = b.capacity;
    double* coef = new double[degree+1];
    for (int i=0;i<=degree;i++){
        if (a.capacity >= i && b.capacity >= i){
            coef[degree-i] = a.coefficients[a.capacity-i] - b.coefficients[b.capacity-i];
            continue;
        }
        if (a.capacity >= i){
            coef[degree-i] = a.coefficients[degree-i];
        }
        if (b.capacity >= i){
            coef[degree-i] = -b.coefficients[degree-i];
        }
    }
    return Polynomial(degree, coef);
}

Polynomial operator*(const Polynomial &a, const Polynomial &b)
{
    int degree = a.capacity+b.capacity;
    double* coef = new double[degree+1];
    for (int i=0;i<=degree;i++){
        coef[i] = 0;
    }
    for (int i=0;i<=a.capacity;i++){
        for (int j=0;j<=b.capacity;j++){
            coef[i+j] += a[i]*b[j];
        }
    }
    return Polynomial(degree, coef);
}







