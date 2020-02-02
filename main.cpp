#include <iostream>
#include "FinancesApplication.h"

using namespace std;

int main()
{
    FinancesApplication financesApplication("Users.xml", "Incomes.xml", "Expences.xml");

    financesApplication.mainMenu();

}
