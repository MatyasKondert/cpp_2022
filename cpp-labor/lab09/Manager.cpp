//
// Created by Matyas Kondert on 11/16/2022.
//

#include "Manager.h"

using namespace std;

const string Manager::MANAGER_MUNKAKOR = "manager";

Manager::Manager(const std::string &vezetekNev, const std::string &keresztNev, int szuletesiEv,
                 const std::string &munkakor) : Alkalmazott(vezetekNev, keresztNev, szuletesiEv, munkakor)
{}

void Manager::addAlkalmazott(Alkalmazott *alk)
{
    beosztotak.emplace_back(alk);
}

void Manager::deleateAlkalmazott(Alkalmazott *alk)
{
    remove(beosztotak.begin(),beosztotak.end(),alk);
}

void Manager::print(std::ostream &o)
{
    Alkalmazott::print(o);
    cout<<' '<<"beosztottjai:"<<'\n';
    for (auto item : beosztotak){
        item->print(o);
    }
}

const int Manager::beosztotakSzama()
{
    return beosztotak.size();
}

void Manager::deleateAlkalmazottById(int id)
{
    remove_if(beosztotak.begin(),beosztotak.end(),[id](Alkalmazott* a){
        return id == a->getId();
    });
}





