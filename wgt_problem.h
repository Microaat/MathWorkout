#ifndef WGT_PROBLEM_H
#define WGT_PROBLEM_H

#include <QWidget>

#include "problem.h"

namespace Ui {
class wgtProblem;
}

class Settings;

class wgtProblem : public QWidget {
    Q_OBJECT

public:
    explicit wgtProblem(Settings *s, QWidget *parent = nullptr);
    ~wgtProblem();

    void onAnswer();

public slots:
    void showProblem();

private slots:
    void on_btnRefresh_clicked();

private:
    Ui::wgtProblem *ui;
    Problem mProblem;
    Settings *mSettings;
};

#endif // WGT_PROBLEM_H
