#include "config.h"
#include "ui_config.h"

Config::Config(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Config)
{
    ui->setupUi(this);
    config();
}

void Config::config()
{
    connect(ui->conButton,SIGNAL(clicked()),this,SLOT(slot_reg()));
}

void Config::slot_reg()
{
    w.set_address(ui->saddress->text());
    w.set_port(ui->paddress->text());
    this->hide();
    w.show();
    w.reg_action();
}

Config::~Config()
{
    delete ui;
}
