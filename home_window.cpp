#include "home_window.h"
#include "ui_home_window.h"
#include "allusersfile.h"
#include <QScrollArea>

extern Bank_meneger& meneger;

Home_window::Home_window(long long user_index, QWidget *parent) :QDialog(parent),ui(new Ui::Home_window)
{
    ui->setupUi(this);

    ui -> stackedWidget -> setCurrentIndex(1);
    scene = new QGraphicsScene();

    ui -> graphicsView -> setScene(scene);

    this -> user_index = user_index;

    QString folder_path = QDir::currentPath() + "/files";
    QString file_path = folder_path + "/All users";

    meneger.Set_file_path_to_all_users(file_path);
    meneger.Set_folder_path(folder_path);

    AllUsersFile::Users_in_file_to_meneger();

    Add_Personal_user_data_to_window();

    Add_cards_to_scene();

    double a = 1.7;
    double b = 1.8;

    qDebug() << a + b;
}

Home_window::~Home_window()
{
    delete ui;
}

void Home_window::on_Exit_button_clicked()
{

    emit(OpenMainWindow());
    this -> close();
}

void Home_window::Add_Personal_user_data_to_window(){

    ui -> Name_line -> setText(meneger.GetUserName(user_index));
    ui -> Middle_name_line -> setText(meneger.GetUserMiddlename(user_index));
    ui -> Surname_line -> setText(meneger.GetUserSurname(user_index));

    ui -> Birthday_line -> setText(meneger.GetUserBirthDay(user_index).toString("dd.MM.yyyy"));

    ui -> Login_line -> setText(meneger.GetUserLogin(user_index));
    ui -> Email_line -> setText(meneger.GetUserEmail(user_index));

    if(meneger.Get_user_card_count(user_index) > 0){
        current_card = meneger.Get_user_card(user_index, 0);
    }


}


void Home_window::on_Account_button_clicked()
{
    ui -> stackedWidget -> setCurrentIndex(0);
}

void Home_window::on_Cards_button_clicked()
{
    ui -> stackedWidget -> setCurrentIndex(1);
}

void Home_window::on_Transactions_button_clicked()
{
    ui -> stackedWidget -> setCurrentIndex(2);
}

void Home_window::Add_cards_to_scene(){
    scene -> clear();

    QList<QPair<QString, long double>> temp;
    QPair<QString, long double> temp_pair;

    for(long long i = 0; i < meneger.Get_user_card_count(user_index); ++i){
        temp_pair = {meneger.Get_user_card_number(user_index, i), meneger.Get_user_card_money(user_index, i)};
        temp.append(temp_pair);
    }

    temp.append(temp_pair);

    card_to_scene.Add_cards_to_scene(scene, temp);

}

void Home_window::on_Card_data_button_clicked()
{
    card_data_window = new Card_data_window(current_card);
    card_data_window -> exec();
}


void Home_window::on_stackedWidget_currentChanged(int index)
{
    ui -> Account_button -> setStyleSheet("color: white;");
    ui -> Cards_button -> setStyleSheet("color: white;");
    ui -> Transactions_button -> setStyleSheet("color: white;");


    if(index == 0){
        ui -> Account_button -> setStyleSheet("background-color:blue;color: white;");
    }
    else if(index == 1){
        ui -> Cards_button -> setStyleSheet("background-color:blue;color: white;");
    }
    else if(index == 2){
        ui -> Transactions_button -> setStyleSheet("background-color:blue;color: white;");
    }
}

void Home_window::on_menu_change_size_button_toggled(bool checked)
{
    qreal width = ui -> menu_card_frame -> width();
    qreal height = ui -> menu_card_frame -> height();

    QTimer* timer = new QTimer(this);

    timer -> setInterval(1);

    if(checked){

        connect(timer, &QTimer::timeout, this, [=] () mutable{
            if(width > ui -> menu_change_size_button -> x() + ui -> menu_change_size_button -> width() + 20){
                width -= 5;
                ui -> menu_card_frame -> resize(width, height);
            }
            else{
                timer -> stop();
            }
        });
    }
    else{

        connect(timer, &QTimer::timeout, this, [=] () mutable{
            if(width < ui -> Register_new_card_button -> x() + ui -> Register_new_card_button -> width() + 20){
                width += 5;
                ui -> menu_card_frame -> resize(width, height);
            }
            else{
                timer -> stop();
            }
        });
    }

    timer -> start();
}


void Home_window::on_Register_new_card_button_clicked()
{
    register_new_card_window = new Register_new_card_window(user_index);
    register_new_card_window -> exec();

}


void Home_window::on_Transfer_money_button_clicked()
{

}

