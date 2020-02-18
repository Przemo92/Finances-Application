#ifndef TIMEMENEGER_H
#define TIMEMENEGER_H
#include <iostream>
#include <vector>
#include <time.h>
#include <conio.h>

#include "AuxiliaryMethods.h"

using namespace std;

class TimeMeneger
{
AuxiliaryMethods auxiliaryMethods;
int calculateDaysInMonth(int month, int year);

public:
    //TimeMeneger(){};
    string getTodaysDate();
    int changeTextDateToInteger(string textDate);
    bool isCorrectDate (string textDate);
    int getMonthWithYear(string date);
    string changeIntDateIntoString(int date);
    string getLastMonthWithYear();
    int getSelectedData();

};
#endif
