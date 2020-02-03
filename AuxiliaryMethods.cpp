#include "AuxiliaryMethods.h"

string AuxiliaryMethods::changeIntIntoString (int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
string AuxiliaryMethods::loadLinie()
{
    string inlet = "";
    getline(cin, inlet);
    return inlet;
}
char AuxiliaryMethods::getSign()
{
    string inlet = "";
    char sign  = {0};

    while (true)
    {
        getline(cin, inlet);

        if (inlet.length() == 1)
        {
            sign = inlet[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return sign;
}
int AuxiliaryMethods::changeStringIntoInt(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}
string AuxiliaryMethods::changeFirstLetterIntoCapital(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}
double AuxiliaryMethods::downloadDoubleNumber()
{
    string inlet = "";
    double number = 0;

    while (true)
    {
        getline(cin, inlet);
        for (int i=0; i<inlet.length(); i++)
        {
            if (inlet[i] == ',')
            inlet[i] == '.';
        }
        stringstream myStream(inlet);
        if (myStream >> number)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return number;
}
