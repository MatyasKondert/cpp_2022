#include <iostream>
#include "functions.h"

int main() {
    /*for (int i=0;i<=127;i++)
    {
        cout<<countBits(i);
        cout<<"\n";
    }*/


    /*for (int i = 0; i < 35; ++i) {
        int n = 20;
        if(setBit(n, i)){
            cout<<i<<" ---> " << n <<endl;
        }else{
            cout<<"Impossible operation!" << endl;
        }
    }*/

    /*double array[5]={1,2,3,4,5};
    int numElements = 5;
    pair<double,double> p = max2(array,numElements);
    cout<<p.first<<", "<< p.second;
*/

/*
    string bemenet;
    cin>>bemenet;
    istringstream iss(bemenet);
    double counter;
    double number;
    string s;
    while (!iss.eof())
    {
        iss>>s;
        istringstream iss2(s);
        if (iss2>>number)
            counter += number;
    }
    cout << counter << endl;*/

    //cout<<countWords("asjodnas doiasnd asodjnaskjsdoas sdja ssojd as sdjasjd asdj");

    //cout<<decode(code("almaz ALMAZ"))<<'\n';

    string bemenet;

    getline(cin,bemenet);

    //cout<<bemenet;

    cout<<capitalizeWords(bemenet);
    return 0;
}
