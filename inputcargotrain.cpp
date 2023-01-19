//
// Created by creaz on 19.01.2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_InputCargoTrain.h" resolved

#include "inputcargotrain.h"
#include "ui_InputCargoTrain.h"


InputCargoTrain::InputCargoTrain(QWidget *parent) :
        QDialog(parent), ui(new Ui::InputCargoTrain) {
    ui->setupUi(this);
}

InputCargoTrain::~InputCargoTrain() {
    delete ui;
}
