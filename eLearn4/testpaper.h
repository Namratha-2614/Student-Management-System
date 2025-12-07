#ifndef TESTPAPER_H
#define TESTPAPER_H

#include <QDialog>

namespace Ui {
class testPaper;
}

class testPaper : public QDialog
{
    Q_OBJECT

public:
    explicit testPaper(QWidget *parent = nullptr);
    ~testPaper();

private slots:
    void testSubmitBtn();

private:
    Ui::testPaper *ui;
    void loadQuestions();
    void fillUI();
    void submitTest();
};

#endif // TESTPAPER_H
