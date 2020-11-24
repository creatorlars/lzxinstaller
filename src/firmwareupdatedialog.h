#ifndef FIRMWAREUPDATEDIALOG_H
#define FIRMWAREUPDATEDIALOG_H

#include <QDialog>

namespace Ui {
class FirmwareUpdateDialog;
}

class FirmwareUpdateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FirmwareUpdateDialog(QWidget *parent = nullptr);
    ~FirmwareUpdateDialog();

private:
    Ui::FirmwareUpdateDialog *ui;
};

#endif // FIRMWAREUPDATEDIALOG_H
