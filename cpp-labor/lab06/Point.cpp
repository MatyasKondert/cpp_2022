//
// Created by Matyas Kondert on 10/26/2022.
//

#include "Point.h"

int Point::counter{0};

Point::Point(int x, int y)
{
    if ((x<0 || x>M)||(y<0 || y>M))
        throw std::invalid_argument("values must be between 0 and 2000");
    this->x = x;
    this->y = y;
    counter=counter+1;
}


int Point::getX() const
{
    return this->x;
}

int Point::getY() const
{
    return this->y;
}

double Point::distanceTo(const Point &point) const
{
    return sqrt(pow((getX() - point.getX()), 2) + pow((getY() - point.getY()), 2));
}

void Point::print()
{
    std::cout<<this->x<<"/"<<this->y;
}

Point::~Point()
{
    counter--;
}

int Point::getCounter()
{
    return counter;
}

Point::Point(const Point& p)
{
    if ((p.x<0 || p.x>M)||(p.y<0 || p.y>M))
        throw std::invalid_argument("values must be between 0 and 2000");
    this->x=p.x;
    this->y=p.y;
    counter++;
}
