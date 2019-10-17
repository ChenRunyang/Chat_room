#ifndef CHAT_UI_H
#define CHAT_UI_H

#include <QMainWindow>
#include <QtCore/QObject>
#include"chat_ui.h"
#include <qmessagebox.h>
#include <QTcpSocket>
#include <QHostAddress>
#include<string.h>
#include <qdatetime.h>
#include<QTime>
#include<QTimer>


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
class chat_ui;
}

struct rlmessage
{
    int action;
    char acount_buff[1024];
    char password_buff[1024];
    char buff[1024];
};

class chat_ui : public QMainWindow
{
    Q_OBJECT

public:
    void chat_action();
    void csendmessage(rlmessage msg);
    void set_account(QString a);
    void time_init();
    QString get_account();
    void set_set_csocket();
    rlmessage str;
    void s2c(rlmessage &reg,QString account,QString password);
    void s2c(rlmessage &reg,QString account,QString password,QString buff);
    explicit chat_ui(QTcpSocket *msocket,QWidget *parent = 0);
    ~chat_ui();

private:
    Ui::chat_ui *ui;
    QTcpSocket *cm_socket;
    QString acc;



private slots:
    void slot_judge();
    void slot_chgfea();
    void slot_sendmeg();
    void slot_update();
};

#endif // CHAT_UI_H
