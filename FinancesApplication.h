#ifndef FINANCESAPPLICATION_H
#define FINANCESAPPLICATION_H

#include "UserMeneger.h"
#include "IncomeMeneger.h"
#include "ExpenceMeneger.h"
#include "AuxiliaryMethods.h"
#include "TimeMeneger.h"

using namespace std;

class FinancesApplication
{
    AuxiliaryMethods auxiliaryMethods;
    TimeMeneger timeMeneger;
    UserMeneger userMeneger;
    IncomeMeneger *incomeMeneger;
    ExpenceMeneger *expenceMeneger;
    const string NAME_FILE_WITH_INCOMES;
    const string NAME_FILE_WITH_EXPENCES;
    char choose;

public:

    FinancesApplication (string nameFileWithUsers, string nameFileWithIncomes, string nameFileWithExpences)
    : userMeneger (nameFileWithUsers), NAME_FILE_WITH_INCOMES(nameFileWithIncomes), NAME_FILE_WITH_EXPENCES(nameFileWithExpences)
        {
            incomeMeneger = NULL;
            expenceMeneger = NULL;
        };
    ~FinancesApplication()
    {
        delete incomeMeneger;
        incomeMeneger = NULL;
        delete expenceMeneger;
        expenceMeneger = NULL;
    };
    void userRegistration();
    void userLogin();
    void mainMenu();
    void chooseFromMainMenu();
    void chooseOptionFromUserMenu();
    void addIncome();
    void userLogout();
    void changePasswordLogedUser();
    void addExpence();
    void balanceFromCurrentMonth();
    void balanceFromLastMonth();
    void balanceFromSelectedPeroid();
};
#endif
