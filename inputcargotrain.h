//
// Created by creaz on 19.01.2023.
//

#ifndef UNTITLED5_INPUTCARGOTRAIN_H
#define UNTITLED5_INPUTCARGOTRAIN_H

#include <QDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class InputCargoTrain; }
QT_END_NAMESPACE

class InputCargoTrain : public QDialog {
Q_OBJECT

public:
    explicit InputCargoTrain(QWidget *parent = nullptr);

    ~InputCargoTrain() override;

private:
    Ui::InputCargoTrain *ui;
};


#endif //UNTITLED5_INPUTCARGOTRAIN_H
