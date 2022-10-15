//
// Created by Matyas Kondert on 10/12/2022.
//

#include <random>
#include "PointSet.h"


PointSet::PointSet(int n)
{

    this->n=n;
    for (int i=0;i<n;i++){
        random_device rd; // seed the random number generator named rd
        mt19937 mt(rd());
        uniform_int_distribution<int> dist(0, M); // return a number in the given range

        int x = dist(mt);
        int y = dist(mt);
        this->points.emplace_back(Point(x , y));
    }
    computeDistances();
}

void PointSet::computeDistances()
{

    for (int i=0;i<this->n;i++){
        for (int j=i+1;j<this->n;j++){
            this->distances.emplace_back(points[i].distanceTo(points[j]));
        }
    }
}

void PointSet::printPoints() const
{
    for (auto i:this->points){
        i.print();
        cout<<" ";
    }
    cout<<'\n';
}

void PointSet::printDistances() const
{
    for (auto i:this->distances){
        cout<<i<<" ";
    }
    cout<<'\n';
}

double PointSet::maxDistance() const
{
    return *max_element(distances.begin(),distances.end());
}

double PointSet::minDistance() const
{
    return *min_element(distances.begin(),distances.end());
}


int PointSet::numDistances() const
{
    return distances.size();
}

bool compareX(Point a,Point b){
    return (a.getX()<b.getX());
}

bool compareY(Point a,Point b){
    return (a.getY()<b.getY());
}

void PointSet::sortPointsX()
{
    sort(points.begin(),points.end(), compareX);
}

void PointSet::sortPointsY()
{
    sort(points.begin(),points.end(), compareY);
}

void PointSet::sortDistances()
{
    sort(distances.begin(),distances.end());
}

int PointSet::numDistinctDistances()
{
    int size = 0;
    vector<double> tmp;
    tmp = distances;
    sort(tmp.begin(),tmp.end());
    vector<double>::iterator it;
    it = unique(tmp.begin(),tmp.end());
    for (it=tmp.begin(); it!=tmp.end(); ++it){
        size++;
    }
    return size;
}




