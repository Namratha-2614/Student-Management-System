/********************************************************************************
** Form generated from reading UI file 'admindb.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINDB_H
#define UI_ADMINDB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_adminDb
{
public:
    QLabel *label;
    QTableWidget *tableWidget;

    void setupUi(QDialog *adminDb)
    {
        if (adminDb->objectName().isEmpty())
            adminDb->setObjectName("adminDb");
        adminDb->resize(1362, 572);
        label = new QLabel(adminDb);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 10, 1361, 61));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        label->setFont(font);
        label->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label->setStyleSheet(QString::fromUtf8("background-color: lightblue;color: navyblue"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        tableWidget = new QTableWidget(adminDb);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(20, 91, 1341, 461));

        retranslateUi(adminDb);

        QMetaObject::connectSlotsByName(adminDb);
    } // setupUi

    void retranslateUi(QDialog *adminDb)
    {
        adminDb->setWindowTitle(QCoreApplication::translate("adminDb", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("adminDb", "SRM - Student Management System", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adminDb: public Ui_adminDb {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINDB_H
