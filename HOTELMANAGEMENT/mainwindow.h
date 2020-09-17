#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "sqllitedriver.h"
#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QApplication>
#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QMovie>
#include <QTimer>
#include <QEvent>







namespace Ui {
class MainWindow;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class MainWindow : public QMainWindow
{

    DBLITT HOTELMANAGEMENT;
    bool showP;
    QMovie* loadAni;

    Ui::MainWindow *ui;
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void showPasswordEvent()
    {


        if(!showP)
        {
            ui->passwordEdit->setEchoMode(QLineEdit::Password);
            showP = 1;
        }
        else if(showP)
        {
            ui->passwordEdit->setEchoMode(QLineEdit::Normal);
            showP = 0;
        }

    }
    inline void updateWindowTitle(QString titleName )
    {
      setWindowTitle(titleName);
    }
    void DBconnectionStatus()
    {
        if(HOTELMANAGEMENT.getConnectStatus() == 1 )
        {
            \
            ui->DatabaseConnection->setText("Connected");
            loadAni->stop();
            ui->loadingAnim->clear();
            ui->loadingAnim->setStyleSheet("border-image: url(/Users/oscy/Desktop/HOTELDEPEND/connected.png) 0 0 0 0 stretch stretch");

        }
        else{
            ui->DatabaseConnection->setText("Connecting");
            ui->loadingAnim->setStyleSheet("");
            loadAni = new QMovie("/Users/oscy/Desktop/loadAN.gif");
            ui->loadingAnim->setMovie(loadAni);
            ui->loadingAnim->show();
            loadAni->start();;

        }
    }


private slots:
    void on_showPass_clicked();
};
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#endif // MAINWINDOW_H
