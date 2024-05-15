#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include "card.h"
#include "bank_meneger.h"
#include <QString>
#include <QMessageBox>
\
class Transactions
{
private :
    static int do_transaction(Bank_account*, long long, Bank_account*);
public:
    Transactions();

    static int Transfer_money_from_card_to_card(QString , long long, QString);
    static int Transfer_money_from_card_to_banking_acc(QString, long long, QString);
    static int Transfer_money_from_banking_app_to_card(QString, long long, QString);
    static int Transfer_money_from_banking_app_to_banking_app(QString, long long, QString);
};

#endif // TRANSACTIONS_H
