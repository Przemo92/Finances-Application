#include "Expence.h"

void Expence::setId(int newId)
{
    if (newId >= 0)
        id = newId;
}
void Expence::setUserId(int newUserId)
{
    if (newUserId >= 0)
        userId = newUserId;
}
void Expence::setDate(int newDate)
{
    if (newDate >= 20000101)
        date = newDate;
}
void Expence::setItem(string newItem)
{
    item = newItem;
}
void Expence::setMoney(float newMoney)
{
    money = newMoney;
}

int Expence::downloadId()
{
    return id;
}
int Expence::downloadUserId()
{
    return userId;
}
int Expence::downloadDate()
{
    return date;
}
string Expence::downloadItem()
{
    return item;
}
float Expence::downloadMoney()
{
    return money;
}
