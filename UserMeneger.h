#ifndef USERMENEGER_H
#define USERMENEGER_H
#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"
#include "UserFile.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UserMeneger
{
    vector <User> users;
    //int idZalogowanegoUzytkownika;

    AuxiliaryMethods auxiliaryMethods;
    //UserFile userFile;

    User setDataForNewUser();
    int downloadUserNewId();
    bool isLoginExist(string login);
    //Uzytkownik podajDaneNowegoUzytkownika();
    //int pobierzIdNowegoUzytkownika();
   // bool czyIstniejeLogin(string login);


public:
    /*UzytkownikMeneger(string nazwaPlikuZUzytkownikami) :plikZUzytkownikami(nazwaPlikuZUzytkownikami)
    {
        idZalogowanegoUzytkownika = 0;
        uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
    };
    void rejestracjaUzytkownika();
    void logowanieUzytkownika();
    void wypiszWszystkichUzytkownikow();//to jest niepotrzebne
    int pobierzIdZalogowanegoUzytkownika();
    bool czyUzytkownikJestZalogowany();
    void wylogowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();*/
    void userRegistration();
};
#endif
