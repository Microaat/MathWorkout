#include "wgt_settings.h"
#include "ui_wgt_settings.h"

#include "settings.h"

wgtSettings::wgtSettings(Settings *s, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::wgtSettings),
    mSettings(s)
{
    Q_ASSERT(mSettings);
    ui->setupUi(this);

    on_btnApply_clicked();
}

wgtSettings::~wgtSettings(){
    delete ui;
}

void wgtSettings::on_hsldProblems_sliderMoved(int position){
    ui->spnProblems->setValue(position);
}

void wgtSettings::on_spnProblems_valueChanged(int arg1){
    ui->hsldProblems->setValue(arg1);
}

void wgtSettings::on_btnApply_clicked(){
    mSettings->setAmount(ui->spnProblems->value());

    mSettings->clearOps();
    if(ui->boxAdd->isChecked()) mSettings->setOp(Operator::Addition);
    if(ui->boxSub->isChecked()) mSettings->setOp(Operator::Subtraction);
    if(ui->boxMult->isChecked()) mSettings->setOp(Operator::Multiplication);
    if(ui->boxDiv->isChecked()) mSettings->setOp(Operator::Division);

    mSettings->setAddition({ui->spnAddMin->value(), ui->spnAddMax->value()});
    mSettings->setMultiplication({ui->spnMultMin->value(), ui->spnMultMax->value()});
    mSettings->setDivision({ui->spnDivMin->value(), ui->spnDivMax->value()});

    emit settingsChanged();
}

void wgtSettings::on_btnCancel_clicked(){

}

