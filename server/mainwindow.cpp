#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    start_ser();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("usr.db3");
    if(db.open())
    {
        sql_query = new QSqlQuery;
        if(sql_query->exec(QString("select count(*) from user where type='table'")))
        {

        }
        else
        {
            if(sql_query->exec(QString("create table user(account text primary key,passwd text)")))
            {
                QMessageBox::information(NULL,"OK","create");
            }
        }
    }
    else
    {
        QMessageBox::information(NULL,"error","database not open");
    }
}



void MainWindow::s2c(rlmessage &reg,QString account,QString password)                     //QString转char[]
{
    QByteArray ba1 = account.toLatin1();
    const char *tmp=ba1.data();
    strcpy(reg.acount_buff,tmp);
    QByteArray ba2= password.toLatin1();
    const char*tmp2=ba2.data();
    strcpy(reg.password_buff,tmp2);
}


void MainWindow::s2c(rlmessage &reg,QString account,QString password,QString buff)
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


void MainWindow::start_ser()                                             //绑定槽函数
{
    m_server = new QTcpServer(this);
    m_server->listen(QHostAddress::Any,9999);
    connect(m_server,SIGNAL(newConnection()),this,SLOT(slot_newConnect()));
    ui->textBrowser->setText("Waiting");
}

int MainWindow::check(rlmessage i)
{
    QString tmp=QString(QLatin1String(i.acount_buff));
    for(int i=0;i<on_account.size();i++)
    {
        if (tmp==on_account[i])
        {
            return i;
        }
    }
    return -1;
}

int MainWindow::check_poi(rlmessage i)
{
    QString tmp=QString(QLatin1String(i.password_buff));
    for(int i=0;i<on_account.size();i++)
    {
        if (tmp==on_account[i])
        {
            return i;
        }
    }
    return -1;
}

void MainWindow::slot_readMessage()                                     //接收到数据
{
    QTcpSocket* socket = (QTcpSocket*)QObject::sender();  //Which one to send message
    rlmessage str;
    QString tmp;
    socket->read((char *) &str,sizeof(rlmessage));
    int seq=check(str);
    int poi;
    switch(str.action)
    {
        case INQUE:
        {
            inqure_data.action=INQUE;
            for(int m=0;m<on_account.size();m++)
            {
                s2c(inqure_data,(on_account[m]),"","");
                socket->write((char *)&inqure_data,sizeof(inqure_data));
                socket->waitForBytesWritten(80000);
            }
        }
        break;
        case PRCHAT:
        {
            if(competence[seq]!=0)
            {
                poi=check_poi(str);
                on_sockets[poi]->write((char *)&str,sizeof(str));
            }
            else
            {
                str.action=BAN;
                on_sockets[seq]->write((char *)&str,sizeof(str));
            }
        }
        break;
        case BAN:
        {
            poi=check_poi(str);
            competence[poi]=0;
        }
        break;
        case UNBAN:
        {
            poi=check_poi(str);
            competence[poi]=1;
        }
        break;
        case KICK:
        {
            poi=check_poi(str);
            on_sockets[poi]->write((char *)&str,sizeof(str));
            QList<QTcpSocket*>::iterator first=on_sockets.begin();
            QList<QTcpSocket*>::iterator currect=first+poi;
            on_sockets.erase(currect);
        }
        break;
        case PUCHAT:
        if(competence[seq]!=0)
        {
            for(int i=0;i<on_sockets.size();i++)
            {
                if(i==seq)
                {
                    continue;
                }
                on_sockets[i]->write((char *)&str,sizeof(str));
            }
        }
        else
        {
            str.action=BAN;
            on_sockets[seq]->write((char *)&str,sizeof(str));
        }
            break;
        case REG:
            tmp.sprintf("insert into user (account,passwd) values ('%s','%s')",str.acount_buff,str.password_buff);
            if(sql_query->exec(tmp))
            {
                str.action = REGSUCCESS;
                ui->textBrowser->append("A client has registered");
                socket->write((char *)&str,sizeof(str));
            }
            else
            {
                str.action =REGFAIL;
                socket->write((char *)&str,sizeof(str));
            }
            break;
        case LOG:
            tmp.sprintf("select account from user where account ='%s' and passwd ='%s'",str.acount_buff,str.password_buff);
            QSqlQuery find_name(tmp);
            if(!(find_name.isActive()))
            {
                str.action = LOGFAIL;
                socket->write((char *)&str,sizeof(str));
            }
            else
            {
                find_name.next();
                if(!(find_name.isValid()))
                {
                    str.action = LOGFAIL;
                    socket->write((char *)&str,sizeof(str));
                }
                else
                {
                    ui->textBrowser->append("A client has logined");
                    str.action = LOGSUCCESS;
                    on_sockets.push_back(socket);
                    on_account.push_back(QString(QLatin1String(str.acount_buff)));
                    competence.push_back(1);
                    socket->write((char *)&str,sizeof(str));
                }
            }
            break;

    }
}

void MainWindow::slot_newConnect()                            //有新链接
{
   ui->textBrowser->append("A client is collect");
   QTcpSocket* socket = m_server->nextPendingConnection();
   m_sockets.push_back(socket);
   connect(socket,SIGNAL(readyRead()),this,SLOT(slot_readMessage()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
