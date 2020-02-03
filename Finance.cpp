#include "Finance.h"

int Finance::getTodaysDate()
{
    time_t moment;
    struct tm * data;
    char hour[ 80 ];
    string date;

    time( & moment );
    data = localtime( & moment );

    strftime( hour, 80, "%Y%m%d", data );
    cout << hour << endl;

    for (int i=0; i < 6; i++)
        date += hour[i];
    return auxiliaryMethods.changeStringIntoInt(date);
}
int Finance::changeTextDateToInteger(string textDate)
{
    string date = "";
    for(int i=0; i<textDate.length(); i++)
    {
        if(textDate[i] != '-')
            date += textDate[i];
    }
    cout << date;
    return auxiliaryMethods.changeStringIntoInt(date);
}
