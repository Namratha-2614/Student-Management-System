#ifndef ADMINDB_H
#define ADMINDB_H

#include <QDialog>
#include <QTableWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QLineEdit>
#include <QInputDialog>
#include "tinyxml2.h"

using namespace tinyxml2;

namespace Ui {
class adminDb;
}

class adminDb : public QDialog
{
    Q_OBJECT

public:
    explicit adminDb(QWidget *parent = nullptr);
    ~adminDb();

private slots:
    void onEditStudentClicked(int row);
    void onDeleteStudentClicked(int row);

    void onEditTestClicked(int row);
    void onDeleteTestClicked(int row);

    // helper slot used by buttons (determines row at click time)
    void onEditButtonClicked();
    void onDeleteButtonClicked();

private:
    Ui::adminDb *ui;

    void loadXmlAndPopulateTable();

    QString getCourseName(XMLDocument &doc, const QString &courseId);
    QString getTestType(XMLDocument &doc, const QString &courseId, const QString &testId);

    // student-level
    bool deleteStudentFromXML(const QString &studentId);
    bool updateStudentInXML(const QString &studentId,
                            const QString &newUsername,
                            const QString &newEmail,
                            const QString &newPhone,
                            const QString &newAddress);

    // test-level
    bool deleteTestFromXML(const QString &studentId, const QString &courseId,
                           const QString &testId, const QString &attempt);
    bool updateTestInXML(const QString &studentId, const QString &courseId,
                         const QString &testId, const QString &oldAttempt,
                         const QString &newAttempt, const QString &newUsername);

    // Utility helpers
    int rowForWidget(QWidget *w) const;
    QPushButton* makeButton(const QString &text, const QString &stylePropName);
};

#endif // ADMINDB_H
