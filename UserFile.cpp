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
    bool isNextDataExist = false;
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
            cout<< user.downloadId() <<endl;
            xml.FindElem();//userLogin
            user.setLogin(xml.GetData());
            cout<< user.downloadLogin() <<endl;
            xml.FindElem();//userPassword
            user.setPassword(xml.GetData());
            cout<< user.downloadPassword() <<endl;
            xml.OutOfElem();
            users.push_back(user);
            isNextDataExist = xml.FindElem();
        }while(isNextDataExist==true);
    }
    else
    {
        cout << "Nie wczytalo pliku";
        system("pause");
    }
    return users;
}
