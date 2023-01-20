#include <QApplication>
#include<QIcon>
#include "../ui/mainwindow.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QIcon icon("../icon.png"); //https://www.flaticon.com/free-icons/train Train icons created by Freepik - Flaticon

    MainWindow mainWindow;
    a.setWindowIcon(icon);
    mainWindow.show();


    return QApplication::exec();
}
