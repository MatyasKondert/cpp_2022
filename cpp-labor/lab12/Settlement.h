//
// Created by Matyas Kondert on 12/7/2022.
//

#ifndef LAB12_SETTLEMENT_H
#define LAB12_SETTLEMENT_H


#include <string>
#include <iostream>
using namespace std;

class Settlement {
    string name = "";
    string county = "";
    int population = 0;
public :
    Settlement(const string &name, const string &county, int population);

    Settlement();

    const string &getName() const;

    void setName(const string &name);

    const string &getCounty() const;

    void setCounty(const string &county);

    int getPopulation() const;

    void setPopulation(int population);

    friend ostream &operator<<(ostream &os, const Settlement &settlement);
};


#endif //LAB12_SETTLEMENT_H
