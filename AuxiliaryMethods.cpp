#include "AuxiliaryMethods.h"

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
