#include "admindb.h"
#include "ui_admindb.h"
#include "globals.h"

#include <QBrush>
#include <QColor>
#include <QHeaderView>
#include <QTableWidgetItem>
#include <QDebug>

// Visible columns
static const int COL_NUMBER  = 0;
static const int COL_USER    = 1;
static const int COL_PWD     = 2;
static const int COL_EMAIL   = 3;
static const int COL_PHONE   = 4;
static const int COL_ADDR    = 5;
static const int COL_COURSE  = 6;
static const int COL_TEST    = 7;
static const int COL_SCORE   = 8;
static const int COL_GRADE   = 9;
static const int COL_ATTEMPT = 10;
static const int COL_EDIT    = 11;
static const int COL_DELETE  = 12;

// Hidden metadata columns (M1)
static const int H_ISHEADER   = 13; // "1" = header row, "0" = test row
static const int H_STUDENTID  = 14;
static const int H_COURSEID   = 15;
static const int H_TESTID     = 16;
static const int H_ATTEMPT_H  = 17;
static const int H_GRADE_H    = 18;

adminDb::adminDb(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminDb)
{
    ui->setupUi(this);

    // Visible + hidden columns
    ui->tableWidget->setColumnCount(19);
    // Narrow action columns
    ui->tableWidget->setColumnWidth(COL_EDIT, 65);
    ui->tableWidget->setColumnWidth(COL_DELETE, 75);

    // Adjust other important columns
    ui->tableWidget->setColumnWidth(COL_USER, 1400);
    ui->tableWidget->setColumnWidth(COL_EMAIL, 1450);
    ui->tableWidget->setColumnWidth(COL_PHONE, 1200);
    ui->tableWidget->setColumnWidth(COL_ADDR, 1450);
    ui->tableWidget->setColumnWidth(COL_COURSE, 1300);
    ui->tableWidget->setColumnWidth(COL_TEST, 1300);

    // Allow dynamic resizing
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);



    ui->tableWidget->setHorizontalHeaderLabels({
        "Number", "Username", "Password",
        "Email", "Phone", "Address",
        "Course", "Test", "Score", "Grade", "Attempt",
        "Edit", "Delete",
        // Hidden (headers put but will hide)
        "isHeader", "studentId", "courseId", "testId", "attempt_meta", "grade_meta"
    });

    // Hide metadata columns
    ui->tableWidget->setColumnHidden(H_ISHEADER, true);
    ui->tableWidget->setColumnHidden(H_STUDENTID, true);
    ui->tableWidget->setColumnHidden(H_COURSEID, true);
    ui->tableWidget->setColumnHidden(H_TESTID, true);
    ui->tableWidget->setColumnHidden(H_ATTEMPT_H, true);
    ui->tableWidget->setColumnHidden(H_GRADE_H, true);

    // ========== THEME 3 (Green) - Header + Hover ==========
    ui->tableWidget->horizontalHeader()->setStyleSheet(
        "QHeaderView::section {"
        " background-color: #2E7D32;"      /* Dark Green */
        " color: white;"
        " font-weight: bold;"
        " font-size: 14px;"
        " padding: 6px;"
        " border: 1px solid #1B5E20;"
        "}"
        "QHeaderView::section:hover {"
        " background-color: #1B5E20;"
        "}"
        );

    // Center-align header text for visible columns
    for (int i = 0; i <= COL_ATTEMPT; ++i) {
        QTableWidgetItem *h = ui->tableWidget->horizontalHeaderItem(i);
        if (h) h->setTextAlignment(Qt::AlignCenter);
    }

    // ========== TABLE FORMATTING ==========
    ui->tableWidget->setAlternatingRowColors(true);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(30);
    ui->tableWidget->verticalHeader()->setVisible(false);

    // Row highlight (matching green theme)
    // We'll set selection color via stylesheet - keep existing style additions but append safely
    ui->tableWidget->setStyleSheet(ui->tableWidget->styleSheet() +
                                   QString(
                                       "QTableWidget::item:selected {"
                                       " background-color: #A5D6A7;"      /* Light green highlight */
                                       " color: black;"
                                       "}"
                                       "QTableWidget {"
                                       " alternate-background-color: #F1F8E9;"  /* Very light green */
                                       " background-color: white;"
                                       "}"
                                       "QTableWidget::item { padding: 4px; }"
                                       ));

    // Header resizing
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    // Button style strings stored as properties for reuse
    QString editBtnStyle =
        "QPushButton {"
        " background-color: #43A047;"     /* Medium green */
        " color: white;"
        " padding: 4px 10px;"
        " border-radius: 5px;"
        " font-weight: bold;"
        "}"
        "QPushButton:hover {"
        " background-color: #2E7D32;"     /* Darker on hover */
        "}";
    QString deleteBtnStyle =
        "QPushButton {"
        " background-color: #E53935;"     /* Soft red */
        " color: white;"
        " padding: 4px 10px;"
        " border-radius: 5px;"
        " font-weight: bold;"
        "}"
        "QPushButton:hover {"
        " background-color: #B71C1C;"     /* Dark red on hover */
        "}";

    ui->tableWidget->setProperty("editBtnStyle", editBtnStyle);
    ui->tableWidget->setProperty("deleteBtnStyle", deleteBtnStyle);

    // Prevent user editing directly
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Populate table
    loadXmlAndPopulateTable();
}

adminDb::~adminDb()
{
    delete ui;
}

// Helper: returns row index for a widget placed inside the table (cell widget)
int adminDb::rowForWidget(QWidget *w) const
{
    if (!w) return -1;
    // map widget's top-left point to table viewport coordinates and get index
    QPoint globalPt = w->mapToGlobal(QPoint(1,1));
    QPoint viewPt = ui->tableWidget->viewport()->mapFromGlobal(globalPt);
    QModelIndex idx = ui->tableWidget->indexAt(viewPt);
    return idx.isValid() ? idx.row() : -1;
}

// Helper to create a styled button and attach generic clicked handlers
QPushButton* adminDb::makeButton(const QString &text, const QString &stylePropName)
{
    QPushButton *btn = new QPushButton(text);
    btn->setFixedSize(80, 28);
    QString s = ui->tableWidget->property(stylePropName.toUtf8()).toString();
    if (!s.isEmpty()) btn->setStyleSheet(s);
    return btn;
}

QString adminDb::getCourseName(XMLDocument &doc, const QString &courseId)
{
    if (courseId.isEmpty()) return QString();

    XMLElement *courses = doc.FirstChildElement("ELearningPlatform");
    if (!courses) return courseId;
    courses = courses->FirstChildElement("Courses");
    if (!courses) return courseId;

    for (XMLElement *c = courses->FirstChildElement("Course"); c; c = c->NextSiblingElement("Course"))
    {
        const char *aid = c->Attribute("id");
        if (!aid) continue;
        if (courseId == aid)
        {
            XMLElement *nameEl = c->FirstChildElement("Name");
            if (nameEl && nameEl->GetText()) return QString(nameEl->GetText());
        }
    }
    return courseId;
}

QString adminDb::getTestType(XMLDocument &doc, const QString &courseId, const QString &testId)
{
    if (courseId.isEmpty() || testId.isEmpty()) return testId;

    XMLElement *courses = doc.FirstChildElement("ELearningPlatform");
    if (!courses) return testId;
    courses = courses->FirstChildElement("Courses");
    if (!courses) return testId;

    for (XMLElement *c = courses->FirstChildElement("Course"); c; c = c->NextSiblingElement("Course"))
    {
        const char *cid = c->Attribute("id");
        if (!cid) continue;
        if (courseId == cid)
        {
            XMLElement *tests = c->FirstChildElement("Tests");
            if (!tests) break;
            for (XMLElement *t = tests->FirstChildElement("Test"); t; t = t->NextSiblingElement("Test"))
            {
                const char *tid = t->Attribute("id");
                if (!tid) continue;
                if (testId == tid)
                {
                    const char *type = t->Attribute("type");
                    if (type) return QString(type);
                }
            }
        }
    }
    return testId;
}

void adminDb::loadXmlAndPopulateTable()
{
    QString xmlFile = g_xmlPath + "users.xml";
    XMLDocument doc;

    if (doc.LoadFile(xmlFile.toUtf8().constData()) != XML_SUCCESS) {
        QMessageBox::critical(this, "XML Error", "Unable to load users.xml");
        return;
    }

    XMLElement *root = doc.FirstChildElement("ELearningPlatform");
    if (!root) {
        QMessageBox::critical(this, "XML Error", "Invalid users.xml: missing ELearningPlatform root");
        return;
    }
    XMLElement *students = root->FirstChildElement("Students");
    if (!students) {
        // no students => clear table
        ui->tableWidget->setRowCount(0);
        return;
    }

    // Clear any existing rows and delete cell widgets to avoid leaks
    ui->tableWidget->setRowCount(0);

    int row = 0;
    int displayIndex = 1;

    // iterate students
    for (XMLElement *s = students->FirstChildElement("Student"); s; s = s->NextSiblingElement("Student"))
    {
        const char* sid = s->Attribute("id");
        QString studentId = sid ? QString(sid) : "";

        // read attributes robustly
        auto textOrEmpty = [&](XMLElement *el)->QString{
            if (!el) return QString();
            const char* t = el->GetText();
            return t ? QString(t) : QString();
        };

        QString username = textOrEmpty(s->FirstChildElement("Username"));
        QString password = textOrEmpty(s->FirstChildElement("Password"));
        QString email = textOrEmpty(s->FirstChildElement("Email"));
        QString phone = textOrEmpty(s->FirstChildElement("Phone"));
        QString address = textOrEmpty(s->FirstChildElement("Address"));

        // Insert header row for student
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, COL_NUMBER, new QTableWidgetItem("#" + QString::number(displayIndex)));
        ui->tableWidget->setItem(row, COL_USER, new QTableWidgetItem(username));
        ui->tableWidget->setItem(row, COL_PWD, new QTableWidgetItem(password));
        ui->tableWidget->setItem(row, COL_EMAIL, new QTableWidgetItem(email));
        ui->tableWidget->setItem(row, COL_PHONE, new QTableWidgetItem(phone));
        ui->tableWidget->setItem(row, COL_ADDR, new QTableWidgetItem(address));

        // Hidden metadata
        ui->tableWidget->setItem(row, H_ISHEADER, new QTableWidgetItem("1"));
        ui->tableWidget->setItem(row, H_STUDENTID, new QTableWidgetItem(studentId));
        ui->tableWidget->setItem(row, H_COURSEID, new QTableWidgetItem(""));
        ui->tableWidget->setItem(row, H_TESTID, new QTableWidgetItem(""));
        ui->tableWidget->setItem(row, H_ATTEMPT_H, new QTableWidgetItem(""));
        ui->tableWidget->setItem(row, H_GRADE_H, new QTableWidgetItem(""));

        // Mark header row visually
        QBrush headerBrush(QColor(240, 240, 240));
        for (int c = 0; c <= COL_DELETE; ++c) {
            if (ui->tableWidget->item(row, c))
                ui->tableWidget->item(row, c)->setBackground(headerBrush);
        }

        // Student-level Edit button
        QPushButton *editStudentBtn = makeButton("Edit", "editBtnStyle");
        // connect generic clicked -> find row at runtime
        connect(editStudentBtn, &QPushButton::clicked, this, &adminDb::onEditButtonClicked);
        ui->tableWidget->setCellWidget(row, COL_EDIT, editStudentBtn);

        // Student-level Delete button
        QPushButton *delStudentBtn = makeButton("Delete", "deleteBtnStyle");
        connect(delStudentBtn, &QPushButton::clicked, this, &adminDb::onDeleteButtonClicked);
        ui->tableWidget->setCellWidget(row, COL_DELETE, delStudentBtn);

        ui->tableWidget->setRowHeight(row, 30);
        row++;
        displayIndex++;

        // Now add test rows for this student
        XMLElement *regCourses = s->FirstChildElement("RegisteredCourses");
        if (!regCourses) continue;

        for (XMLElement *c = regCourses->FirstChildElement("CourseRegistration"); c; c = c->NextSiblingElement("CourseRegistration"))
        {
            const char *cid = c->Attribute("courseId");
            QString courseId = cid ? QString(cid) : "";
            QString courseName = getCourseName(doc, courseId);

            XMLElement *tests = c->FirstChildElement("TestRegistrations");
            if (!tests) continue;

            for (XMLElement *t = tests->FirstChildElement("TestRegistration"); t; t = t->NextSiblingElement("TestRegistration"))
            {
                const char *tid = t->Attribute("testId");
                const char *att = t->Attribute("attempt");
                QString tid_q = tid ? QString(tid) : "";
                QString attempt = att ? QString(att) : "";

                QString score = textOrEmpty(t->FirstChildElement("Score"));
                // Grade might be missing; use Grade tag if available
                QString grade = textOrEmpty(t->FirstChildElement("Grade"));
                // Result tag might be used elsewhere, ignore for now

                QString testType = getTestType(doc, courseId, tid_q);

                ui->tableWidget->insertRow(row);

                // For test rows, leave username/password/email/phone/address blank to show they're under the header
                ui->tableWidget->setItem(row, COL_NUMBER, new QTableWidgetItem(""));
                ui->tableWidget->setItem(row, COL_USER, new QTableWidgetItem(""));
                ui->tableWidget->setItem(row, COL_PWD, new QTableWidgetItem(""));

                ui->tableWidget->setItem(row, COL_COURSE, new QTableWidgetItem(courseName + " (" + courseId + ")"));
                ui->tableWidget->setItem(row, COL_TEST, new QTableWidgetItem(testType + " (" + tid_q + ")"));
                ui->tableWidget->setItem(row, COL_SCORE, new QTableWidgetItem(score));
                ui->tableWidget->setItem(row, COL_GRADE, new QTableWidgetItem(grade));
                ui->tableWidget->setItem(row, COL_ATTEMPT, new QTableWidgetItem(attempt));

                // Hidden metadata for test row
                ui->tableWidget->setItem(row, H_ISHEADER, new QTableWidgetItem("0"));
                ui->tableWidget->setItem(row, H_STUDENTID, new QTableWidgetItem(studentId));
                ui->tableWidget->setItem(row, H_COURSEID, new QTableWidgetItem(courseId));
                ui->tableWidget->setItem(row, H_TESTID, new QTableWidgetItem(tid_q));
                ui->tableWidget->setItem(row, H_ATTEMPT_H, new QTableWidgetItem(attempt));
                ui->tableWidget->setItem(row, H_GRADE_H, new QTableWidgetItem(grade));

                // Color-code grade cell (cosmetic only)
                if (!grade.isEmpty()) {
                    QTableWidgetItem *gradeItem = ui->tableWidget->item(row, COL_GRADE);
                    if (gradeItem) {
                        QString g = grade.trimmed().toUpper();
                        if (g == "A" || g == "A+") {
                            gradeItem->setBackground(QBrush(QColor(220, 255, 220))); // light green
                        } else if (g == "B") {
                            gradeItem->setBackground(QBrush(QColor(240, 255, 220))); // pale
                        } else if (g == "C") {
                            gradeItem->setBackground(QBrush(QColor(255, 250, 220)));
                        } else if (g == "F") {
                            gradeItem->setBackground(QBrush(QColor(255, 220, 220))); // light red
                        }
                    }
                }

                // Test-level Edit button
                QPushButton *editTestBtn = makeButton("Edit", "editBtnStyle");
                connect(editTestBtn, &QPushButton::clicked, this, &adminDb::onEditButtonClicked);
                ui->tableWidget->setCellWidget(row, COL_EDIT, editTestBtn);

                // Test-level Delete button
                QPushButton *delTestBtn = makeButton("Delete", "deleteBtnStyle");
                connect(delTestBtn, &QPushButton::clicked, this, &adminDb::onDeleteButtonClicked);
                ui->tableWidget->setCellWidget(row, COL_DELETE, delTestBtn);

                ui->tableWidget->setRowHeight(row, 28);
                row++;
            }
        }
    }
}

// Generic indirection slots that find the row at click time and delegate to the appropriate function.
// This approach avoids capturing stale row indices when the table is reloaded.

void adminDb::onEditButtonClicked()
{
    QWidget *w = qobject_cast<QWidget*>(sender());
    int row = rowForWidget(w);
    if (row >= 0) {
        // Determine whether it is a student header row or test row
        QTableWidgetItem *isHdr = ui->tableWidget->item(row, H_ISHEADER);
        if (isHdr && isHdr->text() == "1") {
            onEditStudentClicked(row);
        } else {
            onEditTestClicked(row);
        }
    }
}

void adminDb::onDeleteButtonClicked()
{
    QWidget *w = qobject_cast<QWidget*>(sender());
    int row = rowForWidget(w);
    if (row >= 0) {
        QTableWidgetItem *isHdr = ui->tableWidget->item(row, H_ISHEADER);
        if (isHdr && isHdr->text() == "1") {
            onDeleteStudentClicked(row);
        } else {
            onDeleteTestClicked(row);
        }
    }
}

// ------------------ Student-level edit ------------------
void adminDb::onEditStudentClicked(int row)
{
    // read metadata
    QTableWidgetItem* idItem = ui->tableWidget->item(row, H_STUDENTID);
    if (!idItem) return;
    QString studentId = idItem->text();
    if (studentId.isEmpty()) return;

    QString oldUser = ui->tableWidget->item(row, COL_USER)->text();
    QString oldEmail = ui->tableWidget->item(row, COL_EMAIL)->text();
    QString oldPhone = ui->tableWidget->item(row, COL_PHONE)->text();
    QString oldAddress = ui->tableWidget->item(row, COL_ADDR)->text();

    bool ok1, ok2, ok3, ok4;
    QString newUser = QInputDialog::getText(this, "Edit Username",
                                            "Enter new Username:", QLineEdit::Normal,
                                            oldUser, &ok1);
    if (!ok1) return;

    QString newEmail = QInputDialog::getText(this, "Edit Email",
                                             "Enter Email:", QLineEdit::Normal,
                                             oldEmail, &ok2);
    if (!ok2) return;

    QString newPhone = QInputDialog::getText(this, "Edit Phone",
                                             "Enter Phone:", QLineEdit::Normal,
                                             oldPhone, &ok3);
    if (!ok3) return;

    QString newAddress = QInputDialog::getText(this, "Edit Address",
                                               "Enter Address:", QLineEdit::Normal,
                                               oldAddress, &ok4);
    if (!ok4) return;

    if (updateStudentInXML(studentId, newUser, newEmail, newPhone, newAddress))
    {
        loadXmlAndPopulateTable();
        QMessageBox::information(this, "Updated", "Student updated successfully.");
    }
    else
    {
        QMessageBox::warning(this, "Failed", "Could not update student in XML.");
    }
}

// ------------------ Student-level delete ------------------
void adminDb::onDeleteStudentClicked(int row)
{
    QTableWidgetItem* idItem = ui->tableWidget->item(row, H_STUDENTID);
    if (!idItem) return;
    QString studentId = idItem->text();
    if (studentId.isEmpty()) return;

    QString username = ui->tableWidget->item(row, COL_USER)->text();

    if (QMessageBox::question(this, "Confirm Delete",
                              "Delete student and all records for: " + username + "?") == QMessageBox::Yes)
    {
        if (deleteStudentFromXML(studentId))
        {
            loadXmlAndPopulateTable();
            QMessageBox::information(this, "Deleted", "Student removed.");
        }
        else
        {
            QMessageBox::warning(this, "Error", "XML delete failed.");
        }
    }
}

// ------------------ Test-level edit ------------------
void adminDb::onEditTestClicked(int row)
{
    QTableWidgetItem* sidItem = ui->tableWidget->item(row, H_STUDENTID);
    QTableWidgetItem* cidItem = ui->tableWidget->item(row, H_COURSEID);
    QTableWidgetItem* tidItem = ui->tableWidget->item(row, H_TESTID);
    QTableWidgetItem* attItem = ui->tableWidget->item(row, H_ATTEMPT_H);
    QTableWidgetItem* gradeItem = ui->tableWidget->item(row, H_GRADE_H);

    if (!sidItem || !cidItem || !tidItem || !attItem || !gradeItem) return;

    QString studentId = sidItem->text();
    QString courseId  = cidItem->text();
    QString testId    = tidItem->text();
    QString attempt   = attItem->text();
    QString grade     = gradeItem->text();

    // Find student header row (to sync username automatically)
    QString headerUser;
    int headerRow = row;
    while (headerRow >= 0)
    {
        QTableWidgetItem *isHdr = ui->tableWidget->item(headerRow, H_ISHEADER);
        if (isHdr && isHdr->text() == "1") {
            QTableWidgetItem *userItem = ui->tableWidget->item(headerRow, COL_USER);
            headerUser = userItem ? userItem->text() : QString();
            break;
        }
        headerRow--;
    }

    // Condition: attempt=2 AND grade=F → deletion offer
    if (attempt == "2" && grade.toUpper() == "F")
    {
        QMessageBox::StandardButton btn =
            QMessageBox::question(this, "Give Additional Attempt",
                                  "Give Additional Attempt?",
                                  QMessageBox::Ok | QMessageBox::Cancel);

        if (btn == QMessageBox::Ok)
        {
            // delete TestRegistration
            if (deleteTestFromXML(studentId, courseId, testId, attempt))
            {
                loadXmlAndPopulateTable();
                QMessageBox::information(this, "Updated",
                                         "Previous attempt removed. Student may register again.");
            }
            else
            {
                QMessageBox::warning(this, "Error",
                                     "Unable to remove attempt from XML.");
            }
        }

        return;  // exit always for this condition
    }

    // Otherwise normal edit of test is disabled
    QMessageBox::information(this, "Info",
                             "Editing of this test record is not permitted.");
}

// ------------------ Test-level delete ------------------
void adminDb::onDeleteTestClicked(int row)
{
    QTableWidgetItem* sidItem = ui->tableWidget->item(row, H_STUDENTID);
    QTableWidgetItem* cidItem = ui->tableWidget->item(row, H_COURSEID);
    QTableWidgetItem* tidItem = ui->tableWidget->item(row, H_TESTID);
    QTableWidgetItem* attItem = ui->tableWidget->item(row, H_ATTEMPT_H);

    if (!sidItem || !cidItem || !tidItem || !attItem) return;

    QString studentId = sidItem->text();
    QString courseId  = cidItem->text();
    QString testId    = tidItem->text();
    QString attempt   = attItem->text();

    QString testFull = ui->tableWidget->item(row, COL_TEST) ? ui->tableWidget->item(row, COL_TEST)->text() : QString();

    if (QMessageBox::question(this, "Confirm Delete",
                              "Delete test record: " + testFull + " ?") == QMessageBox::Yes)
    {
        if (deleteTestFromXML(studentId, courseId, testId, attempt))
        {
            loadXmlAndPopulateTable();
            QMessageBox::information(this, "Deleted", "Test record removed.");
        }
        else
        {
            QMessageBox::warning(this, "Error", "Failed to delete test in XML.");
        }
    }
}

// ------------------ XML operations ------------------

// Delete student (entire <Student> node)
bool adminDb::deleteStudentFromXML(const QString &studentId)
{
    QString xmlFile = g_xmlPath + "users.xml";
    XMLDocument doc;
    if (doc.LoadFile(xmlFile.toUtf8().constData()) != XML_SUCCESS) return false;

    XMLElement* root = doc.FirstChildElement("ELearningPlatform");
    if (!root) return false;

    XMLElement* students = root->FirstChildElement("Students");
    if (!students) return false;

    for (XMLElement *s = students->FirstChildElement("Student"); s; s = s->NextSiblingElement("Student"))
    {
        const char* aid = s->Attribute("id");
        if (aid && studentId == QString(aid))
        {
            students->DeleteChild(s);
            doc.SaveFile(xmlFile.toUtf8().constData());
            return true;
        }
    }
    return false;
}

// Update student details
bool adminDb::updateStudentInXML(const QString &studentId,
                                 const QString &newUsername,
                                 const QString &newEmail,
                                 const QString &newPhone,
                                 const QString &newAddress)
{
    QString xmlFile = g_xmlPath + "users.xml";
    XMLDocument doc;
    if (doc.LoadFile(xmlFile.toUtf8().constData()) != XML_SUCCESS) return false;

    XMLElement* root = doc.FirstChildElement("ELearningPlatform");
    if (!root) return false;

    XMLElement* students = root->FirstChildElement("Students");
    if (!students) return false;

    for (XMLElement *s = students->FirstChildElement("Student"); s; s = s->NextSiblingElement("Student"))
    {
        const char* aid = s->Attribute("id");
        if (aid && studentId == QString(aid))
        {
            XMLElement* uEl = s->FirstChildElement("Username");
            if (!uEl) {
                uEl = doc.NewElement("Username");
                s->InsertFirstChild(uEl);
            }
            uEl->SetText(newUsername.toUtf8().constData());

            XMLElement* eEl = s->FirstChildElement("Email");
            if (!eEl) { eEl = doc.NewElement("Email"); s->InsertAfterChild(uEl, eEl); }
            eEl->SetText(newEmail.toUtf8().constData());

            XMLElement* pEl = s->FirstChildElement("Phone");
            if (!pEl) { pEl = doc.NewElement("Phone"); s->InsertAfterChild(eEl, pEl); }
            pEl->SetText(newPhone.toUtf8().constData());

            XMLElement* aEl = s->FirstChildElement("Address");
            if (!aEl) { aEl = doc.NewElement("Address"); s->InsertAfterChild(pEl, aEl); }
            aEl->SetText(newAddress.toUtf8().constData());

            doc.SaveFile(xmlFile.toUtf8().constData());
            return true;
        }
    }
    return false;
}

// Delete test registration
bool adminDb::deleteTestFromXML(const QString &studentId, const QString &courseId,
                                const QString &testId, const QString &attempt)
{
    QString xmlFile = g_xmlPath + "users.xml";
    XMLDocument doc;
    if (doc.LoadFile(xmlFile.toUtf8().constData()) != XML_SUCCESS) return false;

    XMLElement* root = doc.FirstChildElement("ELearningPlatform");
    if (!root) return false;

    XMLElement* students = root->FirstChildElement("Students");
    if (!students) return false;

    for (XMLElement *s = students->FirstChildElement("Student"); s; s = s->NextSiblingElement("Student"))
    {
        const char* aid = s->Attribute("id");
        if (!(aid && studentId == QString(aid))) continue;

        XMLElement* regCourses = s->FirstChildElement("RegisteredCourses");
        if (!regCourses) continue;

        for (XMLElement *c = regCourses->FirstChildElement("CourseRegistration"); c; c = c->NextSiblingElement("CourseRegistration"))
        {
            const char* cid = c->Attribute("courseId");
            if (!cid) continue;
            if (courseId == QString(cid))
            {
                XMLElement* tests = c->FirstChildElement("TestRegistrations");
                if (!tests) continue;

                for (XMLElement *t = tests->FirstChildElement("TestRegistration"); t; t = t->NextSiblingElement("TestRegistration"))
                {
                    const char* tid = t->Attribute("testId");
                    const char* att = t->Attribute("attempt");
                    if (!tid) continue;
                    if (testId == QString(tid) && attempt == QString(att))
                    {
                        tests->DeleteChild(t);
                        doc.SaveFile(xmlFile.toUtf8().constData());
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

// Update test registration (attempt and username sync)
bool adminDb::updateTestInXML(const QString &studentId, const QString &courseId,
                              const QString &testId, const QString &oldAttempt,
                              const QString &newAttempt, const QString &newUsername)
{
    QString xmlFile = g_xmlPath + "users.xml";
    XMLDocument doc;
    if (doc.LoadFile(xmlFile.toUtf8().constData()) != XML_SUCCESS) return false;

    XMLElement* root = doc.FirstChildElement("ELearningPlatform");
    if (!root) return false;

    XMLElement* students = root->FirstChildElement("Students");
    if (!students) return false;

    // Find the student by id
    for (XMLElement *s = students->FirstChildElement("Student"); s; s = s->NextSiblingElement("Student"))
    {
        const char* aid = s->Attribute("id");
        if (!(aid && studentId == QString(aid))) continue;

        // Update username at student level (sync)
        XMLElement* uEl = s->FirstChildElement("Username");
        if (uEl) uEl->SetText(newUsername.toUtf8().constData());

        XMLElement* regCourses = s->FirstChildElement("RegisteredCourses");
        if (!regCourses) break;

        // Find the course
        for (XMLElement *c = regCourses->FirstChildElement("CourseRegistration"); c; c = c->NextSiblingElement("CourseRegistration"))
        {
            const char* cid = c->Attribute("courseId");
            if (!cid) continue;
            if (courseId != QString(cid))
                continue;

            XMLElement* tests = c->FirstChildElement("TestRegistrations");
            if (!tests) break;

            // Find the test registration with matching oldAttempt
            for (XMLElement *t = tests->FirstChildElement("TestRegistration"); t; t = t->NextSiblingElement("TestRegistration"))
            {
                const char* tid = t->Attribute("testId");
                const char* att = t->Attribute("attempt");
                if (!tid) continue;
                if (testId != QString(tid))
                    continue;

                if (oldAttempt != QString(att))
                    continue;

                // Only update attempt if allowed: oldAttempt == "2" and Grade == "F"
                XMLElement* gradeEl = t->FirstChildElement("Grade");
                QString grade = gradeEl && gradeEl->GetText() ? QString(gradeEl->GetText()).trimmed() : "";

                if (oldAttempt == "2" && grade.toUpper() == "F")
                {
                    t->SetAttribute("attempt", newAttempt.toUtf8().constData());
                }
                // else: do not change attempt

                doc.SaveFile(xmlFile.toUtf8().constData());
                return true;
            }
        }
    }
    return false;
}
