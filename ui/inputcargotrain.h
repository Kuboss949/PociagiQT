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

/**
 * @class InputCargoTrain
 * @brief This class is a QDialog Window that takes from user input about CargoTrain which he want to change/creeate
 */
class InputCargoTrain : public QDialog {
Q_OBJECT

public:
    /**
     * @brief Constructor
     * @param parent parent object
     * @param editedEntry Pointer to Entry in which we want to change/add CargoTrain
     */
    explicit InputCargoTrain(QWidget *parent = nullptr, Entry* editedEntry= nullptr);
    /**
     * @brief InputCargoTrain deconstructor
     */
    ~InputCargoTrain() override;
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
     *  @brief pointer to the user interface of the InputCargoTrain class
     */
    Ui::InputCargoTrain *ui;
    /**
     * @property entryTrain
     * @brief a pointer to new CargoTrain
     */
    CargoTrain *entryTrain;
    /**
     * @property entry
     * @brief a pointer to edited entry
     */
    Entry* entry;
};


#endif //UNTITLED5_INPUTCARGOTRAIN_H
