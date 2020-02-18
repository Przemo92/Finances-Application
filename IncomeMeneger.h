#ifndef INCOMEMENEGER_H
#define INCOMEMENEGER_H
#include <iostream>
#include <vector>
#include <algorithm>

#include "Income.h"
#include "IncomeFile.h"
#include "AuxiliaryMethods.h"
#include "TimeMeneger.h"

using namespace std;

class IncomeMeneger : public TimeMeneger
{
    const int ID_LOGED_USER;
    vector <Income> incomes;
    float incomesSum;
    struct less_than_date
    {
        inline bool operator() (Income& income1, Income& income2)
        {
            return (income1.downloadDate() < income2.downloadDate());
        }
    };

    IncomeFile incomeFile;
    AuxiliaryMethods auxiliaryMethods;

    Income writeNewIncome();
    void showSortedIncomes (vector <Income> sortedIncomes);

public:
    IncomeMeneger (string nameFileWithIncomes, int idLogedUser)
        :incomeFile(nameFileWithIncomes), ID_LOGED_USER(idLogedUser)
    {
        incomes = incomeFile.downloadIncomesFormFile(ID_LOGED_USER);
    };
    void addIncome();
    void showIncomesForThisMonth ();
    float downloadIncomesSum();
    void showIncomesForLastMonth();
    void showIncomesForSelectedPeroid(int date1ForSelectedPeroid, int date2ForSelectedPeroid);

};
#endif
