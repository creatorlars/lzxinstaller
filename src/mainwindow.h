#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "firmwareupdatedialog.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_detectHardwareButton_clicked();

    void on_deviceMenu_currentIndexChanged(const QString &arg1);

    void on_actionDevice_Firmware_Update_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
