#ifndef CARD_H
#define CARD_H

#include <QGraphicsRectItem>
#include <QString>
#include <QRandomGenerator>

#include "luna.h"
#include "bank_account.h"

class Card : public QGraphicsRectItem
{
private:

    QString card_number;
    Bank_account bank_account;

    QString pin;

    QString month;
    QString year;

    QString cvv;

    void create_card_number(long long );

    void create_cvv();


public:
    void create_bank_account();

    Card(QGraphicsItem* parent = nullptr);


    void Create_card(long long);
    void add_card_to_scene();



};

#endif // CARD_H
