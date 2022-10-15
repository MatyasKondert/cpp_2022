//
// Created by Matyas Kondert on 10/12/2022.
//

#include "Point.h"

Point::Point(int x, int y)
{
    if ((x<0 || x>M)||(y<0 || y>M))
        throw std::invalid_argument("values must be between 0 and 2000");
    this->x = x;
    this->y = y;
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
