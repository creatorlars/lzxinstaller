#include <QFile>
#include <QProcess>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->updateFirmwareButton->setEnabled(false);
    ui->detectHardwareButton->setEnabled(false);
    ui->deviceMenu->setEnabled(false);
    ui->deviceMenuLabel->setEnabled(false);

    // Connections    
	connect( &m_dfuUtilProcess, SIGNAL( readyReadStandardOutput() ), this, SLOT( dfuCommandStatus() ) );
	connect( &m_dfuUtilProcess, SIGNAL( finished( int, QProcess::ExitStatus ) ), this, SLOT( dfuCommandComplete( int ) ) );

	// Only use the included dfu-util
    
    m_binaryPath = QFileInfo(QCoreApplication::applicationFilePath()).dir().absolutePath();
	m_dfuUtilProcess.setWorkingDirectory( m_binaryPath );

	// Merge the output channels
	m_dfuUtilProcess.setProcessChannelMode( QProcess::MergedChannels );
}

MainWindow::~MainWindow()
{
    delete ui;
}


// Make sure dfu-util can be found
bool MainWindow::checkDFU( QFile *dfuUtil )
{
	if ( !dfuUtil->exists() )
	{
		// Error, dfu-util not installed locally
		QString output = tr("dfu-util cannot be found. Either build dfu-util and copy the binary to this directory or symlink it.\ne.g. ln -s /usr/bin/dfu-util %1/.").arg( m_binaryPath );

        ui->textConsole->appendPlainText(output);
		return false;
	}

	return true;
}


void MainWindow::on_detectHardwareButton_clicked()
{
     #ifdef WIN32
         QFile dfuUtil( m_binaryPath + "/" + "dfu-util.exe");
     #else
         QFile dfuUtil( m_binaryPath + "/" + "dfu-util" );
     #endif

        if(checkDFU(&dfuUtil) && m_currentFirmware!=""){

            dfuListDevices();
            ui->deviceMenu->setEnabled(true);
            ui->deviceMenuLabel->setEnabled(true);

        } else {
            ui->deviceMenu->setEnabled(false);
            ui->deviceMenuLabel->setEnabled(false);
            ui->updateFirmwareButton->setEnabled(false);
        }

}

void MainWindow::on_firmwareMenu_currentIndexChanged(const QString &arg1)
{
    m_currentFirmware = arg1;
    if(arg1!="") {
        ui->detectHardwareButton->setEnabled(true);
    } else {
        ui->detectHardwareButton->setEnabled(false);
        ui->updateFirmwareButton->setEnabled(false);
        ui->deviceMenu->setEnabled(false);
        ui->deviceMenuLabel->setEnabled(false);
    }
}

void MainWindow::on_deviceMenu_currentIndexChanged(const QString &arg1)
{

    if(arg1!="") {
        ui->updateFirmwareButton->setEnabled(true);
    } else {
        ui->updateFirmwareButton->setEnabled(false);
    }
}



void MainWindow::dfuFlashBinary()
{
// 	// Check if file exists
// 	QFile flashFile( ui->fileBrowseLineEdit->text() );
// 	if ( !flashFile.exists() )
// 	{
// 		// Error if no file selected
// 		if ( flashFile.fileName() == QString() )
// 		{
// 			QString output = tr("No file selected...");
// 			ui->dfuResultsTextEdit->append( output );
// 		}
// 		// Error if it doesn't exist
// 		else
// 		{
// 			QString output = tr("'%1' does not exist...").arg( flashFile.fileName() );
// 			ui->dfuResultsTextEdit->append( output );
// 		}

// 		return;
// 	}

// #ifdef WIN32
//     QFile dfuUtil( binaryPath + "/" + "dfu-util.exe");
// #else
//     QFile dfuUtil( binaryPath + "/" + "dfu-util" );
// #endif

// 	// Only run dfu-util if it exists
// 	if ( !checkDFU( &dfuUtil ) )
// 	{
// 		return;
// 	}

// 	// Run dfu-util command
// 	QString dfuCmd = QString("%1 -D %2").arg( dfuUtil.fileName(), flashFile.fileName() );
// 	dfuUtilProcess.start( dfuCmd );

// 	// Disable the flash button while command is running
// 	ui->flashButton->setDisabled( true );
// 	ui->listDevicesButton->setDisabled( true );
}

void MainWindow::dfuListDevices()
{
 #ifdef WIN32
    QFile dfuUtil( m_binaryPath + "/" + "dfu-util.exe");
 #else
    QFile dfuUtil( m_binaryPath + "/" + "dfu-util" );
 #endif

    // Only run dfu-util if it exists
    if ( !checkDFU( &dfuUtil ) )
    {
        return;
    }

    // Run dfu-util command
    QString dfuCmd = QString("%1 -l").arg( dfuUtil.fileName() );
    m_dfuUtilProcess.start( dfuCmd );

    // Disable the flash button while command is running
    //ui->updateFirmwareButton->setDisabled( true );
    //ui->detectHardwareButton->setDisabled( true );
}

void MainWindow::dfuCommandStatus()
{
    // Append text to the viewer
    ui->textConsole->appendPlainText( m_dfuUtilProcess.readAllStandardOutput() );

    // Scroll to bottom
    ui->textConsole->verticalScrollBar()->setValue( ui->textConsole->verticalScrollBar()->maximum() );
}

void MainWindow::dfuCommandComplete( int exitCode )
{
    //ui->updateFirmwareButton->setDisabled( false );
    //ui->detectHardwareButton->setDisabled( false );
     // Append return code
     QString output = tr("Return Code: %1").arg( exitCode );
     ui->textConsole->appendPlainText( output );
}
