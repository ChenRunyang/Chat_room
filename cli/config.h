#ifndef CONFIG_H
#define CONFIG_H

#include <QMainWindow>
#include "mainwindow.h"

namespace Ui {
class Config;
}

class Config : public QMainWindow
{
    Q_OBJECT

public:
    explicit Config(QWidget *parent = 0);
    ~Config();
    void config();
    void set_address(QString add);
    void set_port(QString port);

private:
    Ui::Config *ui;
     MainWindow w;

private slots:
     void slot_reg();
};

#endif // CONFIG_H
