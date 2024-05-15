#include "card_rect.h"

Card_rect::Card_rect(QString number, long long count,QGraphicsItem *parent) : QGraphicsRectItem(parent)
{
    card_number = number;
    money = count;

    add_colors();
}

void Card_rect::Add_card_to_scene(QGraphicsScene *scene, qreal x , QString mode){

    this -> x = x;

    if(mode == "big"){
        y = 0;
        width = 300;
        height = 180;
        Add_rect(scene);
        Add_text(scene);
    }

    else if(mode == "small"){
        y = 30;
        width = 200;
        height = 60;
        Add_rect(scene);

    }

}


void Card_rect::Add_rect(QGraphicsScene* scene){

    QRectF rect (x,y,width,height);

    qreal cornerRadius = 20.0;

    pathItem = new QGraphicsPathItem();

    QPainterPath path;
    path.addRoundedRect(rect, cornerRadius, cornerRadius);

    pathItem -> setPath(path);

    QPen pen;

    QLinearGradient gradient(rect.topLeft(), rect.bottomRight());

    int index = QRandomGenerator::global() -> bounded(0,good_colors_list.length() - 1);

    index = 1;

    QPair<QColor, QColor> colors = good_colors_list.at(index);

    gradient.setColorAt(0, colors.first);
    gradient.setColorAt(1, colors.second);

    pen.setBrush(gradient);
    pathItem -> setPen(pen);
    pathItem -> setBrush(gradient);

    scene -> addItem(pathItem);

}

void Card_rect::Add_text(QGraphicsScene *scene){

    card_number_text = new QGraphicsTextItem(card_number);

    card_number_text -> setDefaultTextColor(Qt::white);

    QFont font = card_number_text -> font();

    font.setPointSize(14);
    font.setFamily("Arial");

    card_number_text -> setFont(font);

    card_number_text -> setX(10);
    card_number_text -> setY(180 - 35);

    scene -> addItem(card_number_text);

    QString money_str = AllUsersFile::From_long_double_to_QString(money);

    money_text = new QGraphicsTextItem(money_str);

    money_text -> setDefaultTextColor(Qt::white);

    font.setPointSize(25);

    money_text -> setFont(font);
    money_text -> setX(10);
    money_text -> setY(0 + 20);

    scene -> addItem(money_text);

}

void Card_rect::add_colors(){
    QPair<QColor, QColor> temp;

    temp.first = QColor("#C2600F");
    temp.second = QColor("#A11AEA");

    good_colors_list.append(temp);

    temp.first = QColor("#9F9B32");
    temp.second = QColor("#BE3AEE");

    good_colors_list.append(temp);
}
