#ifndef FINANCE_H
#define FINANCE_H
#include <iostream>
#include <vector>
#include <windows.h>
#include <time.h>
#include <conio.h>

#include "AuxiliaryMethods.h"

using namespace std;

class Finance
{
AuxiliaryMethods auxiliaryMethods;
public:
    int getTodaysDate();
    int changeTextDateToInteger(string textDate);
    //bool isCorrectDate (string textDate);////////////do zrobienia
};
#endif
