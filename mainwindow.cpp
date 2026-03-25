#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "wgt_problem.h"
#include "wgt_settings.h"

#include <QHBoxLayout>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setFixedSize(560, 330);

    auto *layout = new QHBoxLayout(ui->centralwidget);
    mProblem = new wgtProblem(&mSettings);
    auto *settings = new wgtSettings(&mSettings);

    layout->addWidget(mProblem);
    layout->addWidget(settings);
    //layout->addStretch();

    connect(settings, &wgtSettings::settingsChanged,
            this, &MainWindow::updateProblem);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::updateProblem(){
    mProblem->showProblem();
}



