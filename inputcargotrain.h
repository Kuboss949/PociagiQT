//
// Created by creaz on 18.01.2023.
//

#ifndef UNTITLED5_INPUTCARGOTRAIN_H
#define UNTITLED5_INPUTCARGOTRAIN_H

#include <QDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class inputcargotrain; }
QT_END_NAMESPACE

class inputcargotrain : public QDialog {
Q_OBJECT

public:
    explicit inputcargotrain(QWidget *parent = nullptr);

    ~inputcargotrain() override;

private:
    Ui::inputcargotrain *ui;
};


#endif //UNTITLED5_INPUTCARGOTRAIN_H
