/********************************************************************************
** Form generated from reading UI file 'config.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIG_H
#define UI_CONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Config
{
public:
    QWidget *centralwidget;
    QPushButton *conButton;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *paddress;
    QLineEdit *saddress;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Config)
    {
        if (Config->objectName().isEmpty())
            Config->setObjectName(QStringLiteral("Config"));
        Config->resize(500, 300);
        centralwidget = new QWidget(Config);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        conButton = new QPushButton(centralwidget);
        conButton->setObjectName(QStringLiteral("conButton"));
        conButton->setGeometry(QRect(380, 210, 75, 23));
        conButton->setCursor(QCursor(Qt::PointingHandCursor));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 130, 71, 31));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(290, 140, 54, 12));
        paddress = new QLineEdit(centralwidget);
        paddress->setObjectName(QStringLiteral("paddress"));
        paddress->setGeometry(QRect(340, 140, 111, 21));
        saddress = new QLineEdit(centralwidget);
        saddress->setObjectName(QStringLiteral("saddress"));
        saddress->setGeometry(QRect(100, 140, 111, 21));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 60, 241, 21));
        Config->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Config);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 500, 23));
        Config->setMenuBar(menubar);
        statusbar = new QStatusBar(Config);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Config->setStatusBar(statusbar);

        retranslateUi(Config);

        QMetaObject::connectSlotsByName(Config);
    } // setupUi

    void retranslateUi(QMainWindow *Config)
    {
        Config->setWindowTitle(QApplication::translate("Config", "MainWindow", 0));
        conButton->setText(QApplication::translate("Config", "\350\277\236\346\216\245", 0));
        label_3->setText(QApplication::translate("Config", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200: ", 0));
        label_4->setText(QApplication::translate("Config", "\347\253\257\345\217\243\345\217\267\357\274\232", 0));
        paddress->setText(QString());
        saddress->setText(QString());
        label->setText(QApplication::translate("Config", "\347\224\250\346\210\267\357\274\214\344\275\240\345\245\275\357\274\214\346\254\242\350\277\216\344\275\277\347\224\250\345\225\212\345\223\210\350\201\212\345\244\251\345\256\244\357\274\214\345\223\210\345\223\210\345\223\210", 0));
    } // retranslateUi

};

namespace Ui {
    class Config: public Ui_Config {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIG_H
