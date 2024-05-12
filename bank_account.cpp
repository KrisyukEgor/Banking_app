#include "bank_account.h"

Bank_account::Bank_account()
{

}

void Bank_account::SetName(QString str){

    str.remove(' ');

    QString result;

    for(int i = 0; i < 6; ++i){
        result.insert(0,str[i]);
    }

    QString temp = str.mid(str.length() - 7, str.length() - 1);

    QString temp_16 = QString::number(temp.toInt(),16);


    QString mid_temp = str.mid(6,9);

    int temp_mid = mid_temp.toInt();

    for(int i = 0; i < 16; ++i){
        temp_mid += 3;
        temp_mid ^= 2;
        temp_mid |= 4;
    }


    temp_mid *= 2;

    result += temp_16.toUpper();
    result += QString::number(temp_mid);


    result = result.leftJustified(22,'0');

    name = result;

}
