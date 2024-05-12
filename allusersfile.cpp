
#include "allusersfile.h"


extern Bank_meneger& meneger;

AllUsersFile::AllUsersFile()
{

}

void AllUsersFile::Add_user_base_data_to_all_users_file(long long index){

    QString file_path = meneger.Get_file_path_to_all_users();


    QFile file(file_path);

    QString login = meneger.GetUserLogin(index);
    QString password = meneger.GetUserPassword(index);


    if(file.open(QIODevice::Append | QIODevice::Text)){

        QTextStream stream(&file);
        stream << login << '\n';
        stream << password << '\n';

        file.close();

    }
    else{
        qDebug() << "Add user file dont open";
    }
}

void AllUsersFile::Add_user_personal_data_to_file(long long index){

    QString id = "/" + meneger.GetUserId(index);

    QString new_user_folder_path = meneger.Get_folder_path() + id;
    QString new_user_file_path = meneger.Get_folder_path() + id + id;

    QDir dir(new_user_folder_path);

    if(!dir.exists()){

        dir.mkdir(new_user_folder_path);

    }

    QFile file(new_user_file_path);

    if(file.open(QIODevice::Append | QIODevice::Text)){
        QTextStream stream(&file);

        stream << meneger.GetUserSurname(index) << '\n';
        stream << meneger.GetUserName(index) << '\n';
        stream << meneger.GetUserMiddlename(index) << '\n';
        stream << meneger.GetUserBirthDay(index).toString("dd.MM.yyyy") << '\n';
        stream << meneger.GetUserEmail(index) << '\n';
        stream << meneger.GetUserLogin(index) << '\n';
        stream << meneger.GetUserId(index) << '\n';

        file.close();
    }

}

void AllUsersFile::Users_in_file_to_meneger(){

    int count = 0;

    QString path = meneger.Get_file_path_to_all_users();
    QFile file(path);

    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);

        QString line;

        while(!stream.atEnd()){
            line = stream.readLine();

            User* user = new User();
            user -> setLogin(line);

            line = stream.readLine();

            QString password = line;

            QString person_path = "/" + meneger.MakeUserId(count);

            QString path = meneger.Get_folder_path() + person_path + person_path;


            QFile person_file(path);

            if(person_file.open(QIODevice::ReadOnly | QIODevice::Text)){
                QTextStream person_file_stream(&person_file);

                QString surname = person_file_stream.readLine();
                QString name = person_file_stream.readLine();
                QString middlename = person_file_stream.readLine();
                QDate date = QDate::fromString(person_file_stream.readLine(), "dd.MM.yyyy");
                QString email = person_file_stream.readLine();
                QString login = person_file_stream.readLine();
                QString id = person_file_stream.readLine();


                user -> setName(name);
                user -> setSurname(surname);
                user -> setMiddlename(middlename);
                user -> setBirthday(date);
                user -> setEmail(email);
                user -> setLogin(login);
                user -> setId(id);
                meneger.AddUser(user,password);

                count++;
            }

        }

        file.close();
    }
}
