#ifndef CARD_TO_SCENE_H
#define CARD_TO_SCENE_H

#include <QDebug>
#include <QGraphicsRectItem>
#include <QString>
#include <QGraphicsScene>

#include <QList>

#include "card_rect.h"


class Card_to_scene
{
private:

    QList<Card_rect* > card_rect_list;

public:
    Card_to_scene();


    void Add_cards_to_scene(QGraphicsScene*, QList<QPair<QString, long double>>);
};

#endif // CARD_TO_SCENE_H
