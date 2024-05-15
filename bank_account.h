#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <QString>
#include <QDebug>


class Bank_account
{
private:
    QString name;
    double money = 0;

public:
    Bank_account();

    void SetName(long long);
    void SetName(QString);
    static long long Get_acc_number(QString);

    void SetMoney(double);
    void Minus_money(double);
    void Plus_money(double);

    double Get_current_money();
    QString GetName();

};

#endif // BANK_ACCOUNT_H
