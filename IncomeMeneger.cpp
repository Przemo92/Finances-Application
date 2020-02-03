#include "IncomeMeneger.h"

void IncomeMeneger::addIncome()
{
    Income income;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU<<<" << endl << endl;
    income = writeNewIncome();

    /*adresaci.push_back(adresat);
    if (plikZAdresatami.dopiszAdresataDoPliku(adresat))
        cout << "Nowy adresat zostal dodany" << endl;
    else
        cout << "Blad nie udalo sie dodac nowego adresata do pliku" << endl;
    system("pause");*/
}
Income IncomeMeneger::writeNewIncome()
{
    Income income;
    char choose;
    string textDate;

    //income.setId ( (plikZAdresatami.pobierzIdOstatniegoAdresata() +1) );
    income.setUserId(ID_LOGED_USER);

    cout << "Czy przychod pochodzi z dzsiejszego dnia? (t/n)" <<endl;
    while (true)
    {
        choose = auxiliaryMethods.getSign();
        if (choose == 't')
        {
            income.setDate(Finance::getTodaysDate());
            break;
        }
        else if (choose == 'n')
        {
            cout << "Podaj date dla nowego przychodu w formacie rrrr-mm-dd" <<endl;
            textDate = auxiliaryMethods.loadLinie();
            income.setDate(Finance::changeTextDateToInteger(textDate));

            break;
        }
        else
        {
            cout << "Wprowadziles zly znak. Wpisz ponownie" << endl;
            system("pause");
        }
    }
    cout << "Podaj nazwe przychodu: ";
    income.setItem(auxiliaryMethods.loadLinie());

    cout << "Podaj wartosc/wysokosc przychodu: ";
    income.setMoney(auxiliaryMethods.downloadDoubleNumber());

    return income;
}
