#include "wgt_problem.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QFont>
#include <QDebug>

wgtProblem::wgtProblem(Settings *s, QWidget *parent)
    : QWidget{parent}, mSettings(s)
{
    Q_ASSERT(mSettings);

    auto alignment = Qt::AlignRight;
    auto font = QFont();
    auto width = 200;

    font.setBold(true);
    font.setPointSize(20);

    auto *layout = new QVBoxLayout(this);
    mProgress = new QLabel;
    mCheck = new QLabel;
    mQuestion = new QLabel;
    mAnswer = new QLineEdit;

    setMaximumWidth(180);
    setMinimumWidth(180);

    mQuestion->setFont(font);
    font.setBold(false);
    mAnswer->setFont(font);

    mQuestion->setAlignment(alignment);
    mAnswer->setAlignment(alignment);
    //mCheck->setAlignment(alignment);

    mQuestion->setMaximumWidth(width);
    mAnswer->setMaximumWidth(width);

    layout->addWidget(mProgress);
    layout->addWidget(mQuestion);
    layout->addWidget(mAnswer);
    layout->addWidget(mCheck);
    layout->addStretch();

    //
    connect(mAnswer, &QLineEdit::returnPressed, this, &wgtProblem::onAnswer);
    showProblem();
}

void wgtProblem::showProblem(){
    mProblem = Problem::generate(*mSettings);
    QString question = QString("%1<br><u>%2 %3</u>")
        .arg(mProblem.lhs())
        .arg(mProblem.opStr())
        .arg(mProblem.rhs());
    mQuestion->setText(question);
    mAnswer->setText("");
}

void wgtProblem::onAnswer(){
    int answer = mAnswer->text().toInt();

    if(answer == mProblem.answer()) mCheck->setText("Correct");
    else {
        mCheck->setText(
            QString("Incorrect.\nAnswer: %1")
                .arg(mProblem.toString())
        );
    }

    showProblem();
}
