#include "ExpenceMeneger.h"

void ExpenceMeneger::addExpence()
{
    Expence expence;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO WYDATKU<<<" << endl << endl;
    expence = writeNewExpence();
    expences.push_back(expence);

    if (expenceFile.addExpenceToFile(expence))
        cout << "Nowy wydatek zostal dodany" << endl;
    else
        cout << "Blad nie udalo sie dodac nowego wydatku do pliku" << endl;
    system("pause");
}
Expence ExpenceMeneger::writeNewExpence()
{
    Expence expence;
    char choose;
    string textDate;

    expence.setId(expenceFile.loadIdLastExpence() +1);
    expence.setUserId(ID_LOGED_USER);

    cout << "Czy wydatek pochodzi z dzsiejszego dnia? (t/n)" <<endl;
    while (true)
    {
        choose = auxiliaryMethods.getSign();
        if (choose == 't')
        {
            expence.setDate(auxiliaryMethods.changeStringIntoInt(getTodaysDate()));
            break;
        }
        else if (choose == 'n')
        {
            cout << "Podaj date dla nowego wydatku w formacie rrrr-mm-dd" <<endl;
            textDate = auxiliaryMethods.loadLinie();
            if (isCorrectDate(textDate) == true)
            {
                expence.setDate(changeTextDateToInteger(textDate));
                break;
            }
            else
            cout << "Wpisales blednie date. Czy nadal chcesz skorzystac z dzsiejszej daty? (t/n)" << endl;
        }
        else
        {
            cout << "Wprowadziles zly znak. Wpisz ponownie" << endl;
            system("pause");
        }
    }
    cout << "Podaj nazwe wydatku: ";
    expence.setItem(auxiliaryMethods.loadLinie());

    cout << "Podaj wartosc/wysokosc wydatku: ";
    expence.setMoney(auxiliaryMethods.downloadFloatNumber());

    return expence;
}
void ExpenceMeneger::showExpencesForThisMonth()
{
    expencesSum = 0;
    vector <Expence> sortedExpences;
    for (int i=0; i < expences.size(); i++)
    {
        if (getMonthWithYear(auxiliaryMethods.changeIntIntoString(expences[i].downloadDate())) == getMonthWithYear(getTodaysDate()))
        {
        sortedExpences.push_back(expences[i]);

            expencesSum += expences[i].downloadMoney();
        }
    }
    sort(sortedExpences.begin(), sortedExpences.end(), less_than_date());
    showSortedExpences (sortedExpences);
}
float ExpenceMeneger::downloadExpencesSum()
{
    return expencesSum;
}
void ExpenceMeneger::showExpencesForLastMonth()
{
    expencesSum = 0;
    vector <Expence> sortedExpences;
    for (int i=0; i < expences.size(); i++)
    {
        if (getMonthWithYear(auxiliaryMethods.changeIntIntoString(expences[i].downloadDate())) == getMonthWithYear(getLastMonthWithYear()))
        {
        sortedExpences.push_back(expences[i]);

            expencesSum += expences[i].downloadMoney();
        }
    }
    sort(sortedExpences.begin(), sortedExpences.end(), less_than_date());
    showSortedExpences (sortedExpences);
}
void ExpenceMeneger::showExpencesForSelectedPeroid()
{
    expencesSum = 0;
    vector <Expence> sortedExpences;

    for (int i=0; i < expences.size(); i++)
    {
       if (expences[i].downloadDate() <= getDate2ForSelectedPeroid() && expences[i].downloadDate() >= getDate1ForSelectedPeroid())
        {
        sortedExpences.push_back(expences[i]);

            expencesSum += expences[i].downloadMoney();
        }
    }
       sort(sortedExpences.begin(), sortedExpences.end(), less_than_date());
        showSortedExpences (sortedExpences);


}
void ExpenceMeneger::showSortedExpences (vector <Expence> sortedExpences)
{
   for (int i=0; i < sortedExpences.size(); i++)
    {
            cout << "Numer ID wydatku: "      << sortedExpences[i].downloadId() << endl;
            cout << "Numer ID uzytkownika: "    << sortedExpences[i].downloadUserId() << endl;
            cout << "Data: "                    << changeIntDateIntoString(sortedExpences[i].downloadDate()) << endl;
            cout << "Nazwa wydatku: "         << sortedExpences[i].downloadItem() << endl;
            cout << "Wielkosc wydatku: "      << sortedExpences[i].downloadMoney() << endl;
            cout << "---------------------------------" << endl;
    }
}
