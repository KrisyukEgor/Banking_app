#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <QString>
#include <QDebug>


class Bank_account
{
private:
    QString name;
    long long money = 0;

public:
    Bank_account();
    void SetName(QString );
    void SetMoney(long long);

};

#endif // BANK_ACCOUNT_H
