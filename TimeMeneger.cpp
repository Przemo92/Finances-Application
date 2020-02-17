#include "TimeMeneger.h"

string TimeMeneger::getTodaysDate()
{
    time_t moment;
    struct tm * data;
    char hour[ 80 ];
    string date;

    time( & moment );
    data = localtime( & moment );

    strftime( hour, 80, "%Y%m%d", data );

    for (int i=0; i < 8; i++)
        date += hour[i];
    return date;
}
int TimeMeneger::changeTextDateToInteger(string textDate)
{
    string date = "";
    for(int i=0; i<textDate.length(); i++)
    {
        if(textDate[i] != '-')
            date += textDate[i];
    }
    return auxiliaryMethods.changeStringIntoInt(date);
}
bool TimeMeneger::isCorrectDate (string textDate)
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

int TimeMeneger::calculateDaysInMonth(int monthNumber, int year)
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
int TimeMeneger::getMonthWithYear(string date)
{
    string dateWithoutDay = "";
    int positionNumberOfDate = 6;
    for (int i=0; i<positionNumberOfDate; i++)
    {
        dateWithoutDay += date[i];
    }
    return auxiliaryMethods.changeStringIntoInt(dateWithoutDay);
}
string TimeMeneger::changeIntDateIntoString(int date)
{
    string stringDate;
    string newDate = "";
    stringDate = auxiliaryMethods.changeIntIntoString(date);
    for (int i=0; i<stringDate.length(); i++)
    {
        if (i == 4)
          newDate += '-';

        if (i == 6)
          newDate += '-';

        newDate += stringDate[i];
    }
    return newDate;
}
string TimeMeneger::getLastMonthWithYear()
{
    string dateWithoutDay = "";
    string year;
    string month;
    string date = getTodaysDate();
    string newDate = "";
    int positionNumberOfDate = 6;
    for (int i=0; i<positionNumberOfDate; i++)
    {
        if (i == 4 || i == 5)
            month += date[i];
        else if (i == 0 || i == 1 || i == 2 || i == 3)
            year += date[i];
        dateWithoutDay += date[i];
    }
    if (month == "12")
    {
        month = "01";
        newDate = year + month;
        return newDate;
    }
    else
    {
        int dateNew = auxiliaryMethods.changeStringIntoInt(dateWithoutDay) -1;
        return auxiliaryMethods.changeIntIntoString(dateNew);
    }
}
int TimeMeneger::getSelectedData()
{
    string date = "";
    while (true)
    {
        cin >> date;
        if (isCorrectDate(date))
        {
           return changeTextDateToInteger(date);
        }
        else
            cout << "Podales zle date. Spruboj ponownie" << endl;
    }
}
void TimeMeneger::setDate1ForSelectedPeroid(int date)
{
    date1ForSelectedPeroid = date;
}
void TimeMeneger::setDate2ForSelectedPeroid(int date)
{
    date2ForSelectedPeroid = date;
}
int TimeMeneger::getDate2ForSelectedPeroid()
{
    return date2ForSelectedPeroid;
}
int TimeMeneger::getDate1ForSelectedPeroid()
{
    return date1ForSelectedPeroid;
}
