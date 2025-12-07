#include "testpaper.h"
#include "ui_testpaper.h"
#include <tinyxml2.h>
#include <QMessageBox>
#include <QRandomGenerator>
#include <algorithm>
#include "globals.h"

QString fullPath1 = g_xmlPath + "testBank.xml";

using namespace tinyxml2;

struct QuizQ {
    QString text;
    QString optA, optB, optC, optD;
    QString answer;
};

QVector<QuizQ> allQ;
QuizQ selectedQ[4];

testPaper::testPaper(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::testPaper)
{
    ui->setupUi(this);
    ui->labelCourseName->setText(g_course);
    loadQuestions();
    fillUI();

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(testSubmitBtn()));
}

testPaper::~testPaper()
{
    delete ui;
}

void testPaper::loadQuestions()
{
    QString course = ui->labelCourseName->text().trimmed();

    XMLDocument doc;
    if (doc.LoadFile(fullPath1.toUtf8().constData()) != XML_SUCCESS) {
        QMessageBox::critical(this, "Error", "Cannot open testBank.xml");
        return;
    }

    XMLElement *root = doc.FirstChildElement("TestBank");
    if (!root) return;

    // Find matching course
    XMLElement *courseNode = nullptr;
    for (XMLElement *c = root->FirstChildElement("Course"); c; c = c->NextSiblingElement("Course"))
    {
        if (QString(c->Attribute("name")) == course) {
            courseNode = c;
            break;
        }
    }

    if (!courseNode) {
        QMessageBox::warning(this, "Not Found", "Course not found in XML");
        return;
    }

    // Extract questions
    allQ.clear(); // Ensure no stale data
    XMLElement *questionsNode = courseNode
                                    ->FirstChildElement("Test")
                                    ->FirstChildElement("Questions");

    for (XMLElement *q = questionsNode->FirstChildElement("Question"); q; q = q->NextSiblingElement("Question"))
    {
        QuizQ qq;
        qq.text = q->Attribute("text");

        XMLElement *opt = q->FirstChildElement("Option");
        while (opt) {
            QString tag = opt->Attribute("tag");
            QString val = QString(opt->GetText() ? opt->GetText() : "");

            if (tag == "A") qq.optA = val;
            if (tag == "B") qq.optB = val;
            if (tag == "C") qq.optC = val;
            if (tag == "D") qq.optD = val;

            opt = opt->NextSiblingElement("Option");
        }

        XMLElement *ansElem = q->FirstChildElement("Answer");
        qq.answer = ansElem && ansElem->GetText() ? QString(ansElem->GetText()) : "";

        allQ.push_back(qq);
    }

    // Out-of-bounds protection
    if (allQ.size() < 4) {
        QMessageBox::warning(this, "Error", "Insufficient questions loaded!");
        return;
    }

    // Shuffle using proper generator
    std::shuffle(allQ.begin(), allQ.end(), *QRandomGenerator::global());

    for (int i = 0; i < 4; i++)
        selectedQ[i] = allQ[i];
}

void testPaper::fillUI()
{
    // Q1
    ui->lblQ1->setText(selectedQ[0].text);
    ui->rb1A->setText(selectedQ[0].optA);
    ui->rb1B->setText(selectedQ[0].optB);
    ui->rb1C->setText(selectedQ[0].optC);
    ui->rb1D->setText(selectedQ[0].optD);

    // Q2
    ui->lblQ2->setText(selectedQ[1].text);
    ui->rb2A->setText(selectedQ[1].optA);
    ui->rb2B->setText(selectedQ[1].optB);
    ui->rb2C->setText(selectedQ[1].optC);
    ui->rb2D->setText(selectedQ[1].optD);

    // Q3
    ui->lblQ3->setText(selectedQ[2].text);
    ui->rb3A->setText(selectedQ[2].optA);
    ui->rb3B->setText(selectedQ[2].optB);
    ui->rb3C->setText(selectedQ[2].optC);
    ui->rb3D->setText(selectedQ[2].optD);

    // Q4
    ui->lblQ4->setText(selectedQ[3].text);
    ui->rb4A->setText(selectedQ[3].optA);
    ui->rb4B->setText(selectedQ[3].optB);
    ui->rb4C->setText(selectedQ[3].optC);
    ui->rb4D->setText(selectedQ[3].optD);
}

void testPaper::testSubmitBtn()
{
    int attempted = 0, correct = 0, wrong = 0;

    auto check = [&](int i, QRadioButton *A, QRadioButton *B,
                     QRadioButton *C, QRadioButton *D)
    {
        QString selected;

        if (A->isChecked())      selected = "A";
        else if (B->isChecked()) selected = "B";
        else if (C->isChecked()) selected = "C";
        else if (D->isChecked()) selected = "D";

        if (selected.isEmpty())
            return; // not attempted

        attempted++;

        if (selected == selectedQ[i].answer)
            correct++;
        else
            wrong++;
    };

    check(0, ui->rb1A, ui->rb1B, ui->rb1C, ui->rb1D);
    check(1, ui->rb2A, ui->rb2B, ui->rb2C, ui->rb2D);
    check(2, ui->rb3A, ui->rb3B, ui->rb3C, ui->rb3D);
    check(3, ui->rb4A, ui->rb4B, ui->rb4C, ui->rb4D);

    QMessageBox::information(this, "Result",
                             "Attempted: " + QString::number(attempted) + "\n"
                                                                          "Correct: "   + QString::number(correct)   + "\n"
                                                              "Wrong: "     + QString::number(wrong));

    // compute percentage and grade
    double total = (correct / 4.0) * 100.0;
    g_score = static_cast<int>(total + 0.5);   // round to nearest int

    if (total > 75)
        g_grade = "A";
    else if (total > 50)
        g_grade = "B";
    else if (total > 25)
        g_grade = "C";
    else
        g_grade = "F";

    if (g_grade == "A" || g_grade == "B" || g_grade == "C") {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Congratulations");
        msgBox.setText("You have passed with grade " + g_grade);
        msgBox.setMinimumSize(800, 400);
        msgBox.exec();
    } else {
        QMessageBox msgBox;
        msgBox.setWindowTitle("You are not qualified");
        msgBox.setText("Your grade is " + g_grade);
        msgBox.setMinimumSize(800, 400);
        msgBox.exec();
    }

    // VERY IMPORTANT: close dialog and return to Dashboard
    accept();   // returns QDialog::Accepted to caller
}
