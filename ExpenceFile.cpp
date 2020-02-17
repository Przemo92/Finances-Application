#include "ExpenceFile.h"

int ExpenceFile::loadIdLastExpence()
{
    return idLastExpence;
}
vector <Expence> ExpenceFile::downloadExpencesFormFile(int idLogedUser)
{
    Expence expence;
    vector <Expence> expences;
    bool isNextDataExist = false;
    bool fileExists = xml.Load(NAME_FILE_WITH_EXPENCES);
    if (fileExists)
    {
        xml.FindElem(); //Expences
        xml.IntoElem();
        xml.FindElem();//Expence
        do
        {
            xml.IntoElem();
            xml.FindElem();//expenceId
            expence.setId(auxiliaryMethods.changeStringIntoInt(xml.GetData()));
            //cout<< expence.downloadId() <<endl;
            xml.FindElem();//userId
            expence.setUserId(auxiliaryMethods.changeStringIntoInt(xml.GetData()));
            //cout<< expence.downloadUserId() <<endl;
            xml.FindElem();//date
            expence.setDate(auxiliaryMethods.changeStringIntoInt(xml.GetData()));
            //cout<< expence.downloadDate() <<endl;
            xml.FindElem();//item
            expence.setItem(xml.GetData());
            //cout<< expence.downloadItem() <<endl;
            xml.FindElem();//money
            expence.setMoney(atof(xml.GetData().c_str()));
            //cout<< expence.downloadMoney() <<endl;
            xml.OutOfElem();
            expences.push_back(expence);
            isNextDataExist = xml.FindElem();
        }while(isNextDataExist==true);
        idLastExpence = expence.downloadId();
    }
    else
    {
        cout << "Nie wczytalo pliku";
        system("pause");
    }
    return expences;
}
bool ExpenceFile::addExpenceToFile (Expence expence)
{
    bool fileExists = xml.Load(NAME_FILE_WITH_EXPENCES);

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expences");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expence");
    xml.IntoElem();
    xml.AddElem("expenceId", auxiliaryMethods.changeIntIntoString(expence.downloadId()));
    xml.AddElem("userId", auxiliaryMethods.changeIntIntoString(expence.downloadUserId()));
    xml.AddElem("date", auxiliaryMethods.changeIntIntoString(expence.downloadDate()));
    xml.AddElem("item", expence.downloadItem());
    xml.AddElem("money", auxiliaryMethods.changeFloatToString(expence.downloadMoney()));

    xml.Save(NAME_FILE_WITH_EXPENCES);
    idLastExpence++;

    return true;
}
