#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDebug>
#include <QProcess>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void ElapsedTime();
    void MoveProgressBar();
    void SelectInstall();
    void LaunchInstallProcess();

    void changeWindows();

private:
    Ui::MainWindow *ui;
    QTimer *timer;

    int seconds, minutes;
    short index;
};
#endif // MAINWINDOW_H
