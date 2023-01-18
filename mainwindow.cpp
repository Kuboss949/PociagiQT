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

void MainWindow::on_modifyDataButt_clicked() {

}

void MainWindow::on_dataView_cellDoubleClicked(int i, int j) {
    tmp=ui->dataView->item(i,j)->text();
}

void MainWindow::on_dataView_cellChanged(int i, int j) {
    if(j==0){
        DateAndTime newDate;
        if(validateDateAndHour(ui->dataView->item(i,j)->text().toStdString(), newDate)){
            database.getEntryAtIndex(i)->setArrival(newDate);
        }else{
            ui->dataView->item(i,j)->setText(tmp);
        }
    }else if(j==1){
        DateAndTime newDate;
        if(validateDateAndHour(ui->dataView->item(i,j)->text().toStdString(), newDate)){
            database.getEntryAtIndex(i)->setDeparture(newDate);
        }else{
            ui->dataView->item(i,j)->setText(tmp);
        }
    }else if(j==2){
        string newDest = ui->dataView->item(i,j)->text().toStdString();
        if(newDest.length()>0 && newDest.length()<30){
            database.getEntryAtIndex(i)->setDestination(newDest);
        }else{
            ui->dataView->item(i,j)->setText(tmp);
        }
    }else if(j==3){
        string newFromWhere= ui->dataView->item(i,j)->text().toStdString();
        if(newFromWhere.length()>0 && newFromWhere.length()<30){
            database.getEntryAtIndex(i)->setFromWhere(newFromWhere);
        }else{
            ui->dataView->item(i,j)->setText(tmp);
        }
    }else if(j==4){
        string newPlatform= ui->dataView->item(i,j)->text().toStdString();
        for(auto i:newPlatform){
            if(isdigit(i)==0){
                ui->dataView->item(i,j)->setText(tmp);
                return;
            }
        }
        int newNumber=stoi(newPlatform);
        if(newNumber>0 && newNumber<21){
            database.getEntryAtIndex(i)->setPlatformNo(newNumber);
        }else{
            ui->dataView->item(i,j)->setText(tmp);
        }
    }else{

    }



}
