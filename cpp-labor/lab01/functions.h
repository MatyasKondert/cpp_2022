//
// Created by Matyas Kondert on 9/21/2022.
//

#ifndef TEST_FUNCTIONS_H
#define TEST_FUNCTIONS_H

#include <iostream>
#include <cmath>
#include <utility>
#include "float.h"
#include <sstream>
#include <ctype.h>

using namespace std;

int countBits(int number);
bool setBit(int& number, int order);
double mean(double array[], int numElements);
double stddev(double array[], int numElements);
pair<double, double> max2(double array[], int numElements);
void test (int * p);
int countWords(string text);
string code(string bemenet);
string decode(string bemenet);
string capitalizeWords(string text);


#endif //TEST_FUNCTIONS_H
