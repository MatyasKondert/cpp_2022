#include <iostream>
#include <vector>

#include "Szemely.h"
#include "Alkalmazott.h"
#include "Manager.h"

using namespace std;

int main() {
    Szemely a("Nagy","Csaba",1995);
    //cout<<a;
    Manager m("Kis","Laszlo",1993,"IT");
    /*Manager* m1 = new Manager("Kis","Laszlo",1993,"IT");
    cout<<*m1;*/
    m.addAlkalmazott(new Alkalmazott("Nagy","Csaba",1995,"IT"));
    m.addAlkalmazott(new Alkalmazott("Nagy","Karoly",1995,"IT"));
    m.addAlkalmazott(new Alkalmazott("Kis","Attila",1995,"IT"));
    m.addAlkalmazott(new Alkalmazott("Kis","Gabor",1995,"IT"));
    m.addAlkalmazott(new Alkalmazott("Kozepes","Peter",1995,"IT"));
    m.addAlkalmazott(new Alkalmazott("Kozepes","David",1995,"IT"));
    cout<<m;
    return 0;
}