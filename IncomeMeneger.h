#ifndef INCOMEMENEGER_H
#define INCOMEMENEGER_H
#include <iostream>
#include <vector>

#include "Income.h"
#include "IncomeFile.h"
#include "AuxiliaryMethods.h"
#include "Finance.h"

using namespace std;

class IncomeMeneger : public Finance
{
    const int ID_LOGED_USER;
    vector <Income> incomes;

    IncomeFile incomeFile;
    AuxiliaryMethods auxiliaryMethods;

    Income writeNewIncome();

public:
    IncomeMeneger (string nameFileWithIncomes, int idLogedUser)
    :incomeFile(nameFileWithIncomes), ID_LOGED_USER(idLogedUser)
     {
     incomes = incomeFile.downloadIncomesFormFile(ID_LOGED_USER);
      };
     void addIncome();

};
#endif
