#include "IncomeFile.h"

int IncomeFile::loadIdLastIncome()
{
    return idLastIncome;
}
vector <Income> IncomeFile::downloadIncomesFormFile(int idLogedUser)
{
    Income income;
    vector <Income> incomes;
    bool isNextDataExist = false;
    bool fileExists = xml.Load(NAME_FILE_WITH_INCOMES);
    if (fileExists)
    {
        xml.FindElem(); //Incomes
        xml.IntoElem();
        xml.FindElem();//Income
        do
        {
            xml.IntoElem();
            xml.FindElem();//incomeId
            income.setId(auxiliaryMethods.changeStringIntoInt(xml.GetData()));
            //cout<< income.downloadId() <<endl;
            xml.FindElem();//userId
            income.setUserId(auxiliaryMethods.changeStringIntoInt(xml.GetData()));
            //cout<< income.downloadUserId() <<endl;
            xml.FindElem();//date
            income.setDate(auxiliaryMethods.changeStringIntoInt(xml.GetData()));
            //cout<< income.downloadDate() <<endl;
            xml.FindElem();//item
            income.setItem(xml.GetData());
            //cout<< income.downloadItem() <<endl;
            xml.FindElem();//money
            income.setMoney(atof(xml.GetData().c_str()));
            //cout<< income.downloadMoney() <<endl;
            xml.OutOfElem();
            if (idLogedUser == income.downloadUserId())
            {
                incomes.push_back(income);
            }
            isNextDataExist = xml.FindElem();
        }while(isNextDataExist==true);
        idLastIncome = income.downloadId();
    }
    else
    {
        cout << "Nie wczytalo pliku";
        system("pause");
    }
    return incomes;
}
bool IncomeFile::addIncomeToFile (Income income)
{
    bool fileExists = xml.Load(NAME_FILE_WITH_INCOMES);

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("incomeId", auxiliaryMethods.changeIntIntoString(income.downloadId()));
    xml.AddElem("userId", auxiliaryMethods.changeIntIntoString(income.downloadUserId()));
    xml.AddElem("date", auxiliaryMethods.changeIntIntoString(income.downloadDate()));
    xml.AddElem("item", income.downloadItem());
    xml.AddElem("money", auxiliaryMethods.changeFloatToString(income.downloadMoney()));

    xml.Save(NAME_FILE_WITH_INCOMES);
    idLastIncome++;

    return true;
}
