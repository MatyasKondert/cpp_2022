//
// Created by Matyas Kondert on 11/16/2022.
//

#ifndef LAB9_MANAGER_H
#define LAB9_MANAGER_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Alkalmazott.h"

class Manager: public Alkalmazott
{
private:
    std::vector<Alkalmazott*> beosztotak;
public:
    static const std::string MANAGER_MUNKAKOR;
    Manager(const std::string &vezetekNev, const std::string &keresztNev, int szuletesiEv, const std::string &munkakor);
    void addAlkalmazott(Alkalmazott* alk);
    void deleateAlkalmazott(Alkalmazott* alk);
    void deleateAlkalmazottById(int id);
    const int beosztotakSzama();
    void print(std::ostream &o) override;
};


#endif //LAB9_MANAGER_H
