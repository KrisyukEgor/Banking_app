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

    Card_to_scene card_to_scene;

    QList<QPair<QString, long double>> temp;

    QPair<QString, long double> temp_pair = {"1234 5678 1234 5678", 10.4512};

    temp.append(temp_pair);

    card_to_scene.Add_cards_to_scene(scene, temp);

}

void Home_window::on_Account_button_clicked()
{
    ui -> stackedWidget -> setCurrentIndex(0);
}

void Home_window::on_Cards_button_clicked()
{
    ui -> stackedWidget -> setCurrentIndex(1);
}
void Home_window::on_Transfer_button_clicked()
{
    ui -> stackedWidget -> setCurrentIndex(2);
}

void Home_window::on_Transactions_button_clicked()
{
    ui -> stackedWidget -> setCurrentIndex(3);
}



void Home_window::on_Card_data_button_clicked()
{

}

void Home_window::on_Transfer_money_buttob_clicked()
{
    ui -> stackedWidget -> setCurrentIndex(2);
}

void Home_window::on_Card_window_transactions_button_clicked()
{
    ui -> stackedWidget -> setCurrentIndex(3);
}




void Home_window::on_stackedWidget_currentChanged(int index)
{
    ui -> Account_button -> setStyleSheet("color: white;");
    ui -> Cards_button -> setStyleSheet("color: white;");
    ui -> Transfer_button -> setStyleSheet("color: white;");
    ui -> Transactions_button -> setStyleSheet("color: white;");


    if(index == 0){
        ui -> Account_button -> setStyleSheet("background-color:blue;color: white;");
    }
    else if(index == 1){
        ui -> Cards_button -> setStyleSheet("background-color:blue;color: white;");
    }
    else if(index == 2){
        ui -> Transfer_button -> setStyleSheet("background-color:blue;color: white;");
    }
    else if(index == 3){
        ui -> Transactions_button -> setStyleSheet("background-color:blue;color: white;");
    }
}

