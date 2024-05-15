#include "card_to_scene.h"
#include <iostream>

Card_to_scene::Card_to_scene()
{

}

void Card_to_scene::Add_cards_to_scene(QGraphicsScene *scene, QList<QPair<QString, long double>> data_list){

    Card_rect* temp_rect;

    qreal x_step = 400;

    for(int i = 0; i < data_list.length(); ++i){

        temp_rect = new Card_rect(data_list[i].first, data_list[i].second);

    }



}

