#include <QFile>
#include <QProcess>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    m_binaryPath = QFileInfo(QCoreApplication::applicationFilePath()).dir().absolutePath();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_detectHardwareButton_clicked()
{
}

void MainWindow::on_deviceMenu_currentIndexChanged(const QString &arg1)
{
    if (arg1 != "")
    {
        ui->detectHardwareButton->setEnabled(true);
    }
    else
    {
        ui->detectHardwareButton->setEnabled(false);
    }
}

void MainWindow::on_actionDevice_Firmware_Update_triggered()
{
    // static FirmwareUpdateDialog d;
    // d.show();
}
