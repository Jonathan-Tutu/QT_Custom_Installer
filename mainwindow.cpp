#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    //Init Variable//
    seconds = 0;

    ui->setupUi(this);


    timer = new QTimer(this);
    timer->start(1000);

    connect(timer, &QTimer::timeout, this, &MainWindow::ElapsedTime);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::ElapsedTime()
{
    seconds++;
    if(seconds == 60) {
        seconds = 0;
        minutes += 1;
    }
    ui->timer->setText(QString::number(minutes).rightJustified(2, '0') + ":" + QString::number(seconds).rightJustified(2,'0'));

    MoveProgressBar();
}

void MainWindow::MoveProgressBar()
{
    ui->progressBar->setRange(0,100);
    ui->progressBar->setValue(seconds);
}

void MainWindow::LaunchInstallProcess()
{
    QProcess *process = new QProcess(this);
    process->start("C:/Test");
}
