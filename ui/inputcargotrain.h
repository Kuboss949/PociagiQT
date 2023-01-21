//
// Created by creaz on 19.01.2023.
//

#ifndef UNTITLED5_INPUTCARGOTRAIN_H
#define UNTITLED5_INPUTCARGOTRAIN_H

#include <QDialog>
#include <QMessageBox>
#include "QTChngProp.h"
#include "validation.h"
#include "Entry.h"


QT_BEGIN_NAMESPACE
namespace Ui { class InputCargoTrain; }
QT_END_NAMESPACE

class InputCargoTrain : public QDialog {
Q_OBJECT

public:
    explicit InputCargoTrain(QWidget *parent = nullptr, Entry* editedEntry= nullptr);

    ~InputCargoTrain() override;
public slots:
    void on_confirmButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::InputCargoTrain *ui;
    CargoTrain *entryTrain;
    Entry* entry;
};


#endif //UNTITLED5_INPUTCARGOTRAIN_H
