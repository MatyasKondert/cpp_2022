#include <iostream>
#include <iomanip>
#include "PointSet.h"
#include "Polynomial.h"
#include <cmath>

double fact(double x){
    double sz = 1;
    for (int i=1;i<=x;i++){
        sz = sz * i;
    }
    return sz;
}

int main() {
    /*int n = 2;
    cout<<"Pontok\tMinTav\t MaxTav\t #tavolsagok\t#kulonbozotavolsagok"<<endl;
    cout<< fixed;
    for( int i= 0; i<12; ++i ){
        PointSet pSet( n );
        cout<<setw(6)<<n<<" ";
        cout<<setw(8)<<setprecision(2)<<pSet.minDistance()<<" ";
        cout<<setw(8)<<setprecision(2)<<pSet.maxDistance()<<" ";
        cout<<setw(10) << pSet.numDistances()<<" ";
        cout<<setw(16) << pSet.numDistinctDistances()<<endl;
        n = n << 1;
    }*/

    /*PointSet pset1(10);
    cout<<"#points: " <<Point::getCounter()<<endl;
    PointSet pset2(20);
    cout<<"#points: " <<Point::getCounter()<<endl;*/

    double* array = new double[3];
    array[0]=2;
    array[1]=1;
    array[2]=1;

    Polynomial p1(2,array);

    p1.print();

    Polynomial p2(p1.derivative());

    p2.print();

    cout<<'\n';

    cout<<p2[0];

    cout<<'\n';

    Polynomial p3(-p2);

    p3.print();

    Polynomial p4(p1+p2);

    p4.print();

    Polynomial p5(p1-p2);

    p5.print();

    Polynomial p6(p1*p2);

    p6.print();

}

