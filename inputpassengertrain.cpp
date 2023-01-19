//
// Created by creaz on 18.01.2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_InputPassengerTrain.h" resolved

#include "inputpassengertrain.h"
#include "ui_InputPassengerTrain.h"


InputPassengerTrain::InputPassengerTrain(QWidget *parent, Train* entryTrain) :
        QDialog(parent), ui(new Ui::InputPassengerTrain) {
    ui->setupUi(this);
    this->entryTrain= dynamic_cast<PassengerTrain*>(entryTrain);
    ui->nameEdit->setText(QString::fromStdString(this->entryTrain->getName()));
    ui->ownerEdit->setText(QString::fromStdString(this->entryTrain->getOwner()));
    ui->velocitySpinBox->setValue(this->entryTrain->getMaxVelocity());
    ui->passengerNumSpinBox->setValue(this->entryTrain->getMaxPassNumber());
    ui->travelClassesSpinBox->setValue(this->entryTrain->getNumOfTravelClasses());
}

InputPassengerTrain::~InputPassengerTrain() {
    delete ui;
}
