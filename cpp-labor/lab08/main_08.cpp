#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <random>

using namespace std;

int main() {


    vector<string> fruits {
            "melon", "strawberry", "raspberry","apple", "banana", "walnut", "lemon"
    };
    string toFind = "qwesadadwq";
    auto findFruits = find_if(fruits.begin(),fruits.end(),[toFind](string v){
        return v.find(toFind) != string::npos;
    });
    if (findFruits != fruits.end())
        cout<<"van";
    else
        cout<<"nincs";
    cout<<'\n';
    vector<int> szamok {1,2,3,4,5,6,7,8,9};
    bool paros = all_of(szamok.begin(),szamok.end(),[](int i){
        return i%2==0;
    });
    if (paros)
        cout<<"paros";
    else
        cout<<"nem paros";
    cout<<'\n';
    for_each(szamok.begin(),szamok.end(),[](int i){
        cout<<i<<" ";
    });
    cout<<'\n';
    for_each(szamok.begin(),szamok.end(),[](int& i){
        i=i*2;
    });
    for_each(szamok.begin(),szamok.end(),[](int i){
        cout<<i<<" ";
    });
    cout<<'\n';
    vector<string> months {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
    };
    int numOfMonths = count_if(months.begin(),months.end(),[](string s){
        return s.length() == 5;
    });
    cout<<numOfMonths;
    cout<<'\n';

    sort(szamok.begin(),szamok.end(),[](int a,int b){
        return a>b;
    });
    for_each(szamok.begin(),szamok.end(),[](int i){
        cout<<i<<" ";
    });
    cout<<'\n';
    sort(szamok.begin(),szamok.end(),[](int a,int b){
        return a<b;
    });
    for_each(szamok.begin(),szamok.end(),[](int i){
        cout<<i<<" ";
    });
    cout<<'\n';
    sort(szamok.begin(),szamok.end(),greater<int>());
    for_each(szamok.begin(),szamok.end(),[](int i){
        cout<<i<<" ";
    });
    cout<<'\n';

    vector<pair<string,double>> mounthTemps;
    for_each(months.begin(),months.end(),[&mounthTemps](string s){
        mounthTemps.emplace_back(pair<string,double>(s,rand()%10));
    });
    for_each(mounthTemps.begin(),mounthTemps.end(),[](pair<string,double> p){
        cout<<p.first<<": "<<p.second<<"\n";
    });
    cout<<'\n';
    sort(mounthTemps.begin(),mounthTemps.end(),[](pair<string,double> a,pair<string,double> b){
       return a.second<b.second;
    });
    for_each(mounthTemps.begin(),mounthTemps.end(),[](pair<string,double> p){
        cout<<p.first<<": "<<p.second<<"\n";
    });

    vector<double> realNums {0.1,0.2,0.3,0.4,-0.1,-0.2,-0.3,-0.4};

    sort(realNums.begin(),realNums.end(),[](double a, double b){
        return abs(a)<abs(b);
    });
    for_each(realNums.begin(),realNums.end(),[](double d){
        cout<<d<<" ";
    });
    cout<<"\n";

    for_each(months.begin(),months.end(),[](string& s){
        s[0] = tolower(s[0]);
    });
    for_each(months.begin(),months.end(),[](string s){
        cout<<s<<" ";
    });
    cout<<"\n";


    vector<char> abc {'a','b','c','d','e','f','g','h','i','j','k',
                'l','m','n','o','p','q','r','s','t','u',
                'v','w','x','y','z'};

    random_device rd;
    mt19937 g(rd());

    shuffle(abc.begin(),abc.end(),g);

    for_each(abc.begin(),abc.end(),[](char s){
        cout<<s<<" ";
    });
    return 0;
}