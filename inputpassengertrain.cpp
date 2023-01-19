//
// Created by creaz on 18.01.2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_InputPassengerTrain.h" resolved

#include "inputpassengertrain.h"
#include "ui_InputPassengerTrain.h"


InputPassengerTrain::InputPassengerTrain(QWidget *parent, Train* editedTrain) :
        QDialog(parent), ui(new Ui::InputPassengerTrain) {
    ui->setupUi(this);
    this->entryTrain= dynamic_cast<PassengerTrain*>(editedTrain);

    ui->nameEdit->setText(QString::fromStdString(editedTrain->getName()));
    ui->ownerEdit->setText(QString::fromStdString(editedTrain->getOwner()));
    ui->velocitySpinBox->setValue(editedTrain->getMaxVelocity());
    if(entryTrain!= nullptr){
        ui->passengerNumSpinBox->setValue(this->entryTrain->getMaxPassNumber());
        ui->travelClassesSpinBox->setValue(this->entryTrain->getNumOfTravelClasses());
    }else{
        originalTrain=new Train(*editedTrain);
    }
}

InputPassengerTrain::~InputPassengerTrain() {
    delete ui;
    delete originalTrain;
}

void InputPassengerTrain::on_confirmButton_clicked() {
    if(ui->nameEdit->toPlainText().size()>0 && ui->nameEdit->toPlainText().size()<30 && ui->ownerEdit->toPlainText().size()>0 && ui->ownerEdit->toPlainText().size()<30){
        if(entryTrain!= nullptr){
            entryTrain->setName(ui->nameEdit->toPlainText().toStdString());
            entryTrain->setOwner(ui->ownerEdit->toPlainText().toStdString());
            entryTrain->setMaxVelocity(ui->velocitySpinBox->value());
            entryTrain->setMaxPassNumber(ui->passengerNumSpinBox->value());
            entryTrain->setNumOfTravelClasses(ui->travelClassesSpinBox->value());
        }else{
            PassengerTrain *newTrain = new PassengerTrain(ui->nameEdit->toPlainText().toStdString(),ui->ownerEdit->toPlainText().toStdString(),
                                                          ui->velocitySpinBox->value(),ui->passengerNumSpinBox->value(),
                                                          ui->travelClassesSpinBox->value());
            delete originalTrain;
            originalTrain=newTrain;
        }
        this->close();
    }else{
        QMessageBox::warning(this,"Invalid data","Name and owner should not be empty or longer than 30 characters!");
    }
}

void InputPassengerTrain::on_cancelButton_clicked() {
    this->close();
}
