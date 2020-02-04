#include "Finance.h"

string Finance::getTodaysDate()
{
    time_t moment;
    struct tm * data;
    char hour[ 80 ];
    string date;

    time( & moment );
    data = localtime( & moment );

    strftime( hour, 80, "%Y%m%d", data );
    //cout << hour << endl;

    for (int i=0; i < 8; i++)
        date += hour[i];
        cout << "Data to: " << date << endl;
    return date;
}
int Finance::changeTextDateToInteger(string textDate)
{
    string date = "";
    for(int i=0; i<textDate.length(); i++)
    {
        if(textDate[i] != '-')
            date += textDate[i];
    }
    return auxiliaryMethods.changeStringIntoInt(date);
}
bool Finance::isCorrectDate (string textDate)
{
    textDate += '-';
    int year;
    int month;
    int day;
    string partOfDate = "";
    int numberOfDateData = 1;

    for (int numberOfSign = 0; numberOfSign < textDate.length(); numberOfSign++)
    {
        if (textDate[numberOfSign] != '-')
        {
            partOfDate += textDate[numberOfSign];
        }
        else
        {
            switch(numberOfDateData)
            {
            case 1:
                year = auxiliaryMethods.changeStringIntoInt(partOfDate);
                break;
            case 2:
                month = auxiliaryMethods.changeStringIntoInt(partOfDate);
                break;
            case 3:
                day = auxiliaryMethods.changeStringIntoInt(partOfDate);
                break;
            }
            partOfDate = "";
            numberOfDateData++;
        }
    }
    if (year <= 2020 && year >= 2000)
    {
        if (month <= 12 && month >= 1)
        {
            if (day <= calculateDaysInMonth(month,year) && day >= 1)
                return true;
        }
    }
    return false;
}

int Finance::calculateDaysInMonth(int monthNumber, int year)
{
    int numberOfDays;
    switch(monthNumber)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        numberOfDays = 31;
        return numberOfDays;
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        numberOfDays = 30;
        return numberOfDays;
        break;

    case 2:
    {
        if (((year % 4) && (year % 100 != 0)) || (year % 400 == 0))
            {
                numberOfDays = 29;
                return numberOfDays;
            }
        else
            numberOfDays = 28;
            return numberOfDays;
        break;
    }
    default:
        cout << "Niepoprawny numer miesiaca";
    }
}
