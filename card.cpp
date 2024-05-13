#include "card.h"

Card::Card()
{

}

void Card::Create_Mastercard_card(long long card_number){

    create_bank_account(card_number);

    create_card_number(card_number, "5");

    create_cvv();
    create_pin();
    create_date();

    bank_account -> SetMoney(10);

}

void Card::Create_Visa_card(long long card_number){

    create_bank_account(card_number);

    create_card_number(card_number, "4");

    create_cvv();
    create_pin();
    create_date();

}

long double Card::Get_current_money(){

    return bank_account -> Get_current_money();
}

void Card::Set_money_to_bank_account(long long money){
    bank_account -> SetMoney(money);
}

void Card::Plus_money_to_bank_account(long long money){
    bank_account -> Plus_money(money);
}

void Card::Minus_money_from_bank_account(long long money){
    bank_account -> Minus_money(money);
}


void Card::create_card_number(long long temp_number, QString first_symbol) {
    QString number;

    number.append(first_symbol);
    number.append("1");

    number.append("5269");

    number.append(QString::number(temp_number).rightJustified(9,'0'));

    number.append(Luna::GetNumber(number));

    number.insert(4," ");
    number.insert(9," ");
    number.insert(14," ");

    card_number = number;
}

void Card::create_bank_account(long long number){

    bank_account = new Bank_account();
    bank_account -> SetName(number);

    bank_account -> Get_acc_number(bank_account -> GetName());

    bank_account -> SetMoney(0);

}

void Card::create_cvv(){
    cvv = QString::number(QRandomGenerator::global() -> bounded(1,999)).rightJustified(3,'0');

}

void Card::create_pin(){
    pin = QString::number(QRandomGenerator::global() -> bounded(1,9999)).rightJustified(4,'0');

}

void Card::create_date(){
    month = QString::number(QDate::currentDate().month()).rightJustified(2,'0');

    year = QString::number(QDate::currentDate().year() + 4).rightJustified(2,'0');
}


QString Card::GetCardNumber(){
    return card_number;
}

QString Card::GetCvv(){
    return cvv;
}

QString Card::GetPin(){
    return pin;
}

QString Card::GetMonth(){
    return month;
}

QString Card::GetYear(){
    return year;
}

long long Card::GetMoney(){
    return bank_account -> Get_current_money();
}

QString Card::Get_banking_app_name(){
    return bank_account -> GetName();
}

Bank_account* Card::Get_bank_account(){
    return bank_account;
}
