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

class MainWindow : public QWidget {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr, std::string fileName="example1.txt");

    ~MainWindow() override;

public slots:
    void on_saveDataButt_clicked();
    void on_getDataButt_clicked();
    void on_searchDataButt_clicked();
    void on_cancelSearchDataButt_clicked();
    void on_deleteEntryButt_clicked();
    void on_infoButt_clicked();
    void on_addEntryButt_clicked();
    void on_dataView_cellDoubleClicked(int i, int j);
    void on_dataView_cellChanged(int i, int j);
    void on_dataView_cellPressed(int i, int j);

private:
    Ui::MainWindow *ui;
    Database database;
    QString editedData;
    int currRow;
    bool isSearched;
};


#endif //UNTITLED5_MAINWINDOW_H
