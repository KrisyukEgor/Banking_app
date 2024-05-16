#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Home_window w(0);

    w.setWindowTitle("");

    w.show();


    return a.exec();
}
