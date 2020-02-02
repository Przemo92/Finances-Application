#ifndef EXPENCEMENEGER_H
#define EXPENCEMENEGER_H
#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Expence.h"
#include "ExpenceFile.h"
#include "AuxiliaryMethods.h"

using namespace std;

class ExpenceMeneger
{
    const int ID_LOGED_USER;
    //vector <Adresat> adresaci;

    ExpenceFile expenceFile;
    AuxiliaryMethods auxiliaryMethods;

   // Adresat podajDaneNowegoAdresata();
   // void wyswietlDaneAdresata(Adresat adresat);
    //int podajIdWybranegoAdresata();
   // char wybierzOpcjeZMenuEdycja();
   // void zaktualizujDaneWybranegoAdresata(Adresat adresat);

public:
    ExpenceMeneger (string nameFileWithExpences, int idLogedUser)
    :expenceFile(nameFileWithExpences), ID_LOGED_USER(idLogedUser)
     {
     //adresaci = plikZAdresatami.wczytajAdresatowZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
      };
     // void dodajAdresata();
     // void wyswietlWszystkichAdresatow();
     // void usunAdresata();
     // void edytujAdresata();

};
#endif
