#ifndef CARD_TO_SCENE_H
#define CARD_TO_SCENE_H

#include <QDebug>
#include <QGraphicsRectItem>
#include <QString>
#include <QGraphicsScene>
#include <QPen>
#include <QList>
#include <QPair>
#include <QRandomGenerator>
#include <QGraphicsTextItem>
#include <QFont>


class Card_to_scene : public QGraphicsRectItem, public QObject
{
private:


public:
    Card_to_scene();


    void Add_cards_to_scene(QGraphicsScene*, QList<QPair<QString, long double>>);
};

#endif // CARD_TO_SCENE_H
