#include "Income.h"

void Income::setId(int newId)
{
    if (newId >= 0)
        id = newId;
}
void Income::setUserId(int newUserId)
{
    if (newUserId >= 0)
        userId = newUserId;
}
void Income::setDate(int newDate)
{
    if (newDate >= 20000101)
        date = newDate;
}
void Income::setItem(string newItem)
{
    item = newItem;
}
void Income::setMoney(float newMoney)
{
    money = newMoney;
}

int Income::downloadId()
{
    return id;
}
int Income::downloadUserId()
{
    return userId;
}
int Income::downloadDate()
{
    return date;
}
string Income::downloadItem()
{
    return item;
}
float Income::downloadMoney()
{
    return money;
}
