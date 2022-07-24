#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    //Init Variable//
    seconds = 0;
    index = 1;

    ui->setupUi(this);


    timer = new QTimer(this);

    //Connect//
    connect(timer, &QTimer::timeout, this, &MainWindow::ElapsedTime);
    connect(ui->btn_next, &QPushButton::clicked, this, &MainWindow::changeWindows);
    connect(ui->btn_next_2, &QPushButton::clicked, this, &MainWindow::changeWindows);
    connect(ui->btn_next_3, &QPushButton::clicked, this, &MainWindow::changeWindows);

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

    //MoveProgressBar();
}

void MainWindow::MoveProgressBar()
{
    ui->progressBar->setRange(0,100);
    ui->progressBar->setValue(seconds);
}

void MainWindow::LaunchInstallProcess()
{
    QProcess p;
    p.setProgram("programs/odbcconnectorHFDSQL.exe");
    p.start();
}


void MainWindow::changeWindows()
{
    ui->stackedWidget->setCurrentIndex(index);

    if(ui->stackedWidget->currentIndex() == 2)
    {
        timer->start(1000);
    }

    index++;
}

void MainWindow::SelectInstall()
{

}
