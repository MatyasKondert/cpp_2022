#include <iostream>
#include "util.h"

int main() {
    /*Point a(1,4);
    Point b(1,10);
    Point c(7,10);
    Point d(7,5);*/

    //testIsSquare("points.txt");

    Point * array = createArray(11);
    printArray(array,11);
    std::cout<<'\n';
    /*std::pair<Point,Point> pair = farthestPoints(array,10);
    pair.first.print();
    std::cout<<'\n';
    pair.second.print();
    std::cout<<'\n';*/
    //sortPoints(array,10);
    Point* out = new Point[11];
    out = farthestPointsFromOrigin(array,11);
    printArray(out,10);
    deletePoints(out);
    std::cout<<'\n';
    printArray(out,10);
    return 0;
}
