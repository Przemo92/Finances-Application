#ifndef EXPENCEFILE_H
#define EXPENCEFILE_H

#include <iostream>
#include <vector>

#include "Expence.h"
#include "AuxiliaryMethods.h"
#include "Markup.h"

using namespace std;

class ExpenceFile
{
    const string NAME_FILE_WITH_EXPENCES;
    int idLastExpence;
    CMarkup xml;
    AuxiliaryMethods auxiliaryMethods;

public:
    ExpenceFile(string nameFileWithExpences) : NAME_FILE_WITH_EXPENCES (nameFileWithExpences)
    {
        idLastExpence = 0;
    };
    int loadIdLastExpence();
    bool addExpenceToFile (Expence expence);
    vector <Expence> downloadExpencesFormFile(int idLogedUser);

};
#endif
