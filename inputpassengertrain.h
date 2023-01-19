//
// Created by creaz on 18.01.2023.
//

#ifndef UNTITLED5_INPUTPASSENGERTRAIN_H
#define UNTITLED5_INPUTPASSENGERTRAIN_H

#include <QDialog>
#include "Train.h"
#include "CargoTrain.h"
#include "PassengerTrain.h"

QT_BEGIN_NAMESPACE
namespace Ui { class InputPassengerTrain; }
QT_END_NAMESPACE

class InputPassengerTrain : public QDialog {
Q_OBJECT

public:
    explicit InputPassengerTrain(QWidget *parent = nullptr, Train* entryTrain=nullptr);

    ~InputPassengerTrain() override;

private:
    Ui::InputPassengerTrain *ui;
    PassengerTrain *entryTrain;
};


#endif //UNTITLED5_INPUTPASSENGERTRAIN_H
