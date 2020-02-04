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
                //wyszukajAdresatowPoImieniu(adresaci);
                break;
            case '3':
               // wyszukajAdresatowPoNazwisku(adresaci);
                break;
            case '4':
                //wyswietlWszystkichAdresatow();
                break;
            case '5':
                 //usunAdresata();
                break;
            case '6':
                //zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '7':
                //wylogowanieUzytkownika();
                //cout << endl << "WYLOGOWANO" << endl;
                //system("pause");
                break;
            }
        }
    }
}
void FinancesApplication::chooseFromMainMenu()
{
   // system("cls");
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

    //system("cls");
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
