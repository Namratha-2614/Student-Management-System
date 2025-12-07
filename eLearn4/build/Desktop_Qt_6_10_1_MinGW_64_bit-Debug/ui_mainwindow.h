/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QLabel *label_6;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_4;
    QLabel *label_7;
    QWidget *widgetBack;
    QLabel *lblright_2;
    QPushButton *pushButton_3;
    QGroupBox *groupBox;
    QGroupBox *groupBox_2;
    QLabel *lblHead;
    QLabel *lblright;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(895, 616);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(310, 166, 101, 31));
        QFont font;
        font.setPointSize(14);
        label_2->setFont(font);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(310, 216, 101, 31));
        label_3->setFont(font);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(510, 166, 211, 26));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(510, 216, 211, 26));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(550, 266, 93, 29));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(480, 96, 101, 31));
        label_4->setFont(font);
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setEnabled(false);
        lineEdit_3->setGeometry(QRect(520, 396, 211, 26));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setEnabled(false);
        label_6->setGeometry(QRect(320, 446, 181, 31));
        label_6->setFont(font);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(560, 496, 93, 29));
        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setEnabled(false);
        lineEdit_4->setGeometry(QRect(520, 446, 211, 26));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setEnabled(false);
        label_7->setGeometry(QRect(320, 396, 181, 31));
        label_7->setFont(font);
        widgetBack = new QWidget(centralwidget);
        widgetBack->setObjectName("widgetBack");
        widgetBack->setGeometry(QRect(0, 70, 851, 491));
        widgetBack->setStyleSheet(QString::fromUtf8("background-color: lightblue;"));
        lblright_2 = new QLabel(widgetBack);
        lblright_2->setObjectName("lblright_2");
        lblright_2->setGeometry(QRect(0, 0, 181, 491));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        lblright_2->setFont(font1);
        lblright_2->setStyleSheet(QString::fromUtf8("background-color: darkblue;color: white;"));
        lblright_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pushButton_3 = new QPushButton(widgetBack);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(460, 270, 93, 41));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        pushButton_3->setFont(font2);
        groupBox = new QGroupBox(widgetBack);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(250, 20, 541, 221));
        groupBox->setAutoFillBackground(false);
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(10, 230, 541, 221));
        groupBox_2->setAutoFillBackground(false);
        groupBox_2->setFlat(false);
        groupBox_2->setCheckable(false);
        lblHead = new QLabel(centralwidget);
        lblHead->setObjectName("lblHead");
        lblHead->setGeometry(QRect(0, 6, 881, 61));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Elephant")});
        font3.setPointSize(36);
        lblHead->setFont(font3);
        lblHead->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        lblHead->setStyleSheet(QString::fromUtf8("background-color: lightblue;color: navyblue"));
        lblHead->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lblright = new QLabel(centralwidget);
        lblright->setObjectName("lblright");
        lblright->setGeometry(QRect(850, 70, 31, 491));
        lblright->setFont(font1);
        lblright->setStyleSheet(QString::fromUtf8("background-color: darkblue;color: white;"));
        lblright->setAlignment(Qt::AlignmentFlag::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        lblright->raise();
        widgetBack->raise();
        label_2->raise();
        label_3->raise();
        lineEdit->raise();
        lineEdit_2->raise();
        pushButton->raise();
        label_4->raise();
        lineEdit_3->raise();
        label_6->raise();
        pushButton_2->raise();
        lineEdit_4->raise();
        label_7->raise();
        lblHead->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 895, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "admin", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("MainWindow", "admin1", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "LOGIN", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Enter Password", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Register", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Enter Name", nullptr));
        lblright_2->setText(QString());
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Sign up", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Existing User ", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Existing User ", nullptr));
        lblHead->setText(QCoreApplication::translate("MainWindow", "SRM - eLerning", nullptr));
        lblright->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
