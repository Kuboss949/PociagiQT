//
// Created by creaz on 18.01.2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_InputPassengerTrain.h" resolved

#include "inputpassengertrain.h"
#include "ui_InputPassengerTrain.h"


InputPassengerTrain::InputPassengerTrain(QWidget *parent) :
        QDialog(parent), ui(new Ui::InputPassengerTrain) {
    ui->setupUi(this);
}

InputPassengerTrain::~InputPassengerTrain() {
    delete ui;
}
