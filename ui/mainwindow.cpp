//
// Created by creaz on 16.01.2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_MainWindow.h"


/**
 * This constructor sets: filename for database, default values for currRow and isSearched, window background and button icons and its sizes
 */
MainWindow::MainWindow(QWidget *parent, std::string fileName) :
        QWidget(parent), ui(new Ui::MainWindow) {
    database.setFile(fileName);
    ui->setupUi(this);
    currRow = -1;
    ui->dataView->setFocusPolicy(Qt::NoFocus);
    ui->dataView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    changeBackground(this, ":/graphics/background.png");
    ui->saveDataButt->setIcon(QIcon(":/graphics/save.png"));
    ui->saveDataButt->setIconSize(QSize(35, 35));
    ui->getDataButt->setIcon(QIcon(":/graphics/file.png"));
    ui->getDataButt->setIconSize(QSize(35, 35));
    ui->searchDataButt->setIcon(QIcon(":/graphics/search.png"));
    ui->searchDataButt->setIconSize(QSize(35, 35));
    ui->cancelSearchDataButt->setIcon(QIcon(":/graphics/cancelSearch.png"));
    ui->cancelSearchDataButt->setIconSize(QSize(35, 35));
    ui->addEntryButt->setIcon(QIcon(":/graphics/add.png"));
    ui->addEntryButt->setIconSize(QSize(35, 35));
    ui->deleteEntryButt->setIcon(QIcon(":/graphics/delete.png"));
    ui->deleteEntryButt->setIconSize(QSize(35, 35));
    ui->infoButt->setIcon(QIcon(":/graphics/trainInfo.png"));
    ui->infoButt->setIconSize(QSize(35, 35));
}

/**
 * MainWindow deconstructor deletes ui and clear database
 */
MainWindow::~MainWindow() {
    database.clear();
    delete ui;
}

/**
 * This slot saves records from database into a file
 */
void MainWindow::on_saveDataButt_clicked() {
    database.saveRecords();
}

/**
 * This slot clears database, then load records, validate if this acction is successfull.
 * Then it clears dataView table, and writes Entries to table
 */
void MainWindow::on_getDataButt_clicked() {
    const QSignalBlocker block(ui->dataView);
    string tmp;
    database.clear();
    if (!database.loadRecords()) {
        QMessageBox::warning(this, "Error", QString("Can't open file!"));
    }

    ui->dataView->clearContents();
    ui->dataView->setRowCount(0);

    QTableWidgetItem *item;
    ui->dataView->setRowCount(database.getDataSize());
    for (int i = 0; i < database.getDataSize(); i++) {
        for (int j = 0; j < ui->dataView->columnCount(); j++) {
            item = new QTableWidgetItem;
            item->setText(QString::fromStdString(database.getStringAtIndex(i, j)));
            ui->dataView->setItem(i, j, item);
        }
    }
}


/**
 * This slot asks user for provide searched column, then asks the user for criteria and if it's doesn't meet, the program hides row.
 * It uses getStringAtIndex(int i, string str) method to access string representation of searched value
 */
void MainWindow::on_searchDataButt_clicked() {
    bool ok, isShorten = false;
    QStringList items;
    items << "Arrival Date \"DD-MM-YYYY\" format" << "Arrival Date and time \"DD-MM-YYYY HH:MM\" format"
          << "Departure Date \"DD-MM-YYYY\" format" << "Departure Date and time \"DD-MM-YYYY HH:MM\" format"
          << "Point of departure" << "Destination" << "Platform Number" << "Train name";
    QString searchTypeStr = QInputDialog::getItem(this, "Select type of searched value", "Type:", items, 0, false, &ok);
    if (ok && !searchTypeStr.isEmpty()) {
        if (searchTypeStr.contains("\"DD-MM-YYYY\""))
            isShorten = true;
        if (searchTypeStr.contains("Arrival")) {
            searchTypeStr = "Arrival";
        } else if (searchTypeStr.contains("Departure")) {
            searchTypeStr = "Departure";
        }
        QString searchValue = QInputDialog::getText(this, "Select type of searched value", "Type:", QLineEdit::Normal,
                                                    QString(), &ok);
        if (ok) {
            for (int i = 0; i < database.getDataSize(); i++) {
                if (isShorten) {
                    try {
                        if (database.getStringAtIndex(i, searchTypeStr.toStdString()).substr(0, 10) !=
                            searchValue.toStdString()) {
                            ui->dataView->hideRow(i);
                        }
                    } catch (WrongIndex &err) {
                        cerr << err.what() << endl;
                    } catch (invalid_argument &err) {
                        cerr << err.what() << endl;
                    }
                } else {
                    try {
                        if (database.getStringAtIndex(i, searchTypeStr.toStdString()) != searchValue.toStdString()) {
                            ui->dataView->hideRow(i);
                        }
                    } catch (WrongIndex &err) {
                        cerr << err.what() << endl;
                    } catch (invalid_argument &err) {
                        cerr << err.what() << endl;
                    }
                }
            }
        }
    }
}

/**
 * This slot deletes row, if currRow is -1 then it shows warning
 * If it isn't - function tries to delete entry at currRow position
 *
 * After all operations, it assigns -1 value to currRow
 */
void MainWindow::on_deleteEntryButt_clicked() {
    if (currRow == -1) {
        QMessageBox::warning(this, "Error", "Select row first!");
    } else {
        try {
            database.deleteEntry(currRow);
        } catch (WrongIndex &err) {
            cerr << err.what() << endl;
        }
        ui->dataView->removeRow(currRow);
        currRow = -1;
    }
}

/**
 * This slot adds entry to database, then row to table and sets row values to "N/A"
 */
void MainWindow::on_addEntryButt_clicked() {
    const QSignalBlocker block(ui->dataView);
    ui->dataView->insertRow(ui->dataView->rowCount());
    QTableWidgetItem *item;
    database.createEntry();
    for (int j = 0; j < ui->dataView->columnCount(); j++) {
        item = new QTableWidgetItem;
        item->setText(QString::fromStdString("N/A"));
        ui->dataView->setItem(ui->dataView->rowCount() - 1, j, item);
    }
}

/**
 * This slot specifies what happen when cell is double clicked
 * For all columns it assigns cell text to editedData member
 * For 5th column it runs an algorithm, that is used to change Train value of the given entry
 */
void MainWindow::on_dataView_cellDoubleClicked(int i, int j) {
    editedData = ui->dataView->item(i, j)->text();
    if (j == 5) {
        bool ok;
        QStringList items;
        items << "Passenger" << "Cargo";
        QString item = QInputDialog::getItem(this, "Enter Train Type", "Type:", items, 0, false, &ok);
        if (ok && !item.isEmpty()) {
            if (item == "Passenger") {
                auto *input = new InputPassengerTrain(this, database.getEntryAtIndex(i));
                input->exec();
            } else {
                auto *input = new InputCargoTrain(this, database.getEntryAtIndex(i));
                input->exec();
            }
            ui->dataView->blockSignals(true);
            ui->dataView->item(i, j)->setText(
                    QString::fromStdString(database.getEntryAtIndex(i)->getEntryTrain()->getName()));
            ui->dataView->blockSignals(false);
        }
    }
}

/**
 * This slot validates data if the cell from rows 0-4 are changed
 * It also validates the value and if it's not valid, it sets old value to changed cell
 * Otherwise, it changes specified Entry value
 */
void MainWindow::on_dataView_cellChanged(int i, int j) {
    if (j == 0) {
        DateAndTime newDate;
        if (validateDateAndHour(ui->dataView->item(i, j)->text().toStdString(), newDate)) {
            database.getEntryAtIndex(i)->setArrival(newDate);
        } else {
            ui->dataView->blockSignals(true);
            ui->dataView->item(i, j)->setText(editedData);
            QMessageBox::warning(this, "Invalid Data", "Date have to be in DD-MM-YYYY HH:MM format!");
            ui->dataView->blockSignals(false);
        }
    } else if (j == 1) {
        DateAndTime newDate;
        if (validateDateAndHour(ui->dataView->item(i, j)->text().toStdString(), newDate)) {
            database.getEntryAtIndex(i)->setDeparture(newDate);
        } else {
            ui->dataView->blockSignals(true);
            ui->dataView->item(i, j)->setText(editedData);
            QMessageBox::warning(this, "Invalid Data", "Date have to be in DD-MM-YYYY HH:MM format!");
            ui->dataView->blockSignals(false);
        }
    } else if (j == 2) {
        string newDest = ui->dataView->item(i, j)->text().toStdString();
        if (validateString(newDest)) {
            database.getEntryAtIndex(i)->setDestination(newDest);
        } else {
            ui->dataView->item(i, j)->setText(editedData);
            QMessageBox::warning(this, "Invalid Data",
                                 QString("This field can't be empty or longer than %1 characters!").arg(STR_LIMIT));
        }
    } else if (j == 3) {
        string newFromWhere = ui->dataView->item(i, j)->text().toStdString();
        if (validateString(newFromWhere)) {
            database.getEntryAtIndex(i)->setFromWhere(newFromWhere);
        } else {
            ui->dataView->item(i, j)->setText(editedData);
            QMessageBox::warning(this, "Invalid Data",
                                 QString("This field can't be empty or longer than %1 characters!").arg(STR_LIMIT));
        }
    } else if (j == 4) {

        string newPlatform = ui->dataView->item(i, j)->text().toStdString();
        if (newPlatform == "") {
            ui->dataView->blockSignals(true);
            ui->dataView->item(i, j)->setText(editedData);
            QMessageBox::warning(this, "Invalid Data", "This field needs to be number!");
            ui->dataView->blockSignals(false);
            return;
        }
        for (auto c: newPlatform) {
            if (isdigit(c) == 0) {
                ui->dataView->blockSignals(true);
                ui->dataView->item(i, j)->setText(editedData);
                QMessageBox::warning(this, "Invalid Data", "This field needs to be number!");
                ui->dataView->blockSignals(false);
                return;
            }
        }
        int newNumber = stoi(newPlatform);
        if (newNumber > 0 && newNumber < 21) {
            database.getEntryAtIndex(i)->setPlatformNo(newNumber);
        } else {
            ui->dataView->blockSignals(true);
            ui->dataView->item(i, j)->setText(editedData);
            QMessageBox::warning(this, "Invalid Data", "This field needs to be lower than 20!");
            ui->dataView->blockSignals(false);
        }
    } else {
        ui->dataView->blockSignals(true);
        ui->dataView->item(i, j)->setText(editedData);
        QMessageBox::warning(this, "Train edit", "To edit train you have to do it by double clicking train name cell!");
        ui->dataView->blockSignals(false);
    }

}

/**
 * This slot sets currRow to number of cell which was last time pressed
 */
void MainWindow::on_dataView_cellPressed(int i, int j) {
    currRow = i;
}

/**
 * This slot displays info about train from last clicked row
 */
void MainWindow::on_infoButt_clicked() {
    QString info;
    if (currRow == -1) {
        QMessageBox::warning(this, "Error", "Select row first!");
    } else if (dynamic_cast<PassengerTrain *>(database.getEntryAtIndex(currRow)->getEntryTrain()) != nullptr) {
        auto *tmp = dynamic_cast<PassengerTrain *>(database.getEntryAtIndex(currRow)->getEntryTrain());
        info = QString(
                "Type: Passenger\nName: %1\nOwner: %2\nMaximum velocity: %3 km/h\nMaximum passenger number: %4\nNumber of travel classes: %5\n").
                arg(QString::fromStdString(tmp->getName()), QString::fromStdString(tmp->getOwner())).
                arg(tmp->getMaxVelocity()).arg(tmp->getMaxPassNumber()).arg(tmp->getNumOfTravelClasses());
        for (int i = 0; i < tmp->getNumOfTravelClasses(); i++) {
            try {
                info.append(QString("Class %1 capacity: %2\n").arg(i + 1).arg(tmp->getNumOfPassAtClass(i)));
            } catch (WrongIndex &err) {
                cerr << err.what() << endl;
            }
        }
        QMessageBox::information(this, "Train info", info);
    } else if (dynamic_cast<CargoTrain *>(database.getEntryAtIndex(currRow)->getEntryTrain()) != nullptr) {
        auto *tmp = dynamic_cast<CargoTrain *>(database.getEntryAtIndex(currRow)->getEntryTrain());
        info = QString(
                "Type: Cargo\nName: %1\nOwner: %2\nMaximum velocity: %3 km/h\nCargo type: %4\nMax cargo mass: %5t\n").
                arg(QString::fromStdString(tmp->getName()), QString::fromStdString(tmp->getOwner())).arg(
                tmp->getMaxVelocity()).
                arg(QString::fromStdString(tmp->getCargoType())).arg(tmp->getMaxCargoMass());
        QMessageBox::information(this, "Train info", info);
    }


}

/**
 * This slot shows all Entries in the table reseting search
 */
void MainWindow::on_cancelSearchDataButt_clicked() {
    for (int i = 0; i < ui->dataView->rowCount(); i++) {
        ui->dataView->showRow(i);
    }
}
