#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QSqlDatabase>
#include<QsqlQuery>
#include<QTime>
#include<QSqlDriver>
#include <QMainWindow>
#include <QTcpSocket>
#include <QHostAddress>
#include <QTcpServer>
#include "rlmessage.h"
#include <QSqlError>
#include "sqlite3.h"
#include<string.h>
#include<QMessageBox>

#define REG 1
#define LOG 2
#define PRCHAT 3
#define PUCHAT 4
#define BAN 5
#define UNBAN 6
#define KICK 12
#define REGSUCCESS 10
#define REGFAIL 9
#define LOGSUCCESS 8
#define LOGFAIL 7
#define INQUE 11


namespace Ui {
class MainWindow;
}

struct rlmessage
{
    int action;
    char acount_buff[1024];
    char password_buff[1024];
    char buff[1024];
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QTcpServer *m_server;
    QList<QTcpSocket *> m_sockets;
    QList<QTcpSocket *> on_sockets;
    QList<QString> on_account;
    QList<int> competence;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void start_ser();
    void s2c(rlmessage &reg,QString account,QString password);
    void s2c(rlmessage &reg,QString account,QString password,QString buff);
    int check(rlmessage i);
    int check_poi(rlmessage i);
private:
    Ui::MainWindow *ui;
    QSqlQuery *sql_query;
    rlmessage inqure_data;

private slots:
    void slot_newConnect();
    void slot_readMessage();
};


#endif
