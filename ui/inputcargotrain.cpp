#include "inputcargotrain.h"
#include "ui_InputCargoTrain.h"

/**
 * This constructor checks if entry has an CargoTrain as Train* pointer
 * if yes, it assigns values to all text and spin boxes, otherwise
 * it only assigns values to Train members
 *
 * It also sets window background using changeBackground(this, ":/graphics/background.png")
 */
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

/**
 * Deconstructor deletes ui pointer
 */
InputCargoTrain::~InputCargoTrain() {
    delete ui;
}

/**
 * This slots validates if every text box and if the type of train in
 * edited entry is CargoTrain, it changes it's values, otherwise it creates
 * a new Train* pointer and initialize it as CargoTrain. Then it change
 * Entry Train pointer
 *
 * If any value is invalid it shows warning
 */

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

/**
 * This slot closes the window if user clicks cancel
 */
void InputCargoTrain::on_cancelButton_clicked() {
    this->close();
}
