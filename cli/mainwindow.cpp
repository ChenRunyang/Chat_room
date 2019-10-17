#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->password->setEchoMode(QLineEdit::Password);
    const QPixmap *img1 = new QPixmap("demo.jpg");
    img1->scaled(ui->image->size(), Qt::KeepAspectRatio);
    ui->image->setPixmap(*img1);
}



void MainWindow::s2c(rlmessage &reg,QString account,QString password)
{
    QByteArray ba1 = account.toLatin1();
    const char *tmp=ba1.data();
    strcpy(reg.acount_buff,tmp);
    QByteArray ba2= password.toLatin1();
    const char *tmp2=ba2.data();
    strcpy(reg.password_buff,tmp2);
}

void MainWindow::set_address(QString s)
{
    this->sadd=s;
}

void MainWindow::set_port(QString s)
{
    bool ok=true;
    this->padd=s.toInt(&ok,10);
}

void MainWindow::set_acc(QString a)
{
    this->account=a;
}
QString MainWindow::get_address()
{
    return this->sadd;
}

QString MainWindow::get_acc()
{
    return this->account;
}
int MainWindow::get_port()
{
    return this->padd;
}

void MainWindow::sendmessage(rlmessage msg)
{
    m_socket->write((char *)&msg,sizeof(msg));
}

void MainWindow::reg_action()
{
    m_socket=new QTcpSocket(this);
    m_socket->connectToHost(QHostAddress(sadd),padd);      //调试时可修改完服务器IP地址
    connect(ui->regButton,SIGNAL(clicked()),this,SLOT(slot_send_regmessage()));
    connect(ui->logButton,SIGNAL(clicked()),this,SLOT(slot_send_logmessage()));
    connect(m_socket,SIGNAL(readyRead()),this,SLOT(slot_judge()));
}

void MainWindow::slot_judge()
{
    chat_ui *chat=new chat_ui(this->m_socket);
    rlmessage str;
    m_socket->read((char *) &str,sizeof(rlmessage));
    switch (str.action) {
    case REGSUCCESS:
        QMessageBox::information(NULL, "imformation", "Register success\nPlease log");
        break;
    case REGFAIL:
        QMessageBox::information(NULL,"imformation","Register fail\nPlease re-register");
        break;
    case LOGFAIL:
        QMessageBox::information(NULL,"imformation","Log fail\nPlease relog");
        break;
    case LOGSUCCESS:
        this->hide();
        chat->set_account(account);
        chat->show();
        chat->time_init();
        break;
    default:
        break;
    }
}

void MainWindow::slot_send_logmessage()
{
    set_acc(ui->account->text());
    QString password = ui->password->text();
    rlmessage reg;
    reg.action=(LOG);
    s2c(reg,account,password);
    sendmessage(reg);
}


void MainWindow::slot_send_regmessage()
{
    QString account = ui->account->text();
    QString password = ui->password->text();
    rlmessage reg;
    reg.action=(REG);
    s2c(reg,account,password);
    sendmessage(reg);
}


MainWindow::~MainWindow()
{
    delete ui;
}
