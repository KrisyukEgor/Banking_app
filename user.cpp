#include "user.h"

User::User()
{

}

void User::setName(const QString & name){
    this -> name = name;
}

void User::setSurname(const QString & name){
    surname = name;
}

void User::setMiddlename(const QString& name) {
    middle_name = name;
}

void User::setLogin(const QString& login) {
    this -> login = login;
}

void User::setBirthday(const QDate& date){
    birthday = date;
}

void User::setEmail(const QString &mail){
    email = mail;
}
void User::setId(const QString &str){
    id = str;
}

QString User::GetName(){
    return name;
}

QString User::GetMiddlename(){
    return middle_name;
}

QString User::GetSurname(){
    return surname;
}

QDate User::GetBirthday(){
    return birthday;
}

QString User::GetEmail(){
    return email;
}

QString User::GetLogin(){
    return login;
}
QString User::GetId(){
    return id;
}

long long User::Get_cards_count(){
    return card_list.length();
}

QString User::Get_card_number(long long index){
    return card_list[index] -> GetCardNumber();
}

long long User::Get_card_money(long long index){
    return card_list[index] -> GetMoney();
}
void User::AddCard(Card* card){

    card_list.append(card);
}

void User::Debug(){
    qDebug() << surname;
    qDebug() << name;
    qDebug() << middle_name;
    qDebug() << email;
    qDebug() << login;
    qDebug() << birthday;
    qDebug() << id;
}
