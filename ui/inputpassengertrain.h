//
// Created by creaz on 18.01.2023.
//

#ifndef UNTITLED5_INPUTPASSENGERTRAIN_H
#define UNTITLED5_INPUTPASSENGERTRAIN_H

#include <QDialog>
#include <QMessageBox>
#include "QTChngProp.h"
#include "validation.h"
#include "Entry.h"

QT_BEGIN_NAMESPACE
namespace Ui { class InputPassengerTrain; }
QT_END_NAMESPACE

class InputPassengerTrain : public QDialog {
Q_OBJECT

public:
    explicit InputPassengerTrain(QWidget *parent = nullptr, Entry* editedEntry=nullptr);

    ~InputPassengerTrain() override;
public slots:
    void on_confirmButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::InputPassengerTrain *ui;
    PassengerTrain *entryTrain;
    Entry* entry;
};


#endif //UNTITLED5_INPUTPASSENGERTRAIN_H
