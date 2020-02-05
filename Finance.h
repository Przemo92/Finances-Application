#ifndef FINANCE_H
#define FINANCE_H
#include <iostream>
#include <vector>
#include <time.h>
#include <conio.h>

#include "AuxiliaryMethods.h"

using namespace std;

class Finance
{
AuxiliaryMethods auxiliaryMethods;
int calculateDaysInMonth(int month, int year);

public:
    string getTodaysDate();
    int changeTextDateToInteger(string textDate);
    bool isCorrectDate (string textDate);

};
#endif
