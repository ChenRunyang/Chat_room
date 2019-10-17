/********************************************************************************
** Form generated from reading UI file 'chat_ui.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_UI_H
#define UI_CHAT_UI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chat_ui
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QTextBrowser *chat_show;
    QTextBrowser *user_name;
    QPushButton *pushButton;
    QComboBox *feature;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *ob;
    QLineEdit *inputtext;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *chat_ui)
    {
        if (chat_ui->objectName().isEmpty())
            chat_ui->setObjectName(QStringLiteral("chat_ui"));
        chat_ui->resize(500, 300);
        centralwidget = new QWidget(chat_ui);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(340, 10, 81, 16));
        chat_show = new QTextBrowser(centralwidget);
        chat_show->setObjectName(QStringLiteral("chat_show"));
        chat_show->setGeometry(QRect(10, 10, 301, 201));
        user_name = new QTextBrowser(centralwidget);
        user_name->setObjectName(QStringLiteral("user_name"));
        user_name->setGeometry(QRect(330, 30, 141, 131));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(230, 220, 81, 31));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        feature = new QComboBox(centralwidget);
        feature->setObjectName(QStringLiteral("feature"));
        feature->setGeometry(QRect(340, 180, 131, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(330, 160, 111, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(330, 210, 61, 16));
        ob = new QComboBox(centralwidget);
        ob->setObjectName(QStringLiteral("ob"));
        ob->setGeometry(QRect(340, 230, 131, 22));
        inputtext = new QLineEdit(centralwidget);
        inputtext->setObjectName(QStringLiteral("inputtext"));
        inputtext->setGeometry(QRect(10, 220, 211, 31));
        chat_ui->setCentralWidget(centralwidget);
        menubar = new QMenuBar(chat_ui);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 500, 23));
        menu = new QMenu(menubar);
        menu->setObjectName(QStringLiteral("menu"));
        chat_ui->setMenuBar(menubar);
        statusbar = new QStatusBar(chat_ui);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        chat_ui->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());

        retranslateUi(chat_ui);

        QMetaObject::connectSlotsByName(chat_ui);
    } // setupUi

    void retranslateUi(QMainWindow *chat_ui)
    {
        chat_ui->setWindowTitle(QApplication::translate("chat_ui", "MainWindow", 0));
        label->setText(QApplication::translate("chat_ui", "\345\275\223\345\211\215\345\234\250\347\272\277\347\224\250\346\210\267", 0));
        pushButton->setText(QApplication::translate("chat_ui", "\345\217\221\351\200\201", 0));
        feature->clear();
        feature->insertItems(0, QStringList()
         << QApplication::translate("chat_ui", "\346\214\202\346\234\272", 0)
         << QApplication::translate("chat_ui", "\347\247\201\350\201\212", 0)
         << QApplication::translate("chat_ui", "\345\271\277\346\222\255", 0)
         << QApplication::translate("chat_ui", "\347\246\201\350\250\200\357\274\210\347\256\241\347\220\206\345\221\230\346\235\203\351\231\220\357\274\211", 0)
         << QApplication::translate("chat_ui", "\350\247\243\347\246\201\357\274\210\347\256\241\347\220\206\345\221\230\346\235\203\351\231\220\357\274\211", 0)
         << QApplication::translate("chat_ui", "\350\270\242\344\272\272\357\274\210\347\256\241\347\220\206\345\221\230\346\235\203\351\231\220\357\274\211", 0)
        );
        label_2->setText(QApplication::translate("chat_ui", "\350\257\267\351\200\211\346\213\251\345\212\237\350\203\275\357\274\232", 0));
        label_3->setText(QApplication::translate("chat_ui", "\350\257\267\351\200\211\346\213\251\345\257\271\350\261\241", 0));
        menu->setTitle(QApplication::translate("chat_ui", "\345\225\212\345\223\210\350\201\212\345\244\251\345\256\244", 0));
    } // retranslateUi

};

namespace Ui {
    class chat_ui: public Ui_chat_ui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_UI_H
