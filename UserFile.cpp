#include "UserFile.h"

void UserFile::addUserToFile(User user)
{
     bool fileExists = xml.Load(NAME_FILE_WITH_USERS);

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", auxiliaryMethods.changeIntIntoString(user.downloadId()));
    xml.AddElem("Login", user.downloadLogin());
    xml.AddElem("Password", user.downloadPassword());

    xml.Save(NAME_FILE_WITH_USERS);

}
vector <User> UserFile::downloadUsersFormFile()
{
    User user;
    vector <User> users;

    bool fileExists = xml.Load(NAME_FILE_WITH_USERS);
    if (fileExists)
    {
        xml.FindElem(); //Users
        xml.IntoElem();
        xml.FindElem();//User
        do
        {
            xml.IntoElem();
            xml.FindElem();//userId
            user.setId(auxiliaryMethods.changeStringIntoInt(xml.GetData()));
            //cout<< user.downloadId() <<endl;
            xml.FindElem();//userLogin
            user.setLogin(xml.GetData());
            //cout<< user.downloadLogin() <<endl;
            xml.FindElem();//userPassword
            user.setPassword(xml.GetData());
            //cout<< user.downloadPassword() <<endl;
            xml.OutOfElem();
            users.push_back(user);

        }while(xml.FindElem());
    }
    else
    {
        cout << "Nie wczytalo pliku";
        system("pause");
    }
    return users;
}
void UserFile::changePassword(int idLogedUser, string newPassword)
{
    User user;

    bool fileExists = xml.Load(NAME_FILE_WITH_USERS);

    if (fileExists)
    {
    xml.FindElem();//Users
    xml.IntoElem();
    xml.FindElem();//User
    do
    {
        xml.IntoElem();
        xml.FindElem();//userId

        if (idLogedUser == auxiliaryMethods.changeStringIntoInt(xml.GetData()))
        {
           xml.FindElem();//login
           xml.FindElem();//password
           xml.RemoveElem();
           xml.AddElem("Password", newPassword);
        }
        xml.OutOfElem();//User)
    }while(xml.FindElem());

    xml.Save(NAME_FILE_WITH_USERS);
    }
    else
    {
        cout << "Nie mozna otworzyc pliku " << NAME_FILE_WITH_USERS << endl;
    }
}
