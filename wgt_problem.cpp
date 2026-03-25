#include "wgt_problem.h"
#include "ui_wgt_problem.h"

#include <QValidator>
#include <limits>

wgtProblem::wgtProblem(Settings *s, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::wgtProblem),
    mSettings(s)
{
    ui->setupUi(this);
    setMaximumWidth(200);
    setMinimumWidth(200);

    ui->lblCheck->setText("");
    ui->txtAnswer->setValidator(
        new QIntValidator(
            std::numeric_limits<int16_t>::lowest(),
            std::numeric_limits<int16_t>::max(),
            this
    ));

    connect(ui->txtAnswer, &QLineEdit::returnPressed, this, &wgtProblem::onAnswer);
    showProblem();
}

wgtProblem::~wgtProblem(){
    delete ui;
}

void wgtProblem::showProblem(){
    mProblem = Problem::generate(*mSettings);
    QString question = QString("%1<br><u>%2 %3</u>")
        .arg(mProblem.lhs())
        .arg(mProblem.opStr())
        .arg(mProblem.rhs());
    ui->lblQuestion->setText(question);
    ui->txtAnswer->setText("");
}

void wgtProblem::onAnswer(){
    int answer = ui->txtAnswer->text().toInt();

    auto *check = ui->lblCheck;
    if(answer == mProblem.answer()) check->setText("<font color='green'>Correct!</font><br>");
    else check->setText(QString("<font color='#F00'>Incorrect</font><br>"));

    check->setText(check->text() + mProblem.toString());

    showProblem();
}

void wgtProblem::on_btnRefresh_clicked(){
    showProblem();
    ui->lblCheck->setText("");
    ui->txtAnswer->setFocus();
}
