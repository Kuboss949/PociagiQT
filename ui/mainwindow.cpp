//
// Created by creaz on 16.01.2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_MainWindow.h"



MainWindow::MainWindow(QWidget *parent, std::string fileName) :
        QWidget(parent), ui(new Ui::MainWindow) {
    //QResource::registerResource("../ui/resources.qrc");
    database.setFile(fileName);
    ui->setupUi(this);
    currRow=-1;
    ui->dataView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window, QBrush(QPixmap(":/graphics/background.png")));
    this->setPalette(palette);
    ui->saveDataButt->setIcon(QIcon(":/graphics/save.png"));
    ui->saveDataButt->setIconSize(QSize(35, 35));
    ui->getDataButt->setIcon(QIcon(":/graphics/file.png"));
    ui->getDataButt->setIconSize(QSize(35, 35));
    ui->searchDataButt->setIcon(QIcon(":/graphics/search.png"));
    ui->searchDataButt->setIconSize(QSize(35, 35));
    ui->addEntryButt->setIcon(QIcon(":/graphics/add.png"));
    ui->addEntryButt->setIconSize(QSize(35, 35));
    ui->deleteEntryButt->setIcon(QIcon(":/graphics/delete.png"));
    ui->deleteEntryButt->setIconSize(QSize(35, 35));
    ui->infoButt->setIcon(QIcon(":/graphics/trainInfo.png"));
    ui->infoButt->setIconSize(QSize(35, 35));
}

MainWindow::~MainWindow() {
    database.clear();
    delete ui;
}

void MainWindow::on_saveDataButt_clicked() {
    database.saveRecords();
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
            item->setText(QString::fromStdString(database.getEntryAtIndex(i)[0][j]));
            ui->dataView->setItem(i,j, item);
        }
    }
}

void MainWindow::on_searchDataButt_clicked() {
    bool ok;
    QStringList items;
    items << "Date \"DD-MM-YYYY\" format" << "Date and time \"DD-MM-YYYY HH:MM\" format" << "Point of departure" << "Destination" << "Platform Number" << "Train name";
    QString searchTypeStr = QInputDialog::getItem(this, "Select type of searched value","Type:", items, 0, false, &ok);
    if(ok && !searchTypeStr.isEmpty()){
        int searchType = searchTypeStr=="Date \"DD-MM-YYYY\" format"?0:searchTypeStr=="Date and time \"DD-MM-YYYY HH:MM\" format"?1:searchTypeStr=="Point of departure"?2:
                                                                                                                                    searchTypeStr=="Destination"?3:searchTypeStr=="Platform Number"?4:5;
        QString searchValue=QInputDialog::getText(this, "Select type of searched value","Type:", QLineEdit::Normal, QString(), &ok);
        if(ok){
            for(int i=0; i<database.getDataSize(); i++){
                if(searchType==0){
                    if(database.getEntryAtIndex(i)[0][searchType].substr(0,10)!=searchValue.toStdString()){
                        ui->dataView->hideRow(i);
                    }
                }else{
                    if(database.getEntryAtIndex(i)[0][searchType]!=searchValue.toStdString()) {
                        ui->dataView->hideRow(i);
                    }
                }
            }
        }
    }
}

void MainWindow::on_deleteEntryButt_clicked() {
    if(currRow==-1){
        QMessageBox::warning(this, "Error", "Select row first!");
    }else{
        try{
            database.deleteEntry(currRow);
        }catch(out_of_range &err){
            cerr << err.what() << endl;
        }
        ui->dataView->removeRow(currRow);
    }
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
    if(j==5){
        bool ok;
        QStringList items;
        items << "Passenger" << "Cargo";
        QString item = QInputDialog::getItem(this, "Enter Train Type","Type:", items, 0, false, &ok);
        if(ok && !item.isEmpty()){
            if(item=="Passenger"){
                InputPassengerTrain *input = new InputPassengerTrain(this, database.getEntryAtIndex(i));
                input->exec();
            }else{
                InputCargoTrain *input = new InputCargoTrain(this, database.getEntryAtIndex(i));
                input->exec();
            }
            ui->dataView->item(i,j)->setText(QString::fromStdString(database.getEntryAtIndex(i)->getEntryTrain()->getName()));
        }
    }
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
            QMessageBox::warning(this, "Invalid Data", "Date have to be in DD-MM-YYYY HH:MM format!");
        }
    }else if(j==1){
        DateAndTime newDate;
        if(validateDateAndHour(ui->dataView->item(i,j)->text().toStdString(), newDate)){
            database.getEntryAtIndex(i)->setDeparture(newDate);
        }else{
            ui->dataView->item(i,j)->setText(editedData);
            QMessageBox::warning(this, "Invalid Data", "Date have to be in DD-MM-YYYY HH:MM format!");
        }
    }else if(j==2){
        string newDest = ui->dataView->item(i,j)->text().toStdString();
        if(newDest.length()>0 && newDest.length()<30){
            database.getEntryAtIndex(i)->setDestination(newDest);
        }else{
            ui->dataView->item(i,j)->setText(editedData);
            QMessageBox::warning(this, "Invalid Data", "This field can't be empty or longer than 30 characters!");
        }
    }else if(j==3){
        string newFromWhere= ui->dataView->item(i,j)->text().toStdString();
        if(newFromWhere.length()>0 && newFromWhere.length()<30){
            database.getEntryAtIndex(i)->setFromWhere(newFromWhere);
        }else{
            ui->dataView->item(i,j)->setText(editedData);
            QMessageBox::warning(this, "Invalid Data", "This field can't be empty or longer than 30 characters!");
        }
    }else if(j==4){
        string newPlatform= ui->dataView->item(i,j)->text().toStdString();
        for(auto c:newPlatform){
            if(isdigit(c)==0){
                ui->dataView->item(i,j)->setText(editedData);
                QMessageBox::warning(this, "Invalid Data", "This field needs to be number!");
                return;
            }
        }
        int newNumber=stoi(newPlatform);
        if(newNumber>0 && newNumber<21){
            database.getEntryAtIndex(i)->setPlatformNo(newNumber);
        }else{
            ui->dataView->item(i,j)->setText(editedData);
            QMessageBox::warning(this, "Invalid Data", "This field needs to be lower than 20!");
        }
    }

}

void MainWindow::on_dataView_cellPressed(int i, int j) {
    currRow=i;
}

void MainWindow::on_infoButt_clicked() {
    QString info;
    if(currRow==-1){
        QMessageBox::warning(this, "Error", "Select row first!");
    }else if(dynamic_cast<PassengerTrain*>(database.getEntryAtIndex(currRow)->getEntryTrain())!=nullptr){
        PassengerTrain *tmp=dynamic_cast<PassengerTrain*>(database.getEntryAtIndex(currRow)->getEntryTrain());
        info=QString("Type: Passenger\nName: %1\nOwner: %2\nMaximum velocity: %3 km/h\nMaximum passenger number: %4\nNumber of travel classes: %5\n").
                arg(QString::fromStdString(tmp->getName()), QString::fromStdString(tmp->getOwner())).
                arg(tmp->getMaxVelocity()).arg(tmp->getMaxPassNumber()).arg(tmp->getNumOfTravelClasses());
        for(int i=0; i<tmp->getNumOfTravelClasses(); i++){
            try {
                info.append(QString("Class %1 capacity: %2\n").arg(i + 1).arg(tmp->getNumOfPassAtClass(i)));
            } catch(out_of_range &err){
                cerr << err.what() << endl;
            }
        }
        QMessageBox::information(this, "Train info", info);
    }else if(dynamic_cast<CargoTrain*>(database.getEntryAtIndex(currRow)->getEntryTrain())!=nullptr){
        CargoTrain *tmp = dynamic_cast<CargoTrain*>(database.getEntryAtIndex(currRow)->getEntryTrain());
        info=QString("Type: Cargo\nName: %1\nOwner: %2\nMaximum velocity: %3 km/h\nCargo type: %4\nMax cargo mass: %5t\n").
                arg(QString::fromStdString(tmp->getName()), QString::fromStdString(tmp->getOwner())).arg(tmp->getMaxVelocity()).
                arg(QString::fromStdString(tmp->getCargoType())).arg(tmp->getMaxCargoMass());
        QMessageBox::information(this, "Train info", info);
    }


}
