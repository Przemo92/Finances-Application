#ifndef FINANCE_H
#define FINANCE_H

#include <iostream>

using namespace std;

class Finance
{
    int id, userId, date;
    string item;
    float money;

public:
    void setId(int newId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setMoney(float newMoney);


    int downloadId();
    int downloadUserId();
    int downloadDate();
    string downloadItem();
    float downloadMoney();
};
#endif
