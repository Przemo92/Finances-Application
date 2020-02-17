#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class AuxiliaryMethods
{
    public:
    string changeIntIntoString (int number);
    string loadLinie();
    char getSign();
    int changeStringIntoInt(string number);
    string changeFirstLetterIntoCapital(string text);
    float downloadFloatNumber();
    string changeFloatToString(float number);
};
#endif
