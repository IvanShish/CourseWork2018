#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "my_bmp.h"
#include "inversionn.h"
#include "bw.h"
#include "increase_bmp.h"
#include "reduction_bmp.h"
#include <QBoxLayout>
#include <QPixmap>
#include <QFileDialog>
#include <QFile>
#include <QTextBrowser>
#include <QMessageBox>
#include <QDebug>
#include <QSize>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_open_my_file_triggered();

    void on_inversion_triggered();

    void on_bw_triggered();

    void on_actionReset_triggered();

    void on_increase_triggered();

    void on_reduction_triggered();

private:
    Ui::MainWindow *ui;
    MyImage* img;
    QString filename;
};

#endif // MAINWINDOW_H
