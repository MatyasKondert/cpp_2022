//
// Created by Matyas Kondert on 11/16/2022.
//

#ifndef LAB9_SZEMELY_H
#define LAB9_SZEMELY_H

#include <iostream>
#include <string>

class Szemely
{
private:
    std::string vezetekNev;
    std::string keresztNev;
    int szuletesiEv;
public:
    Szemely(const std::string &vezetekNev, const std::string &keresztNev, int szuletesiEv);
    virtual void print(std::ostream& o);
};
std::ostream &operator<<(std::ostream &os, Szemely &szemely);
#endif //LAB9_SZEMELY_H
