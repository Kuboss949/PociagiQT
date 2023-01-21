//
// Created by creaz on 19.01.2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_InputCargoTrain.h" resolved

#include "inputcargotrain.h"
#include "ui_InputCargoTrain.h"


InputCargoTrain::InputCargoTrain(QWidget *parent, Entry* editedEntry) :
        QDialog(parent), ui(new Ui::InputCargoTrain) {
    ui->setupUi(this);
    changeBackground(this, ":/graphics/background.png");
    this->entry=editedEntry;
    this->entryTrain= dynamic_cast<CargoTrain*>(editedEntry->getEntryTrain());
    if(entry->getEntryTrain()!= nullptr){
    ui->nameEdit->setText(QString::fromStdString(editedEntry->getEntryTrain()->getName()));
    ui->ownerEdit->setText(QString::fromStdString(editedEntry->getEntryTrain()->getOwner()));
    ui->velocitySpinBox->setValue(editedEntry->getEntryTrain()->getMaxVelocity());
    }
    if(entryTrain!= nullptr){
        ui->cargoTypeEdit->setText(QString::fromStdString(this->entryTrain->getCargoType()));
        ui->cargoMassSpinBox->setValue(this->entryTrain->getMaxCargoMass());
    }
}

InputCargoTrain::~InputCargoTrain() {
    delete ui;
}

void InputCargoTrain::on_confirmButton_clicked() {
    if(validateString(ui->nameEdit->toPlainText()) && validateString(ui->ownerEdit->toPlainText()) && validateString(ui->cargoTypeEdit->toPlainText())){
        if(entryTrain!= nullptr){
            entryTrain->setName(ui->nameEdit->toPlainText().toStdString());
            entryTrain->setOwner(ui->ownerEdit->toPlainText().toStdString());
            entryTrain->setMaxVelocity(ui->velocitySpinBox->value());
            entryTrain->setCargoType(ui->cargoTypeEdit->toPlainText().toStdString());
            entryTrain->setMaxCargoMass(ui->cargoMassSpinBox->value());
        }else{
            Train *newTrain = new CargoTrain(ui->nameEdit->toPlainText().toStdString(),ui->ownerEdit->toPlainText().toStdString(),
                                                 ui->velocitySpinBox->value(),ui->cargoTypeEdit->toPlainText().toStdString(),
                                                 ui->cargoMassSpinBox->value());
            entry->setEntryTrain(newTrain);
        }
        this->close();
    }else{
        QMessageBox::warning(this,"Invalid data","Name, owner and cargo type should not be empty or longer than 30 characters!");
    }
}

void InputCargoTrain::on_cancelButton_clicked() {
    this->close();
}
