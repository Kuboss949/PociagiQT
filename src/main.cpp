#include <QApplication>
#include <QPushButton>
#include "../mainwindow.h"
#include "Train.h"
#include "CargoTrain.h"
#include "Entry.h"
#include "Database.h"
#include "DateAndTime.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();


    return QApplication::exec();

    /*Database d1("example1.txt");

    Train* t1=new CargoTrain("JASKDSA", "PKP", 88.8, "coal", 153);
    Train* t2=new CargoTrain("AMSAA3242", "PKP", 88.8, "coal", 153);
    Train* t3=new PassengerTrain("KASMAW312", "PKP", 88.8, 150, 2);
    DateAndTime da1(7,4,2001,13,42);
    DateAndTime d2(3,4,2001,12,23);
    DateAndTime da3(8,12,2011,13,42);
    DateAndTime d4(8,12,2011,12,23);
    Entry e1(da1, d2, "Krakow1", "Gdansk", 5, t1);
    Entry e2(da1, d2, "Krakow2", "Gdansk", 5, t2);
    Entry e3(da1, d2, "Krakow3", "Gdansk", 5, t3);
    Entry e4(da1, d2, "Krakow4", "Gdansk", 5, t1);
    Entry e5(da3, d4, "Lgota5", "Habibi", 5, t2);


    d1.createEntry();
    d1.createEntry();
    d1.createEntry();
    //d1.loadRecords();

    d1.printRecords();

    d1.saveRecords();*/

    //


    return 0;
}
