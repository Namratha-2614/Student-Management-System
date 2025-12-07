#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "tinyxml2.h"
#include "dashboard.h"
#include "globals.h"
#include "admindb.h"

using namespace tinyxml2;

// single global definitions
QString g_user  = "";
QString g_course = "";
int     g_score  = 0;
QString g_grade  = "";

QString fullPath2 = g_xmlPath + "users.xml";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton,   SIGNAL(clicked()), this, SLOT(loginBtn()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(registerBtn()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(signupBtn()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loginBtn()
{
    QString inputName = ui->lineEdit->text();
    QString inputPwd  = ui->lineEdit_2->text();

    if(inputName == "admin" && inputPwd == "admin1")
    {
        this->hide();
        adminDb adb(this);
        adb.exec();
        this->show();
    }
    else
    {
    XMLDocument doc;
    if (doc.LoadFile(fullPath2.toUtf8().constData()) != XML_SUCCESS) {
        QMessageBox::critical(this, "Error", "Could not open XML file!");
        return;
    }

    XMLElement* root     = doc.FirstChildElement("ELearningPlatform");
    XMLElement* students = root ? root->FirstChildElement("Students") : nullptr;
    if (!root || !students) {
        QMessageBox::critical(this, "Error", "Invalid XML structure");
        return;
    }

    XMLElement* studentElement = students->FirstChildElement("Student");
    bool found = false;

    while (studentElement) {
        XMLElement* nameElement = studentElement->FirstChildElement("Username");
        XMLElement* pwdElement  = studentElement->FirstChildElement("Password");

        if (!nameElement || !pwdElement) {
            studentElement = studentElement->NextSiblingElement("Student");
            continue;
        }

        QString name = nameElement->GetText();
        QString pwd  = pwdElement->GetText();
         if (inputName == name && inputPwd == pwd) {
            QMessageBox::information(this, "Welcome",
                                     "User: " + name + "\nWelcome to login management system!");

            found  = true;
            g_user = name;

            this->hide();
            Dashboard dash(this);      // IMPORTANT: parent = main window
            dash.exec();               // Dashboard runs
            this->show();              // show main window again when Dashboard closes
            break;
        }

        studentElement = studentElement->NextSiblingElement("Student");
    }

    if (!found) {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password");
    }
}
}

    void MainWindow::registerBtn()
    {
        QString newName = ui->lineEdit_3->text();
        QString newPwd  = ui->lineEdit_4->text();

        if (newName.isEmpty() || newPwd.isEmpty()) {
            QMessageBox::warning(this, "Input Error", "Name and password must not be empty.");
            return;
        }
        if(newName == "admin" && newPwd == "admin1")
        {
            QMessageBox::warning(this, "Input Error", "Name and password already exist.");
            return;
        }
        else
        {
        XMLDocument doc;
       // const char* filePath = "C:/My_Projects/Qt_eLrn_Adv/eLearn4/users.xml";

        if (doc.LoadFile(fullPath2.toUtf8().constData()) != XML_SUCCESS) {
            QMessageBox::critical(this, "Error", "Could not open XML file!");
            return;
        }

        XMLElement* root = doc.FirstChildElement("ELearningPlatform");
        if (!root) {
            QMessageBox::critical(this, "Error", "Invalid XML: Missing <ELearningPlatform>");
            return;
        }

        XMLElement* students = root->FirstChildElement("Students");
        if (!students) {
            QMessageBox::critical(this, "Error", "Invalid XML: Missing <Students>");
            return;
        }

        // ---------------------------------------------------------
        // CHECK DUPLICATE USERNAMES
        // ---------------------------------------------------------
        XMLElement* student = students->FirstChildElement("Student");
        while (student) {
            XMLElement* nameElement = student->FirstChildElement("Username");
            if (nameElement && newName == nameElement->GetText()) {
                QMessageBox::warning(this, "Register Error", "Username already exists!");
                return;
            }
            student = student->NextSiblingElement("Student");
        }

        // ---------------------------------------------------------
        // AUTO-GENERATE NEXT STUDENT ID
        // ---------------------------------------------------------
        int maxId = 0;
        student = students->FirstChildElement("Student");
        while (student) {
            const char* idAttr = student->Attribute("id");
            if (idAttr && idAttr[0] == 'S') {
                int idNum = QString(idAttr + 1).toInt();
                if (idNum > maxId) maxId = idNum;
            }
            student = student->NextSiblingElement("Student");
        }
        QString newStudentId = "S" + QString::number(maxId + 1).rightJustified(3, '0');

        // ---------------------------------------------------------
        // BUILD FULL ELEARNING STUDENT STRUCTURE
        // ---------------------------------------------------------
        XMLElement* newStudent = doc.NewElement("Student");
        newStudent->SetAttribute("id", newStudentId.toUtf8().constData());

        // Username
        XMLElement* username = doc.NewElement("Username");
        username->SetText(newName.toUtf8().constData());

        // Password
        XMLElement* password = doc.NewElement("Password");
        password->SetText(newPwd.toUtf8().constData());

        newStudent->InsertEndChild(username);
        newStudent->InsertEndChild(password);

        // ---------------------------------------------------------
        // EMPTY REGISTERED COURSES FOR NEW USER
        // (User will enroll later)
        // ---------------------------------------------------------
        XMLElement* regCourses = doc.NewElement("RegisteredCourses");
        newStudent->InsertEndChild(regCourses);

        // Append to XML
        students->InsertEndChild(newStudent);

        doc.SaveFile((g_xmlPath + "users.xml").toUtf8().constData());

        QMessageBox::information(this, "Registration Successful",
                                 "New user registered with ID: " + newStudentId);

        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();


    }
}


void MainWindow::signupBtn()
{
    ui->lineEdit_3->setEnabled(true);
    ui->lineEdit_4->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
    ui->label_7->setEnabled(true);
    ui->label_6->setEnabled(true);
}


void MainWindow::homeBtn()
{
    this->hide();
    Dashboard dash(this);
    dash.exec();
}

