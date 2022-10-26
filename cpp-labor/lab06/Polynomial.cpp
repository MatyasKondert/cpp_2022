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
    print();
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
        cout<<i<<":"<<array[i]<<' ';
    }

    cout<<this->capacity-1;
    Polynomial p(this->capacity-1, array);
    p.print();
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



