//
// Created by creaz on 16.01.2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_MainWindow.h"



MainWindow::MainWindow(QWidget *parent, std::string fileName) :
        QWidget(parent), ui(new Ui::MainWindow) {
    database.setFile(fileName);
    ui->setupUi(this);
    currRow=-1;
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_saveDataButt_clicked() {
    //ui->dataView->addItem("Hello");
}

void MainWindow::on_getDataButt_clicked() {
    const QSignalBlocker block(ui->dataView);
    string tmp;
    database.clear();
    database.loadRecords();

    ui->dataView->clearContents();
    ui->dataView->setRowCount(0);

    QTableWidgetItem *item;
    ui->dataView->setRowCount(database.getDataSize());
    for(int i=0; i<database.getDataSize(); i++){
        for(int j=0; j<ui->dataView->columnCount(); j++){
            item = new QTableWidgetItem;
            item->setText(QString::fromStdString(database.getStringAtIndex(i, j)));
            ui->dataView->setItem(i,j, item);
        }
    }
}

void MainWindow::on_searchDataButt_clicked() {
}

void MainWindow::on_deleteEntryButt_clicked() {

}

void MainWindow::on_addEntryButt_clicked() {
    const QSignalBlocker block(ui->dataView);
    ui->dataView->insertRow( ui->dataView->rowCount() );
    QTableWidgetItem *item;
    for(int j=0; j<ui->dataView->columnCount(); j++){
        item = new QTableWidgetItem;
        item->setText(QString::fromStdString("N/A"));
        ui->dataView->setItem(ui->dataView->rowCount()-1,j, item);
    }
}

void MainWindow::on_dataView_cellDoubleClicked(int i, int j) {
    editedData=ui->dataView->item(i,j)->text();
}

void MainWindow::on_dataView_cellChanged(int i, int j) {
    if(i>=database.getDataSize()){
        database.createEntry();
    }
    if(j==0){
        DateAndTime newDate;
        if(validateDateAndHour(ui->dataView->item(i,j)->text().toStdString(), newDate)){
            database.getEntryAtIndex(i)->setArrival(newDate);
        }else{
            ui->dataView->item(i,j)->setText(editedData);
            QMessageBox::information(this, "Invalid Data", "Date have to be in DD-MM-YYYY HH:MM format!");
        }
    }else if(j==1){
        DateAndTime newDate;
        if(validateDateAndHour(ui->dataView->item(i,j)->text().toStdString(), newDate)){
            database.getEntryAtIndex(i)->setDeparture(newDate);
        }else{
            ui->dataView->item(i,j)->setText(editedData);
            QMessageBox::information(this, "Invalid Data", "Date have to be in DD-MM-YYYY HH:MM format!");
        }
    }else if(j==2){
        string newDest = ui->dataView->item(i,j)->text().toStdString();
        if(newDest.length()>0 && newDest.length()<30){
            database.getEntryAtIndex(i)->setDestination(newDest);
        }else{
            ui->dataView->item(i,j)->setText(editedData);
            QMessageBox::information(this, "Invalid Data", "This field can't be empty or longer than 30 characters!");
        }
    }else if(j==3){
        string newFromWhere= ui->dataView->item(i,j)->text().toStdString();
        if(newFromWhere.length()>0 && newFromWhere.length()<30){
            database.getEntryAtIndex(i)->setFromWhere(newFromWhere);
        }else{
            ui->dataView->item(i,j)->setText(editedData);
            QMessageBox::information(this, "Invalid Data", "This field can't be empty or longer than 30 characters!");
        }
    }else if(j==4){
        string newPlatform= ui->dataView->item(i,j)->text().toStdString();
        for(auto i:newPlatform){
            if(isdigit(i)==0){
                ui->dataView->item(i,j)->setText(editedData);
                QMessageBox::information(this, "Invalid Data", "This field needs to be number!");
                return;
            }
        }
        int newNumber=stoi(newPlatform);
        if(newNumber>0 && newNumber<21){
            database.getEntryAtIndex(i)->setPlatformNo(newNumber);
        }else{
            ui->dataView->item(i,j)->setText(editedData);
            QMessageBox::information(this, "Invalid Data", "This field needs to be lower than 20!");
        }
    }else{
        bool ok;
        QStringList items;
        items << "Passenger" << "Cargo";
        QString item = QInputDialog::getItem(this, "Enter Train Type","Type:", items, 0, false, &ok);
        if(ok && !item.isEmpty()){
            if(item=="Passenger"){
                InputPassengerTrain input(this, database.getEntryAtIndex(i)->getEntryTrain());
            }
        }
    }



}

void MainWindow::on_dataView_cellClicked(int i, int j) {
currRow=i;
}

void MainWindow::on_infoButt_clicked() {
    QString info;
    if(dynamic_cast<PassengerTrain*>(database.getEntryAtIndex(currRow)->getEntryTrain())!=nullptr){
        PassengerTrain *tmp=dynamic_cast<PassengerTrain*>(database.getEntryAtIndex(currRow)->getEntryTrain());
        info=QString("Type: Passenger\nName: %1\nOwner: %2\nMaximum velocity: %3 km/h\nMaximum passenger number: %4\nNumber of travel classes: %5\n").
                arg(QString::fromStdString(tmp->getName()), QString::fromStdString(tmp->getOwner())).
                arg(tmp->getMaxVelocity()).arg(tmp->getNumOfTravelClasses()).arg(tmp->getMaxPassNumber());
        for(int i=0; i<tmp->getNumOfTravelClasses(); i++){

            info.append(QString("Class %1 capacity: %2").arg(i+1).arg(tmp->getNumOfPassAtClass(i)));
        }

    }



    QMessageBox::information(this, "Train info", info);
}
