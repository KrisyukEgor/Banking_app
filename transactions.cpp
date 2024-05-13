#include "transactions.h"

extern Bank_meneger& meneger;

Transactions::Transactions()
{

}

int Transactions::Transfer_money_from_card_to_card(QString from_card_number, long long money, QString to_card_number){

    Bank_account* from_acc = meneger.Get_account_from_card(from_card_number);

    Bank_account* to_acc = meneger.Get_account_from_card(to_card_number);

    int result = do_transaction(from_acc, money, to_acc);

    return result;

}

int Transactions::Transfer_money_from_card_to_banking_acc(QString from_card_number, long long money, QString banking_acc_number){

    Bank_account* from_acc = meneger.Get_account_from_card(from_card_number);
    Bank_account* to_acc = meneger.Get_banking_acc(banking_acc_number);

    int result = do_transaction(from_acc, money, to_acc);

    return result;
}

int Transactions::Transfer_money_from_banking_app_to_card(QString banking_acc_number, long long money, QString to_card_number){

    Bank_account* from_acc = meneger.Get_banking_acc(banking_acc_number);

    Bank_account* to_acc = meneger.Get_account_from_card(to_card_number);

    int result = do_transaction(from_acc, money, to_acc);

    return result;
}

int Transactions::Transfer_money_from_banking_app_to_banking_app(QString from_banking_acc_number, long long money, QString to_banking_acc_number){

    Bank_account* from_acc = meneger.Get_banking_acc(from_banking_acc_number);

    Bank_account* to_acc = meneger.Get_banking_acc(to_banking_acc_number);

    int result = do_transaction(from_acc, money, to_acc);

    return result;
}


int Transactions::do_transaction(Bank_account* from_acc, long long money, Bank_account* to_acc){

    int result = 0;

    if(from_acc -> Get_current_money() < money){
        return 2;
    }

    long long current_money = to_acc -> Get_current_money();


    current_money += money;

    to_acc -> Plus_money(money);
    from_acc -> Minus_money(money);


    if(current_money != to_acc -> Get_current_money()){
        result = 1;
        to_acc -> Minus_money(money);
        from_acc -> Plus_money(money);
    }

    return result;
}
