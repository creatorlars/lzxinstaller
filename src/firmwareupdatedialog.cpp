#include "firmwareupdatedialog.h"
#include "ui_firmwareupdatedialog.h"

FirmwareUpdateDialog::FirmwareUpdateDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FirmwareUpdateDialog)
{
    ui->setupUi(this);
}

FirmwareUpdateDialog::~FirmwareUpdateDialog()
{
    delete ui;
}
