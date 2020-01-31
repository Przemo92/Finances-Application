#include "FinancesApplication.h"


void FinancesApplication::mainMenu()
{
      while (true)
    {
        //if (!uzytkownikMeneger.czyUzytkownikJestZalogowany())
        //{
            chooseFromMainMenu();

            switch (choose)
            {
            case '1':
                userRegistration();
                break;
            case '2':
                //logowanieUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        //}
        /*else
        {
            wybierzOpcjeZMenuUzytkownika();

            switch (wybor)
            {
            case '1':
                dodajAdresata();
                break;
            case '2':
                //wyszukajAdresatowPoImieniu(adresaci);
                break;
            case '3':
               // wyszukajAdresatowPoNazwisku(adresaci);
                break;
            case '4':
                wyswietlWszystkichAdresatow();
                break;
            case '5':
                 usunAdresata();
                break;
            case '6':
                edytujAdresata();
                break;
            case '7':
                zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
                wylogowanieUzytkownika();
                cout << endl << "WYLOGOWANO" << endl;
                system("pause");
                break;
            }
        }*/
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
