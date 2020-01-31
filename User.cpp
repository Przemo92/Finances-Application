#include <iostream>
#include "User.h"

void User::setId(int newId)
{
    if (newId >= 0)
        id = newId;
}
void User::setLogin(string newLogin)
{
    login = newLogin;
}
void User::setPassword (string newPassword)
{
    password = newPassword;
}

int User::downloadId()
{
    return id;
}
string User::downloadLogin()
{
    return login;
}
string User::downloadPassword()
{
    return password;
}
