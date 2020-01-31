#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User
{
    int id;
    string login, password;

public:
    void setId(int newId);
    void setLogin(string newLogin);
    void setPassword (string newPassword);

    int downloadId();
    string downloadLogin();
    string downloadPassword();
};
#endif
