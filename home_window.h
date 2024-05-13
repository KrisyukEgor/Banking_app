#ifndef HOME_WINDOW_H
#define HOME_WINDOW_H

#include <QDialog>
#include <QTabBar>
#include <QTabWidget>
#include <QMainWindow>
#include <QToolBar>
#include <QGraphicsScene>

#include "card.h"
#include "bank_meneger.h"
#include "card_to_scene.h"

namespace Ui {
class Home_window;
}

class Home_window : public QDialog
{
    Q_OBJECT

signals:
    void OpenMainWindow();


public:
    explicit Home_window(long long user_index, QWidget *parent = nullptr);
    ~Home_window();

private slots:
    void on_Exit_button_clicked();

    void on_Account_button_clicked();

    void on_Cards_button_clicked();

    void on_Transactions_button_clicked();

    void on_Transfer_button_clicked();

    void Add_Personal_user_data_to_window();

    void on_Card_data_button_clicked();

    void on_Card_window_transactions_button_clicked();

    void on_Transfer_money_buttob_clicked();

    void on_stackedWidget_currentChanged(int arg1);

private:
    Ui::Home_window *ui;
    QGraphicsScene* scene;

    long long user_index;
};

#endif // HOME_WINDOW_H
