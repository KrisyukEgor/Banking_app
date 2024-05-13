#ifndef USER_H
#define USER_H

#include <QList>
#include <QDate>
#include "card.h"

class User
{
private:
    QString surname;
    QString name;
    QString middle_name;
    QDate birthday;
    QString email;
    QString login;
    QString id;

    QList<Card*> card_list;


public:
    User();
    void setName(const QString &);
    void setSurname(const QString &);
    void setMiddlename(const QString &);
    void setLogin(const QString &);
    void setBirthday(const QDate &);
    void setEmail(const QString &);
    void setId(const QString &);

    void AddCard(Card*);

    QString GetName();
    QString GetSurname();
    QString GetMiddlename();
    QDate GetBirthday();
    QString GetEmail();
    QString GetLogin();
    QString GetId();

    long long Get_cards_count();

    QString Get_card_number(long long);
    long long Get_card_money(long long);


    void Debug();

};

#endif // USER_H
