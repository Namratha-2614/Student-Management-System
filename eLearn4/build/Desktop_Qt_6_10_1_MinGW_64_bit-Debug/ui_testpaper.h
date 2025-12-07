/********************************************************************************
** Form generated from reading UI file 'testpaper.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTPAPER_H
#define UI_TESTPAPER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_testPaper
{
public:
    QLabel *labelCourseName;
    QLabel *label_2;
    QLabel *lblQ1;
    QRadioButton *rb1A;
    QRadioButton *rb1B;
    QRadioButton *rb1C;
    QRadioButton *rb1D;
    QRadioButton *rb2C;
    QRadioButton *rb2A;
    QLabel *lblQ2;
    QRadioButton *rb2B;
    QLabel *label_5;
    QRadioButton *rb2D;
    QRadioButton *rb3C;
    QRadioButton *rb3A;
    QLabel *lblQ3;
    QRadioButton *rb3B;
    QLabel *label_7;
    QRadioButton *rb3D;
    QRadioButton *rb4C;
    QRadioButton *rb4A;
    QLabel *lblQ4;
    QRadioButton *rb4B;
    QLabel *label_9;
    QRadioButton *rb4D;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QButtonGroup *buttonGroup_3;
    QButtonGroup *buttonGroup;
    QButtonGroup *buttonGroup_2;
    QButtonGroup *buttonGroup_4;

    void setupUi(QDialog *testPaper)
    {
        if (testPaper->objectName().isEmpty())
            testPaper->setObjectName("testPaper");
        testPaper->resize(1115, 736);
        labelCourseName = new QLabel(testPaper);
        labelCourseName->setObjectName("labelCourseName");
        labelCourseName->setGeometry(QRect(340, 0, 371, 31));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        labelCourseName->setFont(font);
        labelCourseName->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2 = new QLabel(testPaper);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 40, 41, 31));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lblQ1 = new QLabel(testPaper);
        lblQ1->setObjectName("lblQ1");
        lblQ1->setGeometry(QRect(72, 40, 1021, 51));
        lblQ1->setStyleSheet(QString::fromUtf8("background-color: white;"));
        rb1A = new QRadioButton(testPaper);
        buttonGroup = new QButtonGroup(testPaper);
        buttonGroup->setObjectName("buttonGroup");
        buttonGroup->addButton(rb1A);
        rb1A->setObjectName("rb1A");
        rb1A->setGeometry(QRect(110, 100, 461, 41));
        rb1B = new QRadioButton(testPaper);
        buttonGroup->addButton(rb1B);
        rb1B->setObjectName("rb1B");
        rb1B->setGeometry(QRect(610, 100, 471, 41));
        rb1C = new QRadioButton(testPaper);
        buttonGroup->addButton(rb1C);
        rb1C->setObjectName("rb1C");
        rb1C->setGeometry(QRect(110, 140, 461, 41));
        rb1D = new QRadioButton(testPaper);
        buttonGroup->addButton(rb1D);
        rb1D->setObjectName("rb1D");
        rb1D->setGeometry(QRect(610, 140, 471, 41));
        rb2C = new QRadioButton(testPaper);
        buttonGroup_2 = new QButtonGroup(testPaper);
        buttonGroup_2->setObjectName("buttonGroup_2");
        buttonGroup_2->addButton(rb2C);
        rb2C->setObjectName("rb2C");
        rb2C->setGeometry(QRect(80, 310, 471, 41));
        rb2A = new QRadioButton(testPaper);
        buttonGroup_2->addButton(rb2A);
        rb2A->setObjectName("rb2A");
        rb2A->setGeometry(QRect(80, 270, 471, 41));
        lblQ2 = new QLabel(testPaper);
        lblQ2->setObjectName("lblQ2");
        lblQ2->setGeometry(QRect(72, 200, 1021, 51));
        lblQ2->setStyleSheet(QString::fromUtf8("background-color: white;"));
        rb2B = new QRadioButton(testPaper);
        buttonGroup_2->addButton(rb2B);
        rb2B->setObjectName("rb2B");
        rb2B->setGeometry(QRect(580, 270, 491, 41));
        label_5 = new QLabel(testPaper);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 200, 41, 31));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);
        rb2D = new QRadioButton(testPaper);
        buttonGroup_2->addButton(rb2D);
        rb2D->setObjectName("rb2D");
        rb2D->setGeometry(QRect(580, 310, 491, 41));
        rb3C = new QRadioButton(testPaper);
        buttonGroup_3 = new QButtonGroup(testPaper);
        buttonGroup_3->setObjectName("buttonGroup_3");
        buttonGroup_3->addButton(rb3C);
        rb3C->setObjectName("rb3C");
        rb3C->setGeometry(QRect(80, 470, 471, 41));
        rb3A = new QRadioButton(testPaper);
        buttonGroup_3->addButton(rb3A);
        rb3A->setObjectName("rb3A");
        rb3A->setGeometry(QRect(80, 430, 471, 41));
        lblQ3 = new QLabel(testPaper);
        lblQ3->setObjectName("lblQ3");
        lblQ3->setGeometry(QRect(72, 360, 1021, 51));
        lblQ3->setStyleSheet(QString::fromUtf8("background-color: white;"));
        rb3B = new QRadioButton(testPaper);
        buttonGroup_3->addButton(rb3B);
        rb3B->setObjectName("rb3B");
        rb3B->setGeometry(QRect(580, 430, 491, 41));
        label_7 = new QLabel(testPaper);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(30, 360, 41, 31));
        label_7->setFont(font1);
        label_7->setAlignment(Qt::AlignmentFlag::AlignCenter);
        rb3D = new QRadioButton(testPaper);
        buttonGroup_3->addButton(rb3D);
        rb3D->setObjectName("rb3D");
        rb3D->setGeometry(QRect(580, 470, 491, 41));
        rb4C = new QRadioButton(testPaper);
        buttonGroup_4 = new QButtonGroup(testPaper);
        buttonGroup_4->setObjectName("buttonGroup_4");
        buttonGroup_4->addButton(rb4C);
        rb4C->setObjectName("rb4C");
        rb4C->setGeometry(QRect(70, 630, 471, 41));
        rb4A = new QRadioButton(testPaper);
        buttonGroup_4->addButton(rb4A);
        rb4A->setObjectName("rb4A");
        rb4A->setGeometry(QRect(70, 590, 481, 41));
        lblQ4 = new QLabel(testPaper);
        lblQ4->setObjectName("lblQ4");
        lblQ4->setGeometry(QRect(62, 520, 1021, 51));
        lblQ4->setStyleSheet(QString::fromUtf8("background-color: white;"));
        rb4B = new QRadioButton(testPaper);
        buttonGroup_4->addButton(rb4B);
        rb4B->setObjectName("rb4B");
        rb4B->setGeometry(QRect(570, 590, 491, 41));
        label_9 = new QLabel(testPaper);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(20, 520, 41, 31));
        label_9->setFont(font1);
        label_9->setAlignment(Qt::AlignmentFlag::AlignCenter);
        rb4D = new QRadioButton(testPaper);
        buttonGroup_4->addButton(rb4D);
        rb4D->setObjectName("rb4D");
        rb4D->setGeometry(QRect(570, 630, 491, 41));
        pushButton = new QPushButton(testPaper);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(510, 680, 131, 41));
        pushButton->setFont(font1);
        pushButton_2 = new QPushButton(testPaper);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(830, 690, 93, 29));

        retranslateUi(testPaper);

        QMetaObject::connectSlotsByName(testPaper);
    } // setupUi

    void retranslateUi(QDialog *testPaper)
    {
        testPaper->setWindowTitle(QCoreApplication::translate("testPaper", "Dialog", nullptr));
        labelCourseName->setText(QCoreApplication::translate("testPaper", "C++", nullptr));
        label_2->setText(QCoreApplication::translate("testPaper", "Q1", nullptr));
        lblQ1->setText(QString());
        rb1A->setText(QCoreApplication::translate("testPaper", "RadioButton", nullptr));
        rb1B->setText(QCoreApplication::translate("testPaper", "RadioButton", nullptr));
        rb1C->setText(QCoreApplication::translate("testPaper", "RadioButton", nullptr));
        rb1D->setText(QCoreApplication::translate("testPaper", "RadioButton", nullptr));
        rb2C->setText(QCoreApplication::translate("testPaper", "RadioButton", nullptr));
        rb2A->setText(QCoreApplication::translate("testPaper", "RadioButton", nullptr));
        lblQ2->setText(QString());
        rb2B->setText(QCoreApplication::translate("testPaper", "RadioButton", nullptr));
        label_5->setText(QCoreApplication::translate("testPaper", "Q2", nullptr));
        rb2D->setText(QCoreApplication::translate("testPaper", "RadioButton", nullptr));
        rb3C->setText(QCoreApplication::translate("testPaper", "RadioButton", nullptr));
        rb3A->setText(QCoreApplication::translate("testPaper", "RadioButton", nullptr));
        lblQ3->setText(QString());
        rb3B->setText(QCoreApplication::translate("testPaper", "RadioButton", nullptr));
        label_7->setText(QCoreApplication::translate("testPaper", "Q3", nullptr));
        rb3D->setText(QCoreApplication::translate("testPaper", "RadioButton", nullptr));
        rb4C->setText(QCoreApplication::translate("testPaper", "RadioButton", nullptr));
        rb4A->setText(QCoreApplication::translate("testPaper", "RadioButton", nullptr));
        lblQ4->setText(QString());
        rb4B->setText(QCoreApplication::translate("testPaper", "RadioButton", nullptr));
        label_9->setText(QCoreApplication::translate("testPaper", "Q4", nullptr));
        rb4D->setText(QCoreApplication::translate("testPaper", "RadioButton", nullptr));
        pushButton->setText(QCoreApplication::translate("testPaper", "Submit", nullptr));
        pushButton_2->setText(QCoreApplication::translate("testPaper", "Dashboard", nullptr));
    } // retranslateUi

};

namespace Ui {
    class testPaper: public Ui_testPaper {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTPAPER_H
