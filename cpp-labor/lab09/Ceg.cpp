//
// Created by Matyas Kondert on 11/20/2022.
//

#include "Ceg.h"

using namespace std;

void Ceg::removeAlkalmazott(int id)
{
    remove_if(alkalmazottak.begin(),alkalmazottak.end(),[id](Szemely* a){
        return dynamic_cast<Alkalmazott*>(a)->getId()==id;
    });
}

void Ceg::addToManager(Szemely* a, Szemely* m)
{
    dynamic_cast<Manager*>(m)->addAlkalmazott((dynamic_cast<Alkalmazott*>(a)));
}

void Ceg::removeFromManager(Szemely* a, Szemely* m)
{
    dynamic_cast<Manager*>(m)->deleateAlkalmazott((dynamic_cast<Alkalmazott*>(a)));
}

void Ceg::printAll(ostream &os)
{
    for(auto item:alkalmazottak){
        os<<item<<"\n";
    }
}

void Ceg::printManager(ostream &os)
{
    for(auto item:alkalmazottak){
        if (dynamic_cast<Manager*>(item) != nullptr)
            os<<*item<<"\n";
    }
}

void Ceg::addAlkalmazott(Szemely *a)
{
    alkalmazottak.emplace_back(a);
}
