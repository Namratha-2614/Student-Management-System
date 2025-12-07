#include "dashboard.h"
#include "ui_dashboard.h"
#include "globals.h"
#include "tinyxml2.h"
#include "QMessageBox"
#include "QInputDialog"
#include "testpaper.h"
#include <QDate>

using namespace tinyxml2;
QString fullPath = g_xmlPath + "users.xml";

Dashboard::Dashboard(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dashboard)
{
    ui->setupUi(this);
    populateDashboard(g_user);
    ui->label->setText(g_user + "'s Dashboard");

    connect(ui->pushButton_2, SIGNAL(clicked()),
            this, SLOT(enrollCourseBtn()));
    connect(ui->pushButton_3, SIGNAL(clicked()),
            this, SLOT(takeTestBtn()));
}

void Dashboard::populateDashboard(const QString& username)
{
    XMLDocument doc;
    if (doc.LoadFile(fullPath.toUtf8().constData()) != XML_SUCCESS)
        return;

    XMLElement* root = doc.FirstChildElement("ELearningPlatform");
    if (!root) return;

    XMLElement* students = root->FirstChildElement("Students");
    XMLElement* allCourses = root->FirstChildElement("Courses");

    // -----------------------------------------------------
    //  FIND LOGGED-IN STUDENT
    // -----------------------------------------------------
    XMLElement* student = students->FirstChildElement("Student");
    XMLElement* matched = nullptr;

    while (student)
    {
        XMLElement* u = student->FirstChildElement("Username");
        if (u && u->GetText() &&
            QString(u->GetText()) == username)
        {
            matched = student;
            break;
        }
        student = student->NextSiblingElement("Student");
    }

    if (!matched) return;

    // -----------------------------------------------------
    //  ACCUMULATE DASHBOARD DATA
    // -----------------------------------------------------
    QVector<QString> courseNames;
    QVector<QString> testsCompleted;
    QVector<QString> scoreTests;
    QVector<QString> scoreGrades;
    QVector<QString> certCourseList;
    QVector<QString> certDateList;

    XMLElement* regCourses = matched->FirstChildElement("RegisteredCourses");
    XMLElement* reg = regCourses ?
                          regCourses->FirstChildElement("CourseRegistration")
                                 : nullptr;

    while (reg)
    {
        QString cid = reg->Attribute("courseId");

        // -------------------------------
        //  COURSE NAME
        // -------------------------------
        QString courseName = "Unknown";
        XMLElement* cr = allCourses->FirstChildElement("Course");
        while (cr)
        {
            if (QString(cr->Attribute("id")) == cid)
            {
                courseName = cr->FirstChildElement("Name")->GetText();
                break;
            }
            cr = cr->NextSiblingElement("Course");
        }
        courseNames.append(courseName);

        // -------------------------------
        //  BUILD testId → type MAP
        // -------------------------------
        QMap<QString, QString> testTypeMap;

        XMLElement* cr2 = allCourses->FirstChildElement("Course");
        while (cr2)
        {
            if (QString(cr2->Attribute("id")) == cid)
            {
                XMLElement* tests = cr2->FirstChildElement("Tests");
                XMLElement* t = tests->FirstChildElement("Test");

                while (t)
                {
                    testTypeMap[t->Attribute("id")] =
                        t->Attribute("type");
                    t = t->NextSiblingElement("Test");
                }
                break;
            }
            cr2 = cr2->NextSiblingElement("Course");
        }

        // -------------------------------
        //  COUNT ATTEMPTS + GET LATEST
        // -------------------------------
        QMap<QString, int> attemptsCount;
        QMap<QString, QString> latestGrade;
        QMap<QString, QString> latestScore;

        XMLElement* testRegs = reg->FirstChildElement("TestRegistrations");
        if (testRegs)
        {
            XMLElement* t = testRegs->FirstChildElement("TestRegistration");

            while (t)
            {
                QString tid = t->Attribute("testId");

                attemptsCount[tid] = attemptsCount.value(tid, 0) + 1;

                XMLElement* gEl = t->FirstChildElement("Grade");
                XMLElement* sEl = t->FirstChildElement("Score");

                if (gEl && gEl->GetText())
                    latestGrade[tid] = gEl->GetText();

                if (sEl && sEl->GetText())
                    latestScore[tid] = sEl->GetText();

                t = t->NextSiblingElement("TestRegistration");
            }

            // Build dashboard labels
            QMapIterator<QString, int> it(attemptsCount);
            while (it.hasNext())
            {
                it.next();
                QString tid = it.key();
                int attempts = it.value();

                QString ttype = testTypeMap.value(tid);
                QString labelFull =
                    ttype + " (" + courseName + ") (" +
                    QString::number(attempts) + ")";

                testsCompleted.append(labelFull);

                scoreTests.append(ttype + " (" + courseName + ")");
                scoreGrades.append(latestGrade.value(tid, ""));
            }
        }

        // -------------------------------
        //  CERTIFICATES
        // -------------------------------
        certCourseList.append(courseName);

        XMLElement* cert = reg->FirstChildElement("Certificate");
        if (!cert)
        {
            certDateList.append("Pending");
        }
        else
        {
            QString status = cert->FirstChildElement("Status")->GetText();

            if (status == "Issued")
            {
                certDateList.append(
                    cert->FirstChildElement("IssueDate")->GetText()
                    );
            }
            else
            {
                certDateList.append("Pending");
            }
        }

        reg = reg->NextSiblingElement("CourseRegistration");
    }

    // -----------------------------------------------------
    // UPDATE UI
    // -----------------------------------------------------
    ui->lblCourse1->setText(courseNames.value(0, ""));
    ui->lblCourse2->setText(courseNames.value(1, ""));
    ui->lblCourse3->setText(courseNames.value(2, ""));

    ui->lblTest1->setText(testsCompleted.value(0, ""));
    ui->lblTest2->setText(testsCompleted.value(1, ""));
    ui->lblTest3->setText(testsCompleted.value(2, ""));
    ui->lblTest4->setText(testsCompleted.value(3, ""));
    ui->lblTest5->setText(testsCompleted.value(4, ""));
    ui->lblTest6->setText(testsCompleted.value(5, ""));

    ui->lblScoreTest1->setText(scoreTests.value(0, ""));
    ui->lblGrade1->setText(scoreGrades.value(0, ""));

    ui->lblScoreTest2->setText(scoreTests.value(1, ""));
    ui->lblGrade2->setText(scoreGrades.value(1, ""));

    ui->lblScoreTest3->setText(scoreTests.value(2, ""));
    ui->lblGrade3->setText(scoreGrades.value(2, ""));

    ui->lblScoreTest4->setText(scoreTests.value(3, ""));
    ui->lblGrade4->setText(scoreGrades.value(3, ""));

    ui->lblScoreTest5->setText(scoreTests.value(4, ""));
    ui->lblGrade5->setText(scoreGrades.value(4, ""));

    ui->lblScoreTest6->setText(scoreTests.value(5, ""));
    ui->lblGrade6->setText(scoreGrades.value(5, ""));

    ui->lblCertCourse1->setText(certCourseList.value(0, ""));
    ui->lblCertDate1->setText(certDateList.value(0, ""));

    ui->lblCertCourse2->setText(certCourseList.value(1, ""));
    ui->lblCertDate2->setText(certDateList.value(1, ""));

    ui->lblCertCourse3->setText(certCourseList.value(2, ""));
    ui->lblCertDate3->setText(certDateList.value(2, ""));
}
Dashboard::~Dashboard()
{
    delete ui;
}

void Dashboard::on_pushButton_clicked()
{
    this->close();
    if (parentWidget())
        parentWidget()->show();
}

void Dashboard::enrollCourseBtn()
{
    //QString filePath = "C:/My_Projects/Qt_eLrn_Adv/eLearn4/users.xml";

    XMLDocument doc;
    if (doc.LoadFile(fullPath.toUtf8().constData()) != XML_SUCCESS) {
        QMessageBox::critical(this, "Error", "Cannot open XML file");
        return;
    }

    XMLElement* root = doc.FirstChildElement("ELearningPlatform");
    XMLElement* adminCourses = root->FirstChildElement("Courses");
    XMLElement* students = root->FirstChildElement("Students");

    // FIND STUDENT
    XMLElement* student = students->FirstChildElement("Student");
    XMLElement* st = nullptr;

    while (student) {
        if (QString(student->FirstChildElement("Username")->GetText()) == g_user) {
            st = student;
            break;
        }
        student = student->NextSiblingElement("Student");
    }
    if (!st) return;

    // Ensure <RegisteredCourses>
    XMLElement* regCourses = st->FirstChildElement("RegisteredCourses");
    if (!regCourses) {
        regCourses = doc.NewElement("RegisteredCourses");
        st->InsertEndChild(regCourses);
    }

    // Already-enrolled courses
    QSet<QString> enrolled;
    XMLElement* rc = regCourses->FirstChildElement("CourseRegistration");

    while (rc) {
        enrolled.insert(QString(rc->Attribute("courseId")));
        rc = rc->NextSiblingElement("CourseRegistration");
    }

    // Prepare available courses
    QStringList options;
    QMap<QString, QString> nameToId;

    XMLElement* c = adminCourses->FirstChildElement("Course");
    while (c) {
        QString id = c->Attribute("id");
        QString nm = c->FirstChildElement("Name")->GetText();

        if (!enrolled.contains(id)) {
            options.append(nm);
            nameToId[nm] = id;
        }
        c = c->NextSiblingElement("Course");
    }

    if (options.isEmpty()) {
        QMessageBox::information(this, "Done", "You are enrolled in all courses.");
        return;
    }

    bool ok;
    QString picked = QInputDialog::getItem(
        this, "Enroll", "Pick Course:", options, 0, false, &ok);

    if (!ok || picked.isEmpty()) return;

    QString pickedId = nameToId[picked];

    // Create new <CourseRegistration>
    XMLElement* newReg = doc.NewElement("CourseRegistration");
    newReg->SetAttribute("courseId", pickedId.toUtf8().constData());

    XMLElement* regDate = doc.NewElement("RegistrationDate");
    regDate->SetText(QDate::currentDate().toString("yyyy-MM-dd").toUtf8().constData());
    newReg->InsertEndChild(regDate);

    XMLElement* tests = doc.NewElement("TestRegistrations");
    newReg->InsertEndChild(tests);

    XMLElement* cert = doc.NewElement("Certificate");
    XMLElement* s = doc.NewElement("Status");
    s->SetText("Pending");
    cert->InsertEndChild(s);
    newReg->InsertEndChild(cert);

    regCourses->InsertEndChild(newReg);
    doc.SaveFile((g_xmlPath + "users.xml").toUtf8().constData());

    QMessageBox::information(this, "Success", "Enrolled in: " + picked);
    populateDashboard(g_user);
}

void Dashboard::takeTestBtn()
{
   // QString filePath = "C:/My_Projects/Qt_eLrn_Adv/eLearn4/users.xml";

    XMLDocument doc;
    if (doc.LoadFile(fullPath.toUtf8().constData()) != XML_SUCCESS) {
        QMessageBox::critical(this, "Error", "Cannot open XML file");
        return;
    }

    XMLElement* root = doc.FirstChildElement("ELearningPlatform");
    XMLElement* adminCourses = root->FirstChildElement("Courses");
    XMLElement* students = root->FirstChildElement("Students");

    // FIND STUDENT
    XMLElement* st = students->FirstChildElement("Student");
    while (st) {
        XMLElement* u = st->FirstChildElement("Username");
        if (u && u->GetText() && QString(u->GetText()) == g_user)
            break;
        st = st->NextSiblingElement("Student");
    }
    if (!st) return;

    XMLElement* regCourses = st->FirstChildElement("RegisteredCourses");
    if (!regCourses) return;

    // Build list of pending tests
    QStringList listTests;
    struct Info { QString cid, tid, label, cname; };
    QVector<Info> testsVector;

    XMLElement* rc = regCourses->FirstChildElement("CourseRegistration");
    while (rc)
    {
        QString cid = rc->Attribute("courseId");

        XMLElement* ac = adminCourses->FirstChildElement("Course");
        while (ac)
        {
            if (QString(ac->Attribute("id")) == cid)
            {
                QString cname = ac->FirstChildElement("Name")->GetText();
                XMLElement* testsNode = ac->FirstChildElement("Tests");
                XMLElement* t = testsNode->FirstChildElement("Test");

                while (t)
                {
                    QString tid = t->Attribute("id");
                    QString ttype = t->Attribute("type");

                    int attempts = 0;
                    QString latestGrade = "";

                    XMLElement* trNode = rc->FirstChildElement("TestRegistrations");
                    XMLElement* trCheck = trNode ?
                                              trNode->FirstChildElement("TestRegistration") : nullptr;

                    while (trCheck)
                    {
                        if (QString(trCheck->Attribute("testId")) == tid)
                        {
                            attempts++;
                            XMLElement* gEl = trCheck->FirstChildElement("Grade");
                            if (gEl && gEl->GetText())
                                latestGrade = gEl->GetText();
                        }
                        trCheck = trCheck->NextSiblingElement("TestRegistration");
                    }

                    if (attempts == 0)
                    {
                        QString lbl = ttype + " (" + cname + ")";
                        listTests.append(lbl);
                        testsVector.append({cid, tid, lbl, cname});
                    }
                    else if (attempts == 1 && latestGrade == "F")
                    {
                        QString lbl = ttype + " (" + cname + ") - Second Attempt";
                        listTests.append(lbl);
                        testsVector.append({cid, tid, lbl, cname});
                    }

                    t = t->NextSiblingElement("Test");
                }
                break;
            }

            ac = ac->NextSiblingElement("Course");
        }
        rc = rc->NextSiblingElement("CourseRegistration");
    }

    if (listTests.isEmpty()) {
        QMessageBox::information(this, "Done", "No pending tests.");
        return;
    }

    bool ok;
    QString picked = QInputDialog::getItem(
        this, "Take Test", "Select a Test:", listTests, 0, false, &ok);

    if (!ok || picked.isEmpty()) return;

    QString cid, tid, cname;

    for (const auto &i : testsVector)
    {
        if (picked.startsWith(i.label))
        {
            cid = i.cid;
            tid = i.tid;
            cname = i.cname;
            g_course = cname;
            break;
        }
    }

    // Run test
    testPaper paper(this);
    if (paper.exec() != QDialog::Accepted)
        return;

    // Save test attempt
    XMLElement* st2 = students->FirstChildElement("Student");
    while (st2)
    {
        XMLElement* u = st2->FirstChildElement("Username");
        if (u && u->GetText() && QString(u->GetText()) == g_user)
            break;
        st2 = st2->NextSiblingElement("Student");
    }
    if (!st2) return;

    XMLElement* rc2 = st2->FirstChildElement("RegisteredCourses");
    XMLElement* cr = rc2->FirstChildElement("CourseRegistration");
    while (cr) {
        if (QString(cr->Attribute("courseId")) == cid)
            break;
        cr = cr->NextSiblingElement("CourseRegistration");
    }
    if (!cr) return;

    XMLElement* tr = cr->FirstChildElement("TestRegistrations");
    if (!tr)
    {
        tr = doc.NewElement("TestRegistrations");
        cr->InsertEndChild(tr);
    }

    // Count attempts
    int attempts = 0;
    XMLElement* scan = tr->FirstChildElement("TestRegistration");
    while (scan)
    {
        if (QString(scan->Attribute("testId")) == tid)
            attempts++;
        scan = scan->NextSiblingElement("TestRegistration");
    }

    if (attempts >= 2)
    {
        QMessageBox::warning(this, "Blocked", "Maximum 2 attempts allowed.");
        return;
    }

    if (attempts == 1)
    {
        // check first attempt's grade for F
        XMLElement* last = tr->FirstChildElement("TestRegistration");
        QString gradeFirst = "";

        while (last)
        {
            if (QString(last->Attribute("testId")) == tid)
            {
                XMLElement* gg = last->FirstChildElement("Grade");
                if (gg) gradeFirst = gg->GetText();
            }
            last = last->NextSiblingElement("TestRegistration");
        }

        if (gradeFirst != "F")
        {
            QMessageBox::information(
                this,
                "Not allowed",
                "Second attempt allowed only when first attempt is F.");
            return;
        }
    }

    // Insert new attempt
    XMLElement* newT = doc.NewElement("TestRegistration");
    newT->SetAttribute("testId", tid.toUtf8().constData());
    newT->SetAttribute("attempt", QString::number(attempts + 1).toUtf8().constData());

    XMLElement* scEl = doc.NewElement("Score");
    scEl->SetText(QString::number(g_score).toUtf8().constData());

    XMLElement* resEl = doc.NewElement("Result");
    resEl->SetText((g_grade == "F" ? "Fail" : "Pass"));

    XMLElement* grEl = doc.NewElement("Grade");
    grEl->SetText(g_grade.toUtf8().constData());

    newT->InsertEndChild(scEl);
    newT->InsertEndChild(resEl);
    newT->InsertEndChild(grEl);

    tr->InsertEndChild(newT);

    // ==========================================================
    //  AUTO-CERTIFICATE: ANY PASSING ATTEMPT RULE
    // ==========================================================
    bool allPassed = true;

    XMLElement* courseNode = adminCourses->FirstChildElement("Course");
    while (courseNode)
    {
        if (QString(courseNode->Attribute("id")) == cid)
        {
            XMLElement* tset = courseNode->FirstChildElement("Tests");
            XMLElement* t = tset->FirstChildElement("Test");

            while (t)
            {
                QString tidIter = t->Attribute("id");
                bool passFound = false;

                XMLElement* at = tr->FirstChildElement("TestRegistration");
                while (at)
                {
                    if (QString(at->Attribute("testId")) == tidIter)
                    {
                        QString g = at->FirstChildElement("Grade")->GetText();
                        if (g == "A" || g == "B" || g == "C")
                        {
                            passFound = true;
                            break;
                        }
                    }
                    at = at->NextSiblingElement("TestRegistration");
                }

                if (!passFound)
                {
                    allPassed = false;
                    break;
                }

                t = t->NextSiblingElement("Test");
            }

            break;
        }

        courseNode = courseNode->NextSiblingElement("Course");
    }

    XMLElement* cert = cr->FirstChildElement("Certificate");
    if (!cert)
    {
        cert = doc.NewElement("Certificate");
        XMLElement* sEl = doc.NewElement("Status");
        sEl->SetText("Pending");
        cert->InsertEndChild(sEl);
        cr->InsertEndChild(cert);
    }

    XMLElement* stat = cert->FirstChildElement("Status");
    if (allPassed && QString(stat->GetText()) != "Issued")
    {
        stat->SetText("Issued");

        XMLElement* idEl = cert->FirstChildElement("IssueDate");
        if (!idEl)
        {
            idEl = doc.NewElement("IssueDate");
            cert->InsertEndChild(idEl);
        }

        idEl->SetText(QDate::currentDate().toString("yyyy-MM-dd").toUtf8().constData());
    }

    doc.SaveFile((g_xmlPath + "users.xml").toUtf8().constData());

    QMessageBox::information(this, "Saved", "Test attempt saved.");
    populateDashboard(g_user);
}
