//
// Created by Matyas Kondert on 10/12/2022.
//

#ifndef LAB4_POINT_H
#define LAB4_POINT_H
#include <iostream>
#include <math.h>
#define M 2000
class Point{
private:
    int x, y;
public:
    Point( int x=0, int y=0);
    int getX() const;
    int getY() const;
    double distanceTo(const Point& point)const ;
    void print();
};



#endif //LAB4_POINT_H
