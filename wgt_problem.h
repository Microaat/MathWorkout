#ifndef WGT_PROBLEM_H
#define WGT_PROBLEM_H

#include <QWidget>

#include "problem.h"

class QLabel;
class QLineEdit;
class Settings;

class wgtProblem : public QWidget {
    Q_OBJECT

QLabel *mProgress;
QLabel *mCheck;
QLabel *mQuestion;
QLineEdit *mAnswer;

Settings *mSettings;
Problem mProblem;

public:
    explicit wgtProblem(Settings *s, QWidget *parent = nullptr);

    void showProblem();
    void onAnswer();

signals:

};

#endif // WGT_PROBLEM_H
