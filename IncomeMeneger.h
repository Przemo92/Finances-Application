#ifndef INCOMEMENEGER_H
#define INCOMEMENEGER_H
#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Income.h"
#include "IncomeFile.h"
#include "AuxiliaryMethods.h"

using namespace std;

class IncomeMeneger
{
    const int ID_LOGED_USER;
    //vector <Adresat> adresaci;

    IncomeFile incomeFile;
    AuxiliaryMethods auxiliaryMethods;

   // Adresat podajDaneNowegoAdresata();
   // void wyswietlDaneAdresata(Adresat adresat);
    //int podajIdWybranegoAdresata();
   // char wybierzOpcjeZMenuEdycja();
   // void zaktualizujDaneWybranegoAdresata(Adresat adresat);

public:
    IncomeMeneger (string nameFileWithIncomes, int idLogedUser)
    :incomeFile(nameFileWithIncomes), ID_LOGED_USER(idLogedUser)
     {
     //adresaci = plikZAdresatami.wczytajAdresatowZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
      };
     // void dodajAdresata();
     // void wyswietlWszystkichAdresatow();
     // void usunAdresata();
     // void edytujAdresata();

};
#endif
