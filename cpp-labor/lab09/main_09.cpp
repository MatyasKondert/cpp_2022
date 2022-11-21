#include <iostream>
#include <vector>

#include "Szemely.h"
#include "Alkalmazott.h"
#include "Manager.h"
#include "Ceg.h"

using namespace std;

int main() {
    /*Szemely a("Nagy","Csaba",1995);
    //cout<<a;
    Manager m("Kis","Laszlo",1993,"IT");
    *//*Manager* m1 = new Manager("Kis","Laszlo",1993,"IT");
    cout<<*m1;*//*
    m.addAlkalmazott(new Alkalmazott("Nagy","Csaba",1995,"IT"));
    m.addAlkalmazott(new Alkalmazott("Nagy","Karoly",1995,"IT"));
    m.addAlkalmazott(new Alkalmazott("Kis","Attila",1995,"IT"));
    m.addAlkalmazott(new Alkalmazott("Kis","Gabor",1995,"IT"));
    m.addAlkalmazott(new Alkalmazott("Kozepes","Peter",1995,"IT"));
    m.addAlkalmazott(new Alkalmazott("Kozepes","David",1995,"IT"));
    cout<<m;*/
    Ceg ceg;
    vector<Alkalmazott*> alkamazottak {
            new Alkalmazott("Nagy","Csaba",1995,"IT"),
            new Alkalmazott("Nagy","Karoly",1995,"IT"),
            new Alkalmazott("Kis","Csaba",1995,"IT"),
            new Alkalmazott("Kis","Attila",1995,"IT"),
            new Alkalmazott("Kozepes","Peter",1995,"IT"),
            new Alkalmazott("Kozepes","David",1995,"IT"),
            new Alkalmazott("Orias","Lajos",1995,"IT")
    };
    vector<Manager*> managerek {
            new Manager("Kalman","Tamas",1993,"IT"),
            new Manager("Kadar","Szabolcs",1993,"IT"),
            new Manager("Kelemeen","Robert",1993,"IT")
    };
    ceg.addAlkalmazott(alkamazottak[0]);
    ceg.addAlkalmazott(alkamazottak[1]);
    ceg.addAlkalmazott(alkamazottak[2]);
    ceg.addAlkalmazott(alkamazottak[3]);
    ceg.addAlkalmazott(alkamazottak[4]);
    ceg.addAlkalmazott(alkamazottak[5]);
    ceg.addAlkalmazott(alkamazottak[6]);
    ceg.addAlkalmazott(managerek[0]);
    ceg.addAlkalmazott(managerek[1]);
    ceg.addAlkalmazott(managerek[2]);
    ceg.printAll(cout);
    ceg.addToManager(alkamazottak[0],managerek[0]);
    ceg.addToManager(alkamazottak[1],managerek[0]);
    ceg.addToManager(alkamazottak[2],managerek[1]);
    ceg.addToManager(alkamazottak[3],managerek[1]);
    ceg.addToManager(alkamazottak[4],managerek[1]);
    ceg.addToManager(alkamazottak[5],managerek[2]);
    ceg.addToManager(alkamazottak[6],managerek[2]);
    ceg.printManager(cout);
    return 0;
}