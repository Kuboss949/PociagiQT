/* Graphic Attributions:
 * icon:https://www.flaticon.com/free-icons/train Train icons created by Freepik - Flaticon
 * background texture: https://www.pngwing.com/en/free-png-bzhtk
 * save icon: https://www.flaticon.com/free-icons/save Save icons created by Yogi Aprelliyanto - Flaticon
 * upload icon: https://www.flaticon.com/free-icons/upload Upload icons created by Kiranshastry - Flaticon
 * add and delete icons: https://www.flaticon.com/free-icons/add Add icons created by Ilham Fitrotul Hayat - Flaticon
 * search icon: https://www.flaticon.com/free-icons/search Search icons created by Smashicons - Flaticon
 * train info icon: https://www.flaticon.com/free-icons/info Info icons created by Freepik - Flaticon and "https://www.flaticon.com/free-icons/train Train icons created by Cursor Creative - Flaticon
 * */

#include <QApplication>
#include<QIcon>
#include<QResource>
#include "../ui/mainwindow.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QResource::registerResource("../ui/resources.qrc");
    QIcon icon(":/graphics/icon.png");

    MainWindow mainWindow;
    a.setWindowIcon(icon);
    mainWindow.show();


    return QApplication::exec();
}
