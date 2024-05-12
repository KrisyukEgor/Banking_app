#include "home_window.h"
#include "ui_home_window.h"
#include <QScrollArea>

extern Bank_meneger& meneger;

Home_window::Home_window(long long user_index, QWidget *parent) :QDialog(parent),ui(new Ui::Home_window)
{
    ui->setupUi(this);
    ui -> stackedWidget -> setCurrentIndex(0);
    scene = new QGraphicsScene();

    ui -> graphicsView -> setScene(scene);

    this -> user_index = user_index;

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

