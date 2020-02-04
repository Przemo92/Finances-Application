#ifndef INCOMEFILE_H
#define INCOMEFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>


#include "Income.h"
#include "AuxiliaryMethods.h"
#include "Markup.h"

using namespace std;

class IncomeFile
{
    const string NAME_FILE_WITH_INCOMES;
    int idLastIncome;
    CMarkup xml;
    //string nazwaTymczasowegoPlikuZAdresatami = "Adresaci_tymczasowo.txt";
    AuxiliaryMethods auxiliaryMethods;

    //bool czyPlikJestPusty(fstream &plikTekstowy);
    //string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    //Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    //int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    //int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    //int pobierzZPlikuIdOstatniegoAdresata();
    //void usunPlik(string nazwaPlikuZRozszerzeniem);
    //void zmienNazwePliku(string staraNazwa, string nowaNazwa);

public:
    IncomeFile(string nameFileWithIncomes) : NAME_FILE_WITH_INCOMES (nameFileWithIncomes)
    {
        idLastIncome = 0;
    };
   // bool dopiszAdresataDoPliku(Adresat adresat);
    //int pobierzIdOstatniegoAdresata();
    //void usunWybranegoAdresataZPliku(int idAdresata);
    //void edytujWybranegoAdresataWPliku(Adresat adresat);
    int loadIdLastIncome();
    bool addIncomeToFile (Income income);
    vector <Income> downloadIncomesFormFile(int idLogedUser);

};
#endif
