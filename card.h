#ifndef CARD_H
#define CARD_H

#include <QString>
#include <QRandomGenerator>
#include <QDate>


#include "luna.h"
#include "bank_account.h"

class Card
{
private:

    QString card_number;
    Bank_account* bank_account;

    QString pin;

    QString month;
    QString year;

    QString cvv;

    void create_card_number(long long, QString);

    void create_cvv();

    void create_pin();

    void create_date();

    void create_bank_account(long long);

public:

    Card();

    void Create_Mastercard_card(long long);
    void Create_Visa_card(long long);

    void Set_money_to_bank_account(long long);
    void Minus_money_from_bank_account(long long);
    void Plus_money_to_bank_account(long long);

    long double Get_current_money();

    QString GetCardNumber();
    QString GetPin();
    QString GetCvv();
    QString GetMonth();
    QString GetYear();

    long long GetMoney();
    QString Get_banking_app_name();

    Bank_account* Get_bank_account();


};

#endif // CARD_H
