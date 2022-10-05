//
// Created by Matyas Kondert on 10/4/2022.
//

#include "util.h"
#include <algorithm>

double distance(const Point& a, const Point& b){
    return sqrt(pow((a.getX()-b.getX()),2)+pow((a.getY()-b.getY()),2));
}

bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d){
    double Dab = distance(a,b);
    double Dad = distance(a,d);
    double Dac = distance(a,c);
    double Dbd = distance(b,d);

    if (Dab == 0 || Dad == 0 || Dac == 0){
        return false;
    }

    if (Dab == Dad && Dac == Dbd){
        return true;
    }
    return false;
}

void testIsSquare(const char * filename){
    std::ifstream in;
    in.open(filename);
    while (!in.eof()){
        int x,y;
        in>>x>>y;
        Point a(x,y);
        in>>x>>y;
        Point b(x,y);
        in>>x>>y;
        Point c(x,y);
        in>>x>>y;
        Point d(x,y);
        if (isSquare(a,b,c,d))
            std::cout<<"YES"<<'\n';
        else
            std::cout<<"NO"<<'\n';

    }
}

Point* createArray(int numPoints){
    Point * points = new Point[numPoints];
    for (int i=0;i<numPoints;i++){
        int x = rand()%2000;
        int y = rand()%2000;
        points[i] = Point(x,y);
    }
    return points;
}

void printArray(Point* points, int numPoints){
    for (int i=0;i<numPoints;i++){
        points[i].print();
        std::cout<<'\n';
    }
}

std::pair<Point, Point> closestPoints(Point* points, int numPoints){
    double minDistance = distance(points[0],points[1]);
    std::pair<Point,Point> pair;
    pair.first = points[0];
    pair.first = points[1];
    for (int i=0;i<numPoints;i++){
        for (int j=i+1;j<numPoints;j++){
            if (distance(points[i],points[j])<minDistance){
                minDistance = distance(points[i],points[j]);
                pair.first = points[i];
                pair.second = points[j];
                if (minDistance == 0)
                    return pair;
            }
        }
    }
    return pair;
}

std::pair<Point, Point> farthestPoints(Point* points, int numPoints){
    double maxDistance = 0;
    std::pair<Point,Point> pair;
    for (int i=0;i<numPoints;i++){
        for (int j=i+1;j<numPoints;j++){
            if (distance(points[i],points[j]) > maxDistance){
                maxDistance = distance(points[i], points[j]);
                pair.first = points[i];
                pair.second = points[j];
            }
        }
    }
    return pair;
}

bool myfunction1 (Point i,Point j) { return (i.getX() < j.getX()); }

void sortPoints(Point* points, int numPoints){
    std::sort(points,points+numPoints,myfunction1);
}

bool myfunction2 (Point i,Point j) {
    Point o(0,0);
    return (distance(o,i) > distance(o,j));
}

Point* farthestPointsFromOrigin(Point* points, int numPoints){
    Point * copy1 = new Point[numPoints];
    Point * copy2 = new Point[numPoints];
    std::copy(points,points+numPoints,copy1);
    std::sort(copy1,copy1+numPoints,myfunction2);
    std::copy(copy1,copy1+10,copy2);
    return copy2;
}

void deletePoints(Point* points){
    delete points;
}


