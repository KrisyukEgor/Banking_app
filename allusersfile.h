#ifndef ALLUSERSFILE_H
#define ALLUSERSFILE_H

#include <QString>
#include <QFile>
#include <QDir>
#include <QDebug>

#include "bank_meneger.h"

class AllUsersFile
{
public:
    AllUsersFile();


    static void Add_user_base_data_to_all_users_file(long long index);

    static void Add_user_personal_data_to_file(long long);

    static void Users_in_file_to_meneger();
};

#endif // ALLUSERSFILE_H
