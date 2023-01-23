/**
 * Graphic Attributions:
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

/**
 * @brief Main function of the program, which validates number of parameters and runs MainWindow
 * @param argc The number of command line arguments
 * @param argv The array of command line arguments
 * @return 0 on success, non-zero on failure
 */
int main(int argc, char *argv[]) {
    string filename;
    if(argc==2){
        filename=argv[1];
    }else if(argc==1){
        filename="example1.txt";
    }else{
        cout << "Invalid number of parameters!" << endl;
        return 1;
    }
    QApplication a(argc, argv);
    QResource::registerResource("../ui/resources.qrc");
    QIcon icon(":/graphics/icon.png");

    MainWindow mainWindow(nullptr, filename);
    QApplication::setWindowIcon(icon);
    mainWindow.show();


    return QApplication::exec();
}
