#include "chat_ui.h"
#include "ui_chat_ui.h"

chat_ui::chat_ui(QTcpSocket *msocket,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::chat_ui)
{
    ui->setupUi(this);
    this->cm_socket=msocket;
    chat_action();
}

void chat_ui::time_init()
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(slot_update()));
    timer->start(8000);
}



void chat_ui::chat_action()                                 //绑定槽函数
{

    connect(cm_socket,SIGNAL(readyRead()),this,SLOT(slot_judge()));
    connect(ui->feature,SIGNAL(currentIndexChanged(int)),this,SLOT(slot_chgfea()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(slot_sendmeg()));

}

void chat_ui::s2c(rlmessage &reg,QString account,QString password)     //QString转为char[]
{
    QByteArray ba1 = account.toLatin1();
    const char *tmp=ba1.data();
    strcpy(reg.acount_buff,tmp);
    QByteArray ba2= password.toLatin1();
    const char *tmp2=ba2.data();
    strcpy(reg.password_buff,tmp2);
}


void chat_ui::s2c(rlmessage &reg,QString account,QString password,QString buff)
{
    QByteArray ba1 = account.toLatin1();
    const char *tmp=ba1.data();
    strcpy(reg.acount_buff,tmp);
    QByteArray ba2= password.toLatin1();
    const char *tmp2=ba2.data();
    strcpy(reg.password_buff,tmp2);
    QByteArray ba3=buff.toLatin1();
    const char *tmp3=ba3.data();
    strcpy(reg.buff,tmp3);
}


void chat_ui::csendmessage(rlmessage msg)                     //发送数据
{
    cm_socket->write((char *)&msg,sizeof(msg));
}

void chat_ui::slot_chgfea()                                //选择功能
{
    int tmp =ui->feature->currentIndex();
    switch (tmp) {
    case 0:
        break;
    case 1:
        str.action=PRCHAT;
        break;
    case 2:
        str.action=PUCHAT;
        break;
    case 3:
        if(get_account()=="admin")
        {
            str.action=BAN;
        }
        else
        {
            ui->chat_show->append("Sorry you are not admin!");
        }
        break;
    case 4:
        if(get_account()=="admin")
        {
            str.action=UNBAN;
        }
        else
        {
            ui->chat_show->append("Sorry you are not admin!");
        }
        break;
    case 5:
        if(get_account()=="admin")
        {
            str.action=KICK;
        }
        else
        {
            ui->chat_show->append("Sorry you are not admin!");
        }
        break;
    default:
        break;
    }
}

void chat_ui::slot_judge()                                //接收到消息判断
{
    rlmessage rstr;
    cm_socket->read((char *) &rstr,sizeof(rlmessage));
    switch(rstr.action)
    {
        case(BAN):
            ui->chat_show->append("Sorry you are baned please contact admin");
        break;
        case(PUCHAT):
            ui->chat_show->append(QString(QLatin1String(rstr.acount_buff))+" say: "+QString(QLatin1String(rstr.buff)));
        break;
        case(PRCHAT):
            ui->chat_show->append(QString(QLatin1String(rstr.acount_buff))+" say to you:"+QString(QLatin1String(rstr.buff)));
        break;
        case INQUE:
            ui->user_name->append((QString(QLatin1String(rstr.acount_buff))));
            ui->ob->addItem(QString(QLatin1String(rstr.acount_buff)));
        break;
        case KICK:
            ui->user_name->append("You are kicked please sign out");
            exit(0);
        break;
    }
}

void chat_ui::slot_update()
{
    rlmessage ttmp;
    ui->user_name->clear();
    ui->ob->clear();
    ttmp.action=INQUE;
    csendmessage(ttmp);
}

void chat_ui::slot_sendmeg()                                  //点击发送按钮槽函数
{
    s2c(str,get_account(),ui->ob->currentText(),ui->inputtext->text());
    csendmessage(str);
}


void chat_ui::set_account(QString a)
{
    this->acc=a;
}

QString chat_ui::get_account()
{
    return this->acc;
}

chat_ui::~chat_ui()
{
    delete ui;
}
