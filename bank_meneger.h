#ifndef BANK_MENEGER_H
#define BANK_MENEGER_H

#include "user.h"
#include "card.h"

#include <QPair>

class Bank_meneger
{
private:
    QList<QPair<User*, QString>> user_list;
    QList<Card*> all_cards_list;

    QString all_users_file_path;
    QString folder_path;

    Bank_meneger();


public:
    void Registrer_card();

    static Bank_meneger& getInstance();   // Singleton
    long long GetUserCount();

    void AddUser(User* &, QString &);

    void ChangeUserName(long long, QString &);
    void ChangeUserSurname(long long, QString &);
    void ChangeUserMiddlename(long long, QString &);
    void ChangeUserBirthday(long long, QDate &);
    void ChangeUserEmail(long long, QString &);
    void ChangeUserLogin(long long, QString &);

    QString GetUserName(long long);
    QString GetUserSurname(long long);
    QString GetUserMiddlename(long long);
    QDate GetUserBirthDay(long long);
    QString GetUserLogin(long long);
    QString GetUserEmail(long long);
    QString GetUserId(long long);
    QString GetUserPassword(long long);

    void Set_folder_path(QString &);
    QString Get_folder_path();

    void Set_file_path_to_all_users(QString &);
    QString Get_file_path_to_all_users();

    QString MakeUserId(long long);
    void SetUserId(long long);

    void Debug_user(long long);

    void RemoveUser();
    void RemoveUser(long long index);

    bool Check_email(QString &);

    long long Is_user_login_exist(QString &);
    bool Check_password(QString &, int);

    void Add_card_to_user(long long, Card* );
    void Add_card_to_scene(long long, long long);

};

#endif // BANK_MENEGER_H
