#include "card.h"

Card::Card(QGraphicsItem* parent) : QGraphicsRectItem(parent)
{

}

void Card::add_card_to_scene(){

    setRect(0,0,300,150);
}

void Card::Create_card(long long card_number){

    create_card_number(card_number);
    this -> card_number = "9999 4399 9999 9999";
    //99999998967F705033179

    create_bank_account();
}

void Card::create_card_number(long long temp_number) {
    QString number;

    number.append("5"); //Mastercard
    number.append("1");

    number.append("5269");

    number.append(QString::number(temp_number).rightJustified(9,'0'));

    number.append(Luna::GetNumber(number));

    number.insert(4," ");
    number.insert(9," ");
    number.insert(14," ");

    card_number = number;

    qDebug() << card_number;

}

void Card::create_bank_account(){

    qDebug() << card_number;
    bank_account.SetName(card_number);

}


void Card::create_cvv(){
    cvv = QString::number(QRandomGenerator::global() -> bounded(1,999)).rightJustified(3,'0');
    qDebug() << cvv;
}
