#ifndef INCOMEFILE_H
#define INCOMEFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>


#include "Income.h"
#include "AuxiliaryMethods.h"

using namespace std;

class IncomeFile
{
    const string NAME_FILE_WITH_INCOMES;
    //int idOstatniegoAdresata;
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
        //idOstatniegoAdresata = 0;
    };
   // bool dopiszAdresataDoPliku(Adresat adresat);
    //vector <Adresat> wczytajAdresatowZPliku(int idZalogowanegoUzytkownika);
    //int pobierzIdOstatniegoAdresata();
    //void usunWybranegoAdresataZPliku(int idAdresata);
    //void edytujWybranegoAdresataWPliku(Adresat adresat);

};
#endif
