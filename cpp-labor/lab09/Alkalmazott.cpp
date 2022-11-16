//
// Created by Matyas Kondert on 11/16/2022.
//

#include "Alkalmazott.h"

int Alkalmazott::id = 0;

Alkalmazott::Alkalmazott(const std::string &vezetekNev, const std::string &keresztNev, int szuletesiEv,
                         const std::string &munkakor) : Szemely(vezetekNev, keresztNev, szuletesiEv), munkakor(munkakor)
{id++;}

void Alkalmazott::print(std::ostream &o)
{
    o<<'\t'<<"Alkalmazott "<<getId()<<" ";
    Szemely::print(o);
    o<<' ';
    o<<munkakor;
    o<<'\n';
}

int Alkalmazott::getId()
{
    return id;
}

