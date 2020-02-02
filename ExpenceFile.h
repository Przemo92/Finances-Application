#ifndef EXPENCEFILE_H
#define EXPENCEFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>


#include "Expence.h"
#include "AuxiliaryMethods.h"

using namespace std;

class ExpenceFile
{
    const string NAME_FILE_WITH_EXPENCES;
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
    ExpenceFile(string nameFileWithExpences) : NAME_FILE_WITH_EXPENCES (nameFileWithExpences)
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
