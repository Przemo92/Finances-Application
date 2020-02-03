#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income
{
    int id, userId, date;
    string item;
    double money;

public:
    void setId(int newId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setMoney(double newMoney);


    int downloadId();
    int downloadUserId();
    int downloadDate();
    string downloadItem();
    double downloadMoney();
};
#endif
