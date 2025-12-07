/********************************************************************************
** Form generated from reading UI file 'dashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DASHBOARD_H
#define UI_DASHBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dashboard
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QWidget *widget;
    QLabel *label_2;
    QLabel *lblCourse1;
    QLabel *lblCourse2;
    QLabel *lblCourse3;
    QPushButton *pushButton_2;
    QWidget *widget_2;
    QLabel *label_3;
    QLabel *lblTest1;
    QLabel *lblTest2;
    QLabel *lblTest3;
    QLabel *lblTest4;
    QLabel *lblTest5;
    QLabel *lblTest6;
    QPushButton *pushButton_3;
    QWidget *widget_4;
    QLabel *label_4;
    QLabel *lblScoreTest4;
    QLabel *lblScoreTest2;
    QLabel *lblScoreTest6;
    QLabel *lblScoreTest3;
    QLabel *lblScoreTest1;
    QLabel *lblScoreTest5;
    QLabel *lblGrade1;
    QLabel *lblGrade2;
    QLabel *lblGrade3;
    QLabel *lblGrade4;
    QLabel *lblGrade5;
    QLabel *lblGrade6;
    QPushButton *pushButton_4;
    QWidget *widget_3;
    QLabel *label_5;
    QLabel *lblCertCourse3;
    QLabel *lblCertCourse1;
    QLabel *lblCertCourse2;
    QLabel *lblCertDate1;
    QLabel *lblCertDate2;
    QLabel *lblCertDate3;

    void setupUi(QDialog *Dashboard)
    {
        if (Dashboard->objectName().isEmpty())
            Dashboard->setObjectName("Dashboard");
        Dashboard->resize(885, 648);
        label = new QLabel(Dashboard);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 10, 891, 61));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        label->setFont(font);
        label->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label->setStyleSheet(QString::fromUtf8("background-color: lightblue;color: navyblue"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pushButton = new QPushButton(Dashboard);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(710, 600, 151, 41));
        widget = new QWidget(Dashboard);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(20, 101, 261, 331));
        widget->setStyleSheet(QString::fromUtf8("background-color: lightblue;"));
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 0, 261, 41));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("background-color: darkblue;color: white;"));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lblCourse1 = new QLabel(widget);
        lblCourse1->setObjectName("lblCourse1");
        lblCourse1->setGeometry(QRect(30, 81, 161, 31));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        lblCourse1->setFont(font2);
        lblCourse1->setStyleSheet(QString::fromUtf8("background-color: darkblue;color: white;"));
        lblCourse1->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lblCourse2 = new QLabel(widget);
        lblCourse2->setObjectName("lblCourse2");
        lblCourse2->setGeometry(QRect(30, 140, 161, 31));
        lblCourse2->setFont(font2);
        lblCourse2->setStyleSheet(QString::fromUtf8("background-color: darkblue;color: white;"));
        lblCourse2->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lblCourse3 = new QLabel(widget);
        lblCourse3->setObjectName("lblCourse3");
        lblCourse3->setGeometry(QRect(30, 200, 161, 31));
        lblCourse3->setFont(font2);
        lblCourse3->setStyleSheet(QString::fromUtf8("background-color: darkblue;color: white;"));
        lblCourse3->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(60, 280, 191, 31));
        QFont font3;
        font3.setPointSize(11);
        font3.setBold(false);
        pushButton_2->setFont(font3);
        widget_2 = new QWidget(Dashboard);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(310, 101, 261, 331));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: lightblue;"));
        label_3 = new QLabel(widget_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 0, 261, 41));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("background-color: darkblue;color: white;"));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lblTest1 = new QLabel(widget_2);
        lblTest1->setObjectName("lblTest1");
        lblTest1->setGeometry(QRect(20, 70, 141, 21));
        QFont font4;
        font4.setPointSize(11);
        font4.setBold(true);
        lblTest1->setFont(font4);
        lblTest1->setStyleSheet(QString::fromUtf8("background-color: darkblue;color: white;"));
        lblTest1->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lblTest2 = new QLabel(widget_2);
        lblTest2->setObjectName("lblTest2");
        lblTest2->setGeometry(QRect(20, 100, 141, 21));
        lblTest2->setFont(font4);
        lblTest2->setStyleSheet(QString::fromUtf8("background-color: darkblue;color: white;"));
        lblTest2->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lblTest3 = new QLabel(widget_2);
        lblTest3->setObjectName("lblTest3");
        lblTest3->setGeometry(QRect(20, 130, 141, 21));
        lblTest3->setFont(font4);
        lblTest3->setStyleSheet(QString::fromUtf8("background-color: darkblue;color: white;"));
        lblTest3->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lblTest4 = new QLabel(widget_2);
        lblTest4->setObjectName("lblTest4");
        lblTest4->setGeometry(QRect(20, 160, 141, 21));
        lblTest4->setFont(font4);
        lblTest4->setStyleSheet(QString::fromUtf8("background-color: darkblue;color: white;"));
        lblTest4->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lblTest5 = new QLabel(widget_2);
        lblTest5->setObjectName("lblTest5");
        lblTest5->setGeometry(QRect(20, 190, 141, 21));
        lblTest5->setFont(font4);
        lblTest5->setStyleSheet(QString::fromUtf8("background-color: darkblue;color: white;"));
        lblTest5->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lblTest6 = new QLabel(widget_2);
        lblTest6->setObjectName("lblTest6");
        lblTest6->setGeometry(QRect(20, 220, 141, 21));
        lblTest6->setFont(font4);
        lblTest6->setStyleSheet(QString::fromUtf8("background-color: darkblue;color: white;"));
        lblTest6->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        pushButton_3 = new QPushButton(widget_2);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(122, 278, 121, 31));
        pushButton_3->setFont(font3);
        widget_4 = new QWidget(Dashboard);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(600, 100, 261, 331));
        widget_4->setStyleSheet(QString::fromUtf8("background-color: lightblue;"));
        label_4 = new QLabel(widget_4);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(0, 0, 261, 41));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("background-color: darkblue;color: white;"));
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lblScoreTest4 = new QLabel(widget_4);
        lblScoreTest4->setObjectName("lblScoreTest4");
        lblScoreTest4->setGeometry(QRect(20, 160, 141, 21));
        lblScoreTest4->setFont(font4);
        lblScoreTest4->setStyleSheet(QString::fromUtf8("background-color: darkblue;color: white;"));
        lblScoreTest4->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lblScoreTest2 = new QLabel(widget_4);
        lblScoreTest2->setObjectName("lblScoreTest2");
        lblScoreTest2->setGeometry(QRect(20, 100, 141, 21));
        lblScoreTest2->setFont(font4);
        lblScoreTest2->setStyleSheet(QString::fromUtf8("background-color: darkblue;color: white;"));
        lblScoreTest2->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lblScoreTest6 = new QLabel(widget_4);
        lblScoreTest6->setObjectName("lblScoreTest6");
        lblScoreTest6->setGeometry(QRect(20, 220, 141, 21));
        lblScoreTest6->setFont(font4);
        lblScoreTest6->setStyleSheet(QString::fromUtf8("background-color: darkblue;color: white;"));
        lblScoreTest6->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lblScoreTest3 = new QLabel(widget_4);
        lblScoreTest3->setObjectName("lblScoreTest3");
        lblScoreTest3->setGeometry(QRect(20, 130, 141, 21));
        lblScoreTest3->setFont(font4);
        lblScoreTest3->setStyleSheet(QString::fromUtf8("background-color: darkblue;color: white;"));
        lblScoreTest3->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lblScoreTest1 = new QLabel(widget_4);
        lblScoreTest1->setObjectName("lblScoreTest1");
        lblScoreTest1->setGeometry(QRect(20, 70, 141, 21));
        lblScoreTest1->setFont(font4);
        lblScoreTest1->setStyleSheet(QString::fromUtf8("background-color: darkblue;color: white;"));
        lblScoreTest1->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lblScoreTest5 = new QLabel(widget_4);
        lblScoreTest5->setObjectName("lblScoreTest5");
        lblScoreTest5->setGeometry(QRect(20, 190, 141, 21));
        lblScoreTest5->setFont(font4);
        lblScoreTest5->setStyleSheet(QString::fromUtf8("background-color: darkblue;color: white;"));
        lblScoreTest5->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lblGrade1 = new QLabel(widget_4);
        lblGrade1->setObjectName("lblGrade1");
        lblGrade1->setGeometry(QRect(200, 70, 41, 20));
        QFont font5;
        font5.setPointSize(9);
        font5.setBold(true);
        lblGrade1->setFont(font5);
        lblGrade1->setStyleSheet(QString::fromUtf8("background-color: red;color: white;"));
        lblGrade1->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lblGrade2 = new QLabel(widget_4);
        lblGrade2->setObjectName("lblGrade2");
        lblGrade2->setGeometry(QRect(200, 100, 41, 20));
        lblGrade2->setFont(font5);
        lblGrade2->setStyleSheet(QString::fromUtf8("background-color: red;color: white;"));
        lblGrade2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lblGrade3 = new QLabel(widget_4);
        lblGrade3->setObjectName("lblGrade3");
        lblGrade3->setGeometry(QRect(200, 130, 41, 20));
        lblGrade3->setFont(font5);
        lblGrade3->setStyleSheet(QString::fromUtf8("background-color: red;color: white;"));
        lblGrade3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lblGrade4 = new QLabel(widget_4);
        lblGrade4->setObjectName("lblGrade4");
        lblGrade4->setGeometry(QRect(200, 160, 41, 20));
        lblGrade4->setFont(font5);
        lblGrade4->setStyleSheet(QString::fromUtf8("background-color: red;color: white;"));
        lblGrade4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lblGrade5 = new QLabel(widget_4);
        lblGrade5->setObjectName("lblGrade5");
        lblGrade5->setGeometry(QRect(200, 190, 41, 20));
        lblGrade5->setFont(font5);
        lblGrade5->setStyleSheet(QString::fromUtf8("background-color: red;color: white;"));
        lblGrade5->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lblGrade6 = new QLabel(widget_4);
        lblGrade6->setObjectName("lblGrade6");
        lblGrade6->setGeometry(QRect(200, 220, 41, 20));
        lblGrade6->setFont(font5);
        lblGrade6->setStyleSheet(QString::fromUtf8("background-color: red;color: white;"));
        lblGrade6->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pushButton_4 = new QPushButton(widget_4);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(142, 280, 111, 29));
        QFont font6;
        font6.setPointSize(11);
        pushButton_4->setFont(font6);
        widget_3 = new QWidget(Dashboard);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(20, 450, 841, 141));
        widget_3->setStyleSheet(QString::fromUtf8("background-color: lightblue;"));
        label_5 = new QLabel(widget_3);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(0, 0, 261, 141));
        label_5->setFont(font1);
        label_5->setStyleSheet(QString::fromUtf8("background-color: darkblue;color: white;"));
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lblCertCourse3 = new QLabel(widget_3);
        lblCertCourse3->setObjectName("lblCertCourse3");
        lblCertCourse3->setGeometry(QRect(270, 100, 161, 31));
        lblCertCourse3->setFont(font2);
        lblCertCourse3->setStyleSheet(QString::fromUtf8("background-color: darkblue;color: white;"));
        lblCertCourse3->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lblCertCourse1 = new QLabel(widget_3);
        lblCertCourse1->setObjectName("lblCertCourse1");
        lblCertCourse1->setGeometry(QRect(270, 20, 161, 31));
        lblCertCourse1->setFont(font2);
        lblCertCourse1->setStyleSheet(QString::fromUtf8("background-color: darkblue;color: white;"));
        lblCertCourse1->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lblCertCourse2 = new QLabel(widget_3);
        lblCertCourse2->setObjectName("lblCertCourse2");
        lblCertCourse2->setGeometry(QRect(270, 60, 161, 31));
        lblCertCourse2->setFont(font2);
        lblCertCourse2->setStyleSheet(QString::fromUtf8("background-color: darkblue;color: white;"));
        lblCertCourse2->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lblCertDate1 = new QLabel(widget_3);
        lblCertDate1->setObjectName("lblCertDate1");
        lblCertDate1->setGeometry(QRect(490, 20, 111, 31));
        lblCertDate1->setFont(font2);
        lblCertDate1->setStyleSheet(QString::fromUtf8("background-color: darkblue;color: white;"));
        lblCertDate1->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lblCertDate2 = new QLabel(widget_3);
        lblCertDate2->setObjectName("lblCertDate2");
        lblCertDate2->setGeometry(QRect(490, 60, 111, 31));
        lblCertDate2->setFont(font2);
        lblCertDate2->setStyleSheet(QString::fromUtf8("background-color: darkblue;color: white;"));
        lblCertDate2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lblCertDate3 = new QLabel(widget_3);
        lblCertDate3->setObjectName("lblCertDate3");
        lblCertDate3->setGeometry(QRect(490, 100, 111, 31));
        lblCertDate3->setFont(font2);
        lblCertDate3->setStyleSheet(QString::fromUtf8("background-color: darkblue;color: white;"));
        lblCertDate3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        widget->raise();
        label->raise();
        pushButton->raise();
        widget_2->raise();
        widget_4->raise();
        widget_3->raise();

        retranslateUi(Dashboard);

        QMetaObject::connectSlotsByName(Dashboard);
    } // setupUi

    void retranslateUi(QDialog *Dashboard)
    {
        Dashboard->setWindowTitle(QCoreApplication::translate("Dashboard", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dashboard", "Dashboard", nullptr));
        pushButton->setText(QCoreApplication::translate("Dashboard", "Go to home page", nullptr));
        label_2->setText(QCoreApplication::translate("Dashboard", "Enrolled Courses", nullptr));
        lblCourse1->setText(QCoreApplication::translate("Dashboard", "C++", nullptr));
        lblCourse2->setText(QCoreApplication::translate("Dashboard", "Python", nullptr));
        lblCourse3->setText(QCoreApplication::translate("Dashboard", "Java", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Dashboard", "Enroll for new course", nullptr));
        label_3->setText(QCoreApplication::translate("Dashboard", "Tests completed", nullptr));
        lblTest1->setText(QCoreApplication::translate("Dashboard", "T1 (C++)", nullptr));
        lblTest2->setText(QCoreApplication::translate("Dashboard", "T2 (C++)", nullptr));
        lblTest3->setText(QCoreApplication::translate("Dashboard", "T1 (Python)", nullptr));
        lblTest4->setText(QCoreApplication::translate("Dashboard", "T2 (Python)", nullptr));
        lblTest5->setText(QCoreApplication::translate("Dashboard", "T1 (Java)", nullptr));
        lblTest6->setText(QCoreApplication::translate("Dashboard", "T2 (Java)", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Dashboard", "Take Test", nullptr));
        label_4->setText(QCoreApplication::translate("Dashboard", "Score card", nullptr));
        lblScoreTest4->setText(QCoreApplication::translate("Dashboard", "T2 (Python)", nullptr));
        lblScoreTest2->setText(QCoreApplication::translate("Dashboard", "T2 (C++)", nullptr));
        lblScoreTest6->setText(QCoreApplication::translate("Dashboard", "T2 (Java)", nullptr));
        lblScoreTest3->setText(QCoreApplication::translate("Dashboard", "T1 (Python)", nullptr));
        lblScoreTest1->setText(QCoreApplication::translate("Dashboard", "T1 (C++)", nullptr));
        lblScoreTest5->setText(QCoreApplication::translate("Dashboard", "T1 (Java)", nullptr));
        lblGrade1->setText(QCoreApplication::translate("Dashboard", "A", nullptr));
        lblGrade2->setText(QCoreApplication::translate("Dashboard", "A", nullptr));
        lblGrade3->setText(QCoreApplication::translate("Dashboard", "A", nullptr));
        lblGrade4->setText(QCoreApplication::translate("Dashboard", "A", nullptr));
        lblGrade5->setText(QCoreApplication::translate("Dashboard", "A", nullptr));
        lblGrade6->setText(QCoreApplication::translate("Dashboard", "A", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Dashboard", "View", nullptr));
        label_5->setText(QCoreApplication::translate("Dashboard", "Certificates(Issued on)", nullptr));
        lblCertCourse3->setText(QCoreApplication::translate("Dashboard", "Java", nullptr));
        lblCertCourse1->setText(QCoreApplication::translate("Dashboard", "C++", nullptr));
        lblCertCourse2->setText(QCoreApplication::translate("Dashboard", "Python", nullptr));
        lblCertDate1->setText(QCoreApplication::translate("Dashboard", "Date", nullptr));
        lblCertDate2->setText(QCoreApplication::translate("Dashboard", "Date", nullptr));
        lblCertDate3->setText(QCoreApplication::translate("Dashboard", "Date", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dashboard: public Ui_Dashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHBOARD_H
