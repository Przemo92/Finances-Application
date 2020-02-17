#include "IncomeMeneger.h"

void IncomeMeneger::addIncome()
{
    Income income;

    cout << " >>> DODAWANIE NOWEGO PRZYCHODU<<<" << endl << endl;
    income = writeNewIncome();
    incomes.push_back(income);

    if (incomeFile.addIncomeToFile(income))
        cout << "Nowy przychod zostal dodany" << endl;
    else
        cout << "Blad nie udalo sie dodac nowego przychodu do pliku" << endl;
    system("pause");
}
Income IncomeMeneger::writeNewIncome()
{
    Income income;
    char choose;
    string textDate;

    income.setId(incomeFile.loadIdLastIncome() +1);
    income.setUserId(ID_LOGED_USER);

    cout << "Czy przychod pochodzi z dzsiejszego dnia? (t/n)" <<endl;
    while (true)
    {
        choose = auxiliaryMethods.getSign();
        if (choose == 't')
        {
            income.setDate(auxiliaryMethods.changeStringIntoInt(getTodaysDate()));
            break;
        }
        else if (choose == 'n')
        {
            cout << "Podaj date dla nowego przychodu w formacie rrrr-mm-dd" <<endl;
            textDate = auxiliaryMethods.loadLinie();
            if (isCorrectDate(textDate) == true)
            {
                income.setDate(changeTextDateToInteger(textDate));
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
    cout << "Podaj nazwe przychodu: ";
    income.setItem(auxiliaryMethods.loadLinie());

    cout << "Podaj wartosc/wysokosc przychodu: ";
    income.setMoney(auxiliaryMethods.downloadFloatNumber());

    return income;
}
void IncomeMeneger::showIncomesForThisMonth()
{
    incomesSum = 0;
    vector <Income> sortedIncomes;
    for (int i=0; i < incomes.size(); i++)
    {
        if (getMonthWithYear(auxiliaryMethods.changeIntIntoString(incomes[i].downloadDate())) == getMonthWithYear(getTodaysDate()))
        {
        sortedIncomes.push_back(incomes[i]);

            incomesSum += incomes[i].downloadMoney();
        }
    }
    sort(sortedIncomes.begin(), sortedIncomes.end(), less_than_date());
    showSortedIncomes(sortedIncomes);
}
float IncomeMeneger::downloadIncomesSum()
{
    return incomesSum;
}
void IncomeMeneger::showIncomesForLastMonth()
{
    incomesSum = 0;
    vector <Income> sortedIncomes;
    for (int i=0; i < incomes.size(); i++)
    {
        if (getMonthWithYear(auxiliaryMethods.changeIntIntoString(incomes[i].downloadDate())) == getMonthWithYear(getLastMonthWithYear()))
        {
        sortedIncomes.push_back(incomes[i]);

            incomesSum += incomes[i].downloadMoney();
        }
    }
    if (getDate2ForSelectedPeroid() >= getDate1ForSelectedPeroid())
    {
       sort(sortedIncomes.begin(), sortedIncomes.end(), less_than_date());
    showSortedIncomes(sortedIncomes);
    }
    else
        cout << "Podales bledna kolejnosc dat." << endl;
}
void IncomeMeneger::showIncomesForSelectedPeroid()
{
    incomesSum = 0;
    vector <Income> sortedIncomes;
    cout << "Podaj date w formacie rrrr-mm-dd, od ktorego chcesz zobaczyc bilans: " << endl;
    setDate1ForSelectedPeroid(getSelectedData());
    cout << "Podaj date formacie rrrr-mm-dd, do ktorego chcesz zobaczyc bilans: " << endl;
    setDate2ForSelectedPeroid(getSelectedData());

    for (int i=0; i < incomes.size(); i++)
    {
        if (incomes[i].downloadDate() <= getDate2ForSelectedPeroid() && incomes[i].downloadDate() >= getDate1ForSelectedPeroid())
        {
        sortedIncomes.push_back(incomes[i]);

            incomesSum += incomes[i].downloadMoney();
        }
    }
    sort(sortedIncomes.begin(), sortedIncomes.end(), less_than_date());
    showSortedIncomes(sortedIncomes);
}
void IncomeMeneger::showSortedIncomes (vector <Income> sortedIncomes)
{
   for (int i=0; i < sortedIncomes.size(); i++)
    {
            cout << "Numer ID przychodu: "      << sortedIncomes[i].downloadId() << endl;
            cout << "Numer ID uzytkownika: "    << sortedIncomes[i].downloadUserId() << endl;
            cout << "Data: "                    << changeIntDateIntoString(sortedIncomes[i].downloadDate()) << endl;
            cout << "Nazwa przychodu: "         << sortedIncomes[i].downloadItem() << endl;
            cout << "Wielkosc przychodu: "      << sortedIncomes[i].downloadMoney() << endl;
            cout << "---------------------------------" << endl;
    }
}
