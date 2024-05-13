#include "bank_account.h"

Bank_account::Bank_account()
{

}

void Bank_account::SetName(long long number){

    QString number_str = QString::number(number);
    number_str = number_str.rightJustified(9,'0');


    QString result;

    result += "96251";

    QString temp = number_str.mid(3, 6);


    QString temp_16 = QString::number((temp.toInt() + 999) * 5,16);

    result += temp_16.toUpper();
    result += '-';

    QString temp_start = number_str.mid(0,3);

    QString temp_start_16 = QString::number(temp_start.toInt() * 5,16);

    result += temp_start_16.toLower();

    result += "G";

    result = result.leftJustified(18,'0');

    name = result;

}

long long Bank_account::Get_acc_number(QString acc_number){
    long long result = -1;


    acc_number.remove(0,5);

    QString first_part;
    QString second_part;

    int index_of_first_separator = acc_number.indexOf('-');

    first_part = acc_number.mid(0,index_of_first_separator);

    int index_of_second_separator = acc_number.indexOf('G');

    second_part = acc_number.mid(index_of_first_separator + 1, index_of_second_separator - index_of_first_separator - 1);


    int first_number = first_part.toInt(nullptr,16) / 5 - 999;
    int second_number = second_part.toInt(nullptr,16) / 5;

    result = second_number * 1000000 + first_number;


    return result;
}

void Bank_account::SetMoney(long double number){
    money = number;
}

void Bank_account::Minus_money(long long number){
    money -= number;
}

void Bank_account::Plus_money(long long number){
    money += number;
}

long long Bank_account::Get_current_money(){
    return money;
}

QString Bank_account::GetName(){
    return name;
}
