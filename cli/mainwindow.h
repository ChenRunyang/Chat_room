#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore/QObject>
#include"chat_ui.h"
#include <qmessagebox.h>
#include <QTcpSocket>
#include <QHostAddress>
#include<string.h>

#define REG 1
#define LOG 2
#define PRCHAT 3
#define PUCHAT 4
#define BAN 5
#define UNBAN 6
#define KICK 0
#define REGSUCCESS 10
#define REGFAIL 9
#define LOGSUCCESS 8
#define LOGFAIL 7

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void sendmessage(rlmessage msg);
    void reg_action();
    void s2c(rlmessage &reg,QString account,QString password);
    void set_address(QString s);
    void set_port(QString s);
    void set_acc(QString a);
    QString get_acc();
    QString get_address();
    int get_port();

private:
    Ui::MainWindow *ui;
    QTcpSocket *m_socket;
    QString sadd;
    int padd;
    QString account;

private slots:
    void slot_send_regmessage();
    void slot_send_logmessage();
    void slot_judge();

};

#endif // MAINWINDOW_H
