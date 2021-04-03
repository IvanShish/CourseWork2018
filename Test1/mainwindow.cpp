#include "mainwindow.h"
//"Clear", "Run qmake"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    img = new MyImage();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete img;
}

void MainWindow::on_inversion_triggered()
{
    ui->statusBar->showMessage("Вы выбрали функцию №1 - инверсия цвета");

    inversionn* invers = new inversionn;
    connect(invers, SIGNAL(change_inversation(int, int, int, int)), img, SLOT(inversion(int, int, int, int)));
    invers->exec();
    delete invers;

    QString f = "D://out.bmp";
    QPixmap pix(f);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
}

void MainWindow::on_bw_triggered()
{
    ui->statusBar->showMessage("Вы выбрали функцию №2 - черно-белое изображение");

    bww* blackWhite = new bww;
    connect(blackWhite, SIGNAL(change_bw(int, int, int, int)), img, SLOT(bw(int, int, int, int)));
    blackWhite->exec();
    delete blackWhite;

    QString f = "D://out.bmp";
    QPixmap pix(f);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
}

void MainWindow::on_open_my_file_triggered()
{
    filename = QFileDialog::getOpenFileName(this,
                tr("Inversion"), "D://C++//Projects//Test1//img", "All files (*.bmp)"
                );
    QPixmap pix(filename);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    int error;
    error = img->loadimage(filename.toUtf8());
    if (error != 1) {
        QMessageBox::critical(this, "ERROR", "Not available format");
    }
}

void MainWindow::on_actionReset_triggered()
{
    QPixmap pix(filename);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    img->resetimage(filename.toUtf8());
}

void MainWindow::on_increase_triggered()
{
    increase_bmp* color = new increase_bmp();
    connect(color, SIGNAL(do_increase(QColor*, int)), img, SLOT(increase(QColor*, int)));
    color->exec();
    delete color;

    QString f = "D://out.bmp";
    QPixmap pix(f);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
}

void MainWindow::on_reduction_triggered()
{
    reduction_bmp* reduct = new reduction_bmp();
    connect(reduct, SIGNAL(do_reduction(int)), img, SLOT(reduction(int)));
    reduct->exec();
    delete reduct;

    QString f = "D://out.bmp";
    QPixmap pix(f);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
}
