#include <iostream>
#include "OrderdList.h"

using namespace std;

int main() {
    OrderedList<int> l;
    for( int i=0; i<30; ++i ){
        int v = rand() % 10;
        l.insert( v );
    }
        l.print(cout);
    cout << endl;
    Iterator<int> it( l );
    while( it.hasNext() ){
        cout<<it.next()<<"\t";
    }
    cout<<endl;
    for( int i=0; i<10; ++i ){
        int t = rand() % 10;
        cout<<"\nTorlendo: "<<t<<endl;
        l.remove( t );
        l.print(cout);
    }
}