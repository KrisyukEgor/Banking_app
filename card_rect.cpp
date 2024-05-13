#include "card_rect.h"

Card_rect::Card_rect(QString number, long long count,QGraphicsItem *parent) : QGraphicsRectItem(parent)
{
    card_number = number;
    money = count;
    add_colors();
}

void Card_rect::Add_card_to_scene(QGraphicsScene *scene, qreal x , qreal y , qreal length, qreal width){

    this -> x = x;
    this -> y = y;
    this -> length = length;
    this -> width = width;

    Add_rect(scene);
    Add_text(scene);

}


void Card_rect::Add_rect(QGraphicsScene* scene){

    QRectF rect (x,y,length,width);

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

    long long int_part = (long long)money;
    long double double_part = money - int_part;

    QString double_temp;
    QString money_str = QString::number(int_part) + '.';


    double_part *= 100;
    double_part = std::round(double_part);

    int_part = int(double_part);

    money_str += QString::number(int_part);

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
