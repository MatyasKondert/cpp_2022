//
// Created by Matyas Kondert on 11/16/2022.
//

#ifndef LAB9_ALKALMAZOTT_H
#define LAB9_ALKALMAZOTT_H

#include <iostream>
#include <string>
#include "Szemely.h"

class Alkalmazott: public Szemely
{
private:
    static int id;
    std::string munkakor;
public:
    Alkalmazott(const std::string &vezetekNev, const std::string &keresztNev, int szuletesiEv,
                const std::string &munkakor);

    static int getId();

    void print(std::ostream &o) override;
};


#endif //LAB9_ALKALMAZOTT_H
