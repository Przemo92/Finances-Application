#include "FinancesApplication.h"


void FinancesApplication::mainMenu()
{
      while (true)
    {
        if (!userMeneger.isUserLoged())
        {
            chooseFromMainMenu();

            switch (choose)
            {
            case '1':
                userRegistration();
                break;
            case '2':
                userLogin();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            chooseOptionFromUserMenu();

            switch (choose)
            {
            case '1':
                addIncome();
                break;
            case '2':
                addExpence();
                break;
            case '3':
                balanceFromCurrentMonth();
                break;
            case '4':
                balanceFromLastMonth();
                break;
            case '5':
                 balanceFromSelectedPeroid();
                break;
            case '6':
                changePasswordLogedUser();
                break;
            case '7':
                userLogout();
                cout << endl << "WYLOGOWANO" << endl;
                system("pause");
                break;
            }
        }
    }
}
void FinancesApplication::chooseFromMainMenu()
{
    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choose = auxiliaryMethods.getSign();
}
void FinancesApplication::userRegistration()
{
    userMeneger.userRegistration();
}
void FinancesApplication::userLogin()
{
    userMeneger.userLogin();
    if(userMeneger.isUserLoged())
    {
        incomeMeneger = new IncomeMeneger (NAME_FILE_WITH_INCOMES, userMeneger.getIdLogedUser());
        expenceMeneger = new ExpenceMeneger (NAME_FILE_WITH_EXPENCES, userMeneger.getIdLogedUser());
    }
}
void FinancesApplication::chooseOptionFromUserMenu()
{

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choose = auxiliaryMethods.getSign();
    return;
}
void FinancesApplication::addIncome()
{
    if (userMeneger.isUserLoged())
    {
        incomeMeneger -> addIncome();
    }
    else
    {
        cout << "Aby dodac adresata nalezy najpierw sie zalogowac "<< endl;
        system("pause");
    }
}
void FinancesApplication::addExpence()
{
    if (userMeneger.isUserLoged())
    {
        expenceMeneger -> addExpence();
    }
    else
    {
        cout << "Aby dodac adresata nalezy najpierw sie zalogowac "<< endl;
        system("pause");
    }
}
void FinancesApplication::userLogout()
{
    userMeneger.userLogout();
    delete incomeMeneger;
    incomeMeneger = NULL;
    delete expenceMeneger;
    expenceMeneger = NULL;
}
void FinancesApplication::changePasswordLogedUser()
{
    userMeneger.changePasswordLogedUser();
}
void FinancesApplication::balanceFromCurrentMonth()
{
    system("cls");
       if (userMeneger.isUserLoged())
    {
        cout << ">>> BILANS PRZYCHODOW Z TEGO MIESIACA <<<" << endl;
        incomeMeneger -> showIncomesForThisMonth();
        cout << "Suma przychodow w tym miesiacu wynosi: " << incomeMeneger -> downloadIncomesSum() << endl;
        cout << "---------------------------------------" << endl;
        cout << ">>> BILANS WYDATKOW Z TEGO MIESIACA <<<" << endl;
        expenceMeneger -> showExpencesForThisMonth();
        cout << "Suma wydatkow w tym miesiacu wynosi: " << expenceMeneger -> downloadExpencesSum() << endl;
        cout << "---------------------------------------" << endl;
        cout << "---------------------------------------" << endl;
        cout << "Roznica miedzy przychodami i wydatkami: " << incomeMeneger -> downloadIncomesSum() - expenceMeneger -> downloadExpencesSum() << endl;
        system("pause");
    }
    else
    {
        cout << "Aby dodac adresata nalezy najpierw sie zalogowac "<< endl;
        system("pause");
    }
}
void FinancesApplication::balanceFromLastMonth()
{
    system("cls");
       if (userMeneger.isUserLoged())
    {
        cout << ">>> BILANS PRZYCHODOW Z POPRZEDNIEGO MIESIACA <<<" << endl;
        incomeMeneger -> showIncomesForLastMonth();
        cout << "Suma przychodow w poprzednim miesiacu wynosi: " << incomeMeneger -> downloadIncomesSum() << endl;
        cout << "---------------------------------------" << endl;
        cout << ">>> BILANS WYDATKOW Z POPRZEDNIEGO MIESIACA <<<" << endl;
        expenceMeneger -> showExpencesForLastMonth();
        cout << "Suma wydatkow w poprzednim miesiacu wynosi: " << expenceMeneger -> downloadExpencesSum() << endl;
        cout << "---------------------------------------" << endl;
        cout << "---------------------------------------" << endl;
        cout << "Roznica miedzy przychodami i wydatkami: " << incomeMeneger -> downloadIncomesSum() - expenceMeneger -> downloadExpencesSum() << endl;
        system("pause");
    }
    else
    {
        cout << "Aby dodac adresata nalezy najpierw sie zalogowac "<< endl;
        system("pause");
    }
}
void FinancesApplication::balanceFromSelectedPeroid()
{
    system("cls");
    int date1ForSelectedPeroid, date2ForSelectedPeroid;
       if (userMeneger.isUserLoged())
    {
        cout << "Podaj date w formacie rrrr-mm-dd, od ktorego chcesz zobaczyc bilans: " << endl;
        date1ForSelectedPeroid = timeMeneger.getSelectedData();
        cout << "Podaj date formacie rrrr-mm-dd, do ktorego chcesz zobaczyc bilans: " << endl;
        date2ForSelectedPeroid = timeMeneger.getSelectedData();

        cout << ">>> BILANS PRZYCHODOW Z WYBRANEGO OKRESU <<<" << endl;
        incomeMeneger -> showIncomesForSelectedPeroid(date1ForSelectedPeroid, date2ForSelectedPeroid);
        cout << "Suma przychodow w wybranym okresie wynosi: " << incomeMeneger -> downloadIncomesSum() << endl;
        cout << "---------------------------------------" << endl;
        cout << ">>> BILANS WYDATKOW Z WYBRANEGO OKRESU <<<" << endl;
        expenceMeneger -> showExpencesForSelectedPeroid(date1ForSelectedPeroid, date2ForSelectedPeroid);
        cout << "Suma wydatkow w wybranym okresie wynosi: " << expenceMeneger -> downloadExpencesSum() << endl;
        cout << "---------------------------------------" << endl;
        cout << "---------------------------------------" << endl;
        cout << "Roznica miedzy przychodami i wydatkami: " << incomeMeneger -> downloadIncomesSum() - expenceMeneger -> downloadExpencesSum() << endl;
        system("pause");
    }
    else
    {
        cout << "Aby dodac adresata nalezy najpierw sie zalogowac "<< endl;
        system("pause");
    }
}
