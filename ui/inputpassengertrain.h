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
/**
 * @class InputCargoTrain
 * @brief This class is a QDialog Window that takes from user input about PassengerTrain which he want to change/creeate
 */
class InputPassengerTrain : public QDialog {
Q_OBJECT

public:
    /**
     * @brief Constructor
     * @param parent parent object
     * @param editedEntry Pointer to Entry in which we want to change/add PassengerTrain
     */
    explicit InputPassengerTrain(QWidget *parent = nullptr, Entry* editedEntry=nullptr);

    /**
     * @brief InputPassengerTrain deconstructor
     */
    ~InputPassengerTrain() override;
public slots:
    /**
     * @brief Slot defining what happen after clicking confirmButton
     */
    void on_confirmButton_clicked();

    /**
     * @brief Slot defining what happen after clicking cancelButton
     */
    void on_cancelButton_clicked();

private:
    /**
     *  @property ui
     *  @brief pointer to the user interface of the InputPassengerTrain class
     */
    Ui::InputPassengerTrain *ui;
    /**
     * @property entryTrain
     * @brief a pointer to new PassengerTrain
     */
    PassengerTrain *entryTrain;
    /**
     * @property entry
     * @brief a pointer to edited entry
     */
    Entry* entry;
};


#endif //UNTITLED5_INPUTPASSENGERTRAIN_H
