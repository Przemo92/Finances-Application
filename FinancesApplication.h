#ifndef FINANCESAPPLICATION_H
#define FINANCESAPPLICATION_H

#include "UserMeneger.h"
#include "IncomeMeneger.h"
#include "ExpenceMeneger.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FinancesApplication
{
    AuxiliaryMethods auxiliaryMethods;
    UserMeneger userMeneger;
    char choose;

public:

    void userRegistration();
    void mainMenu();
    void chooseFromMainMenu();
};
#endif
