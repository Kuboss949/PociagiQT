//
// Created by creaz on 18.01.2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_InputPassengerTrain.h" resolved

#include "inputpassengertrain.h"
#include "ui_InputPassengerTrain.h"


InputPassengerTrain::InputPassengerTrain(QWidget *parent, Entry* editedEntry) :
        QDialog(parent), ui(new Ui::InputPassengerTrain) {

    ui->setupUi(this);
    changeBackground(this, ":/graphics/background.png");
    this->entry=editedEntry;
    this->entryTrain= dynamic_cast<PassengerTrain*>(editedEntry->getEntryTrain());
    if(entry->getEntryTrain()!= nullptr){
    ui->nameEdit->setText(QString::fromStdString(editedEntry->getEntryTrain()->getName()));
    ui->ownerEdit->setText(QString::fromStdString(editedEntry->getEntryTrain()->getOwner()));
    ui->velocitySpinBox->setValue(editedEntry->getEntryTrain()->getMaxVelocity());
    }
    if(entryTrain!= nullptr){
        ui->passengerNumSpinBox->setValue(this->entryTrain->getMaxPassNumber());
        ui->travelClassesSpinBox->setValue(this->entryTrain->getNumOfTravelClasses());
    }
}

InputPassengerTrain::~InputPassengerTrain() {
    delete ui;
}

void InputPassengerTrain::on_confirmButton_clicked() {
    if(validateString(ui->nameEdit->toPlainText()) && validateString(ui->ownerEdit->toPlainText())){
        if(entryTrain!= nullptr){
            entryTrain->setName(ui->nameEdit->toPlainText().toStdString());
            entryTrain->setOwner(ui->ownerEdit->toPlainText().toStdString());
            entryTrain->setMaxVelocity(ui->velocitySpinBox->value());
            entryTrain->setMaxPassNumber(ui->passengerNumSpinBox->value());
            entryTrain->setNumOfTravelClasses(ui->travelClassesSpinBox->value());
        }else{
            Train *newTrain = new PassengerTrain(ui->nameEdit->toPlainText().toStdString(),ui->ownerEdit->toPlainText().toStdString(),
                                                          ui->velocitySpinBox->value(),ui->passengerNumSpinBox->value(),
                                                          ui->travelClassesSpinBox->value());
            entry->setEntryTrain(newTrain);
        }
        this->close();
    }else{
        QMessageBox::warning(this,"Invalid data","Name and owner should not be empty or longer than 30 characters!");
    }
}

void InputPassengerTrain::on_cancelButton_clicked() {
    this->close();
}
