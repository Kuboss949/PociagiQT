//
// Created by creaz on 16.01.2023.
//

#ifndef UNTITLED5_MAINWINDOW_H
#define UNTITLED5_MAINWINDOW_H

#include <QWidget>
#include <QMessageBox>
#include <QInputDialog>
#include <iostream>
#include "Database.h"
#include "validation.h"
#include "inputpassengertrain.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr, std::string fileName="example1.txt");

    ~MainWindow() override;

public slots:
    void on_saveDataButt_clicked();
    void on_getDataButt_clicked();
    void on_searchDataButt_clicked();
    void on_deleteEntryButt_clicked();
    void on_infoButt_clicked();
    void on_addEntryButt_clicked();
    void on_dataView_cellDoubleClicked(int i, int j);
    void on_dataView_cellChanged(int i, int j);
    void on_dataView_cellClicked(int i, int j);

private:
    Ui::MainWindow *ui;
    Database database;
    QString editedData;
    int currRow;
};


#endif //UNTITLED5_MAINWINDOW_H
