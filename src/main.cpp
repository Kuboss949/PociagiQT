#include <QApplication>
#include<QIcon>
#include "../mainwindow.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QIcon icon("../icon.png");

    MainWindow mainWindow;
    a.setWindowIcon(icon);
    mainWindow.show();


    return QApplication::exec();
}
