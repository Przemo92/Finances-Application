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
    int idLogedUser;

    AuxiliaryMethods auxiliaryMethods;
    UserFile userFile;

    User setDataForNewUser();
    int downloadUserNewId();
    bool isLoginExist(string login);

public:
    UserMeneger (string nameFileWithUsers)
    : userFile (nameFileWithUsers)
    {
        idLogedUser = 0;
        users = userFile.downloadUsersFormFile();
    };

    void userRegistration();
    void userLogin();
    bool isUserLoged();
    int getIdLogedUser();
    void userLogout();
    void changePasswordLogedUser();
};
#endif
