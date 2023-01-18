//
// Created by creaz on 18.01.2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_inputcargotrain.h" resolved

#include "inputcargotrain.h"
#include "ui_inputcargotrain.h"


inputcargotrain::inputcargotrain(QWidget *parent) :
        QDialog(parent), ui(new Ui::inputcargotrain) {
    ui->setupUi(this);
}

inputcargotrain::~inputcargotrain() {
    delete ui;
}
