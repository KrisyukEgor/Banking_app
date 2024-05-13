#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <QString>
#include <QDebug>


class Bank_account
{
private:
    QString name;
    long double money;

public:
    Bank_account();

    void SetName(long long);
    static long long Get_acc_number(QString);

    void SetMoney(long double);
    void Minus_money(long long);
    void Plus_money(long long);

    long long Get_current_money();
    QString GetName();

};

#endif // BANK_ACCOUNT_H
