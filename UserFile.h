#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>
#include <vector>

#include "User.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UserFile
{
    AuxiliaryMethods auxiliaryMethods;
    CMarkup xml;
    const string NAME_FILE_WITH_USERS;

public:
    UserFile(string nameFileWithUsers)
        : NAME_FILE_WITH_USERS(nameFileWithUsers){};

    void addUserToFile(User user);
    vector <User> downloadUsersFormFile();
    void changePassword(int idLogedUser, string newPassword);

};
#endif
