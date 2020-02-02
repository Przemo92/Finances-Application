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
    //string pobierzLiczbe(string tekst, int pozycjaZnaku);
    int changeStringIntoInt(string number);
    string changeFirstLetterIntoCapital(string text);
    //int wczytajLiczbeCalkowita();
};
#endif
