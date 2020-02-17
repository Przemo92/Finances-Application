#include "Finance.h"

void Finance::setId(int newId)
{
    if (newId >= 0)
        id = newId;
}
void Finance::setUserId(int newUserId)
{
    if (newUserId >= 0)
        userId = newUserId;
}
void Finance::setDate(int newDate)
{
    if (newDate >= 20000101)
        date = newDate;
}
void Finance::setItem(string newItem)
{
    item = newItem;
}
void Finance::setMoney(float newMoney)
{
    money = newMoney;
}

int Finance::downloadId()
{
    return id;
}
int Finance::downloadUserId()
{
    return userId;
}
int Finance::downloadDate()
{
    return date;
}
string Finance::downloadItem()
{
    return item;
}
float Finance::downloadMoney()
{
    return money;
}
