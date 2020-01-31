#include "UserMeneger.h"

void UserMeneger::userRegistration()
{
    User user = setDataForNewUser();

    users.push_back(user);

    //plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

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
