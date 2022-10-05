//
// Created by Matyas Kondert on 9/21/2022.
//

#include "functions.h"

int countBits(int num)
{
    int count;
    while(num>0)
    {
        if ((num & 1) == 1)
            count++;
        num = num >> 1;
    }
    return count;
}

bool setBit(int& number, int order)
{
    long long x = 1;
    x = x << order;
    if (x > number)
        return false;
    number = number | x;
    return true;
}


double mean(double array[], int numElements)
{
    if (numElements == 0)
        return NAN;
    int sz = 0;
    for (int i=0;i < numElements;i++)
    {
        sz += array[i];
    }
    return sz/numElements;
}

double stddev(double array[], int numElements)
{
    if (numElements == 0)
        return NAN;
    double m = mean(array,numElements);
    double sz = 0;
    for (int i=0;i<numElements;i++)
    {
        sz += pow(array[i] - m,2);
    }
    return sqrt(sz/numElements);
}

pair<double, double> max2(double array[], int numElements)
{
    pair<double,double> pair;
    pair.first =NAN;
    pair.second = NAN;
    if (numElements == 0)
        return pair;
    pair.first = array[0];
    pair.second = array[0];
    if (numElements == 1)
        return pair;
    pair.first = -DBL_MAX;
    pair.second = -DBL_MAX;

    for (int i=0;i<numElements;i++)
    {
        if (array[i] > pair.second)
        {
            pair.first = pair.second;
            pair.second = array[i];
        }
        else if (array[i] > pair.first){
            pair.first = array[i];
        }
    }
    return pair;
}

int countWords(string text)
{
    string s;
    int count = 0;
    istringstream iss(text);
    while(iss.eof() == false)
    {
        iss>>s;
        count++;
    }
    return count;
}

string code(string bemenet)
{
    string code = "";
    for (auto i: bemenet)
    {
        if (((int) i >= 97 && (int) i <= 121) || ((int) i >= 65 && (int) i <= 89))
        {
            i = i + 1;
        }
        if ((int) i == 122)
        {
            i = 'a';
        }
        if ((int) i == 90)
        {
            i = 'A';
        }
        code.push_back(i);
    }
    return code;
}

string decode(string bemenet)
{
    string code = "";
    for (auto i: bemenet)
    {
        if (((int) i >= 98 && (int) i <= 122) || ((int) i >= 66 && (int) i <= 90))
        {
            i = i - 1;
        }
        else
        {
            if ((int) i == 97)
            {
                i = 'z';
            }
            if ((int) i == 65)
            {
                i = 'Z';
            }
        }
        code.push_back(i);
    }
    return code;
}

string capitalizeWords(string text)
{
    string final = "";
    string stremSting;
    istringstream iss(text);
    while (!iss.eof())
    {
        iss>>stremSting;
        stremSting[0] = toupper(stremSting[0]);
        final.append(stremSting);
        final.append(" ");
    }
    return final;
}