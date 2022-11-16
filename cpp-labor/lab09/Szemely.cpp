//
// Created by Matyas Kondert on 11/16/2022.
//

#include "Szemely.h"
using namespace std;

Szemely::Szemely(const string &vezetekNev, const string &keresztNev, int szuletesiEv) : vezetekNev(vezetekNev),
                                                                                        keresztNev(keresztNev),
                                                                                        szuletesiEv(szuletesiEv)
{}

void Szemely::print(ostream &o)
{
    o<<this->vezetekNev<<" "<<this->keresztNev;
}

ostream &operator<<(ostream &os, Szemely &szemely)
{
    szemely.print(os);
    return os;
}


