//
// Created by Matyas Kondert on 11/20/2022.
//

#ifndef LAB9_CEG_H
#define LAB9_CEG_H

#include "Alkalmazott.h"
#include "Manager.h"

class Ceg
{
private:
    std::vector<Szemely*> alkalmazottak;
public:
    void addAlkalmazott(Szemely* a);
    void removeAlkalmazott(int id);
    void addToManager(Szemely* a,Szemely* m);
    void removeFromManager(Szemely* a,Szemely* m);
    void printAll(std::ostream &os);
    void printManager(std::ostream &os);
};


#endif //LAB9_CEG_H
