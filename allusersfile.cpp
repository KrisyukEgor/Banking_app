
#include "allusersfile.h"
#include <iostream>

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
            QString user_folder_path = meneger.Get_folder_path() + person_path;



            QString path = user_folder_path + person_path;

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

            QString card_path = user_folder_path + "/cards";


            QDir card_dir(card_path);

            if(card_dir.exists()){

                QStringList files_list = card_dir.entryList();
                QString file_name;

                for(int i = 0; i < files_list.length(); ++i){
                    if(files_list[i] == "." || files_list[i] == ".."){
                        continue;
                    }

                    file_name = card_path + "/" + files_list[i];

                    QFile card_file(file_name);


                    if(card_file.open(QIODevice::ReadOnly | QIODevice::Text)){

                        QTextStream card_stream(&card_file);

                        Card* card = new Card();

                        QString card_number = card_stream.readLine();



                        QString banking_app_number = card_stream.readLine();

                        QString pin = card_stream.readLine();
                        QString cvv = card_stream.readLine();
                        QString year = card_stream.readLine();
                        QString month = card_stream.readLine();

                        long double money = From_QString_to_long_double(card_stream.readLine());

                        card -> Set_card_number(card_number);
                        card -> Set_bank_account_name(banking_app_number);
                        card -> SetPin(pin);
                        card -> SetCvv(cvv);
                        card -> SetYear(year);
                        card -> SetMonth(month);
                        card -> Set_money_to_bank_account(money);

                        meneger.Set_card_to_user(meneger.GetUserCount() - 1, card);
                        meneger.Add_card(card);

                        card_file.close();

                    }
                    else{
                        qDebug() << "not open";
                    }

                }
            }
        }

        file.close();
    }
}

void AllUsersFile::Add_card_to_user(long long user_index, long long card_index){

    QString id = "/" + meneger.GetUserId(user_index);

    QString folder_path_to_user = meneger.Get_folder_path() + id;


    QString cards_folder_path = folder_path_to_user + "/cards";

    QDir dir(cards_folder_path);

    if(!dir.exists()){

        dir.mkdir(cards_folder_path);

    }

    QString path_to_card = cards_folder_path + "/" + meneger.Get_user_card_number(user_index, card_index);

    QFile file(path_to_card);

    if(file.open(QIODevice::Append | QIODevice::Text)){
        QTextStream stream(&file);

        stream << meneger.Get_user_card_number(user_index, card_index) << '\n';
        stream << meneger.Get_user_card_banking_app_name(user_index, card_index) << '\n';

        stream << meneger.Get_user_card_pin(user_index, card_index) << '\n';
        stream << meneger.Get_user_card_cvv(user_index, card_index) << '\n';

        stream << meneger.Get_user_card_year(user_index, card_index) << '\n';
        stream << meneger.Get_user_card_month(user_index, card_index) << '\n';

        stream << From_long_double_to_QString(meneger.Get_user_card_money(user_index, card_index)) << '\n';

        file.close();

    }

    else{
        qDebug() << "файл не открылся";
    }

}

QString AllUsersFile::From_long_double_to_QString(double number){

    long long int_part = (long long)number;
    double double_part = number - int_part;


    QString double_temp;
    double_part *= 100;
    double_part = std::round(double_part);

    if(double_part == 100.0){
        int_part ++;
        double_part = 0;
    }

    QString result = QString::number(int_part) + '.';



    result += QString::number(double_part).rightJustified(2,'0');

    return result;
}

double AllUsersFile::From_QString_to_long_double(QString str){
    double result = 0;

    int dot_index = str.indexOf('.');

    QString int_part_str = str.mid(0,dot_index);
    result += int_part_str.toLongLong();

    QString double_part_str = str.mid(dot_index + 1, str.length()).leftJustified(2,'0');


    double double_part = double_part_str.toInt() / 100.0;

    result += double_part;

    return result;
}
