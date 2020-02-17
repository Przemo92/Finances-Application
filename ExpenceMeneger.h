#ifndef EXPENCEMENEGER_H
#define EXPENCEMENEGER_H
#include <iostream>
#include <vector>

#include "Expence.h"
#include "ExpenceFile.h"
#include "AuxiliaryMethods.h"
#include "TimeMeneger.h"

using namespace std;

class ExpenceMeneger : public TimeMeneger
{
    const int ID_LOGED_USER;
    vector <Expence> expences;
    float expencesSum;
    struct less_than_date
    {
        inline bool operator() (Expence& expence1, Expence& expence2)
        {
            return (expence1.downloadDate() < expence2.downloadDate());
        }
    };

    ExpenceFile expenceFile;
    AuxiliaryMethods auxiliaryMethods;

    Expence writeNewExpence();
    void showSortedExpences (vector <Expence> sortedExpences);

public:
    ExpenceMeneger (string nameFileWithExpences, int idLogedUser)
    :expenceFile(nameFileWithExpences), ID_LOGED_USER(idLogedUser)
     {
     expences = expenceFile.downloadExpencesFormFile(ID_LOGED_USER);
      };
     void addExpence();
     float downloadExpencesSum();
     void showExpencesForThisMonth();
     void showExpencesForLastMonth();
     void showExpencesForSelectedPeroid();
};
#endif
