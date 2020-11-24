#include "mainwindow.h"
#include "firmwareupdatedialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow y;

    y.show();

    return a.exec();
}
