#ifndef CARD_RECT_H
#define CARD_RECT_H

#include <QGraphicsRectItem>
#include <QString>
#include <QGraphicsScene>
#include <QRandomGenerator>
#include <QList>
#include <QPair>

#include "allusersfile.h"


class Card_rect : public QGraphicsRectItem
{
private:
    qreal x,y;
    qreal width,height;

    QString card_number;
    long long money;

    void Add_rect(QGraphicsScene*);
    void Add_text(QGraphicsScene*);

    QList<QPair<QColor, QColor>> good_colors_list;

    void add_colors();

    QGraphicsPathItem* pathItem;
    QGraphicsTextItem* card_number_text;
    QGraphicsTextItem* money_text;

public:
    Card_rect(QString, long long, QGraphicsItem* parent = nullptr);

    void Add_card_to_scene(QGraphicsScene*, qreal, QString mode);

    void Rect_to_right();
    void Rect_to_left();
    void Rect_to_centre();;

};

#endif // CARD_RECT_H
