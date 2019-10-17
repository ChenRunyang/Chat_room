#include "mainwindow.h"
#include <QApplication>
#include"config.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Config b;
    b.show();
    return a.exec();
}
