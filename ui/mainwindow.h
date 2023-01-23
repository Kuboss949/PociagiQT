#ifndef UNTITLED5_MAINWINDOW_H
#define UNTITLED5_MAINWINDOW_H

#include <QWidget>
#include <QMessageBox>
#include <QInputDialog>
#include <QResource>
#include <QPalette>
#include <iostream>
#include <string>
#include "Database.h"
#include "QTChngProp.h"
#include "validation.h"
#include "inputpassengertrain.h"
#include "inputcargotrain.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
/**
 * @class MainWindow
 * @brief Main window of QT application
 */
class MainWindow : public QWidget {
Q_OBJECT

public:
    /**
     * @brief constructor of MainWindow
     * @param parent patent object of window
     * @param fileName name of file for database
     */
    explicit MainWindow(QWidget *parent = nullptr, std::string fileName="example1.txt");

    /**
     * @brief MainWindow deconstructor
     */
    ~MainWindow() override;

public slots:
    /**
     * @brief slot that specifies what happen when saveDataButt is clicked
     */
    void on_saveDataButt_clicked();

    /**
     * @brief slot that specifies what happen when getDataButt is clicked
     */
    void on_getDataButt_clicked();

    /**
     * @brief slot that specifies what happen when searchDataButt is clicked
     */
    void on_searchDataButt_clicked();

    /**
     * @brief slot that specifies what happen when cancelSearchDataButt is clicked
     */
    void on_cancelSearchDataButt_clicked();

    /**
     * @brief slot that specifies what happen when deleteEntryButt is clicked
     */
    void on_deleteEntryButt_clicked();

    /**
     * @brief slot that specifies what happen when infoButt is clicked
     */
    void on_infoButt_clicked();

    /**
     * @brief slot that specifies what happen when addEntryButt is clicked
     */
    void on_addEntryButt_clicked();

    /**
     * @brief slot that specifies what happen when cell in dataView QTableWidget is double clicked
     * @param i row number
     * @param j column number
     */
    void on_dataView_cellDoubleClicked(int i, int j);
    /**
     * @brief slot that specifies what happen when cell in dataView QTableWidget is changed
     * @param i row number
     * @param j column number
     */
    void on_dataView_cellChanged(int i, int j);
    /**
     * @brief slot that specifies what happen when cell in dataView QTableWidget is pressed
     * @param i row number
     * @param j column number
     */
    void on_dataView_cellPressed(int i, int j);

private:
    /**
     *  @property ui
     *  @brief pointer to the user interface of the MainWindow class
     */
    Ui::MainWindow *ui;
    /**
     *  @property database
     *  @brief Database for MainWindow
     */
    Database database;
    /**
     *  @property editedData
     *  @brief Stores the value of last clicked cell
     */
    QString editedData;
    /**
     *  @property currRow
     *  @brief Stores the number of last clicked table row
     */
    int currRow;
    /**
     *  @property isSearched
     *  @brief Indicates if values shown in the table are result of search or not
     */
    bool isSearched;
};


#endif //UNTITLED5_MAINWINDOW_H
