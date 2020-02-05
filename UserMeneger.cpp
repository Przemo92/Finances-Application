#include "UserMeneger.h"

void UserMeneger::userRegistration()
{
    User user = setDataForNewUser();

    users.push_back(user);

    userFile.addUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}
User UserMeneger::setDataForNewUser()
{
    User user;

    user.setId(downloadUserNewId());

    string login;
    do
    {
        cout << "Podaj login: ";
        cin >> login;
        user.setLogin(login);
    }
    while (isLoginExist(user.downloadLogin()) == true);
    string password;
    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password);

    return user;
}
int UserMeneger::downloadUserNewId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().downloadId() + 1;
}
bool UserMeneger::isLoginExist(string login)
{
    for (int i=0; i < users.size(); i++)
    {
        if (users[i].downloadLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}
void UserMeneger::userLogin()
{
    User user;
    string login = "", haslo = "";

    cout << endl << "Podaj login: ";
    login = auxiliaryMethods.loadLinie();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> downloadLogin() == login)
        {
            for (int numberOfChance = 3; numberOfChance > 0; numberOfChance--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << numberOfChance << ": ";
                haslo = auxiliaryMethods.loadLinie();

                if (itr -> downloadPassword() == haslo)
                {
                    idLogedUser = itr -> downloadId();
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
}
bool UserMeneger::isUserLoged()
{
    if (idLogedUser > 0)
        return true;
    else
        return false;
}
int UserMeneger::getIdLogedUser()
{
    return idLogedUser;
}
void UserMeneger::userLogout()
{
    idLogedUser = 0;
}
void UserMeneger::changePasswordLogedUser()
{
    if (idLogedUser > 0)
    {
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = auxiliaryMethods.loadLinie();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr -> downloadId() == idLogedUser)
        {
            itr -> setPassword (newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    //plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
    }
    else
    {
      cout << "Aby zmienic haslo, nalezy najpierw sie zalogowac" << endl;
      system("pause");
    }
}
