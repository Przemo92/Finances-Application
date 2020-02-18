#ifndef INCOMEFILE_H
#define INCOMEFILE_H

#include <iostream>
#include <vector>

#include "Income.h"
#include "AuxiliaryMethods.h"
#include "Markup.h"
#include "TimeMeneger.h"

using namespace std;

class IncomeFile
{
    const string NAME_FILE_WITH_INCOMES;
    int idLastIncome;
    CMarkup xml;
    AuxiliaryMethods auxiliaryMethods;
    TimeMeneger timeMeneger;

public:
    IncomeFile(string nameFileWithIncomes) : NAME_FILE_WITH_INCOMES (nameFileWithIncomes)
    {
        idLastIncome = 0;
    };
    int loadIdLastIncome();
    bool addIncomeToFile (Income income);
    vector <Income> downloadIncomesFormFile(int idLogedUser);

};
#endif
