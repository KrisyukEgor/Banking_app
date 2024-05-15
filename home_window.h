#ifndef HOME_WINDOW_H
#define HOME_WINDOW_H

#include <QDialog>
#include <QTabBar>
#include <QTabWidget>
#include <QMainWindow>
#include <QToolBar>
#include <QGraphicsScene>
#include <QTimer>


#include "card.h"
#include "bank_meneger.h"
#include "card_to_scene.h"
#include "register_new_card_window.h"
#include "card_data_window.h"

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


    void Add_Personal_user_data_to_window();

    void on_Card_data_button_clicked();

    void on_stackedWidget_currentChanged(int arg1);

    void on_menu_change_size_button_toggled(bool checked);

    void on_Register_new_card_button_clicked();

    void on_Transfer_money_button_clicked();

private:
    Ui::Home_window *ui;
    QGraphicsScene* scene;
    Register_new_card_window* register_new_card_window;
    Card_data_window* card_data_window;

    Card* current_card;

    long long user_index;

    void Add_cards_to_scene();

    Card_to_scene card_to_scene;
};

#endif // HOME_WINDOW_H
