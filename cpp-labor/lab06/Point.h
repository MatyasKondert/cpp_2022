//
// Created by Matyas Kondert on 10/26/2022.
//

#ifndef LAB6_POINT_H
#define LAB6_POINT_H

#include <iostream>
#include <math.h>
#define M 2000
class Point{
private:
    int x, y;
    static int counter;
public:
    Point( int x=0, int y=0);
    Point(const Point& p);
    ~Point();
    int getX() const;
    int getY() const;
    double distanceTo(const Point& point)const ;
    void print();

    static int getCounter();
};


#endif //LAB6_POINT_H
