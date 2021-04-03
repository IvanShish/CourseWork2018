#ifndef REDUCTION_BMP_H
#define REDUCTION_BMP_H

#include <QDialog>
#include <QPushButton>
#include <QCheckBox>
#include <QLabel>
#include <QSpinBox>
#include <QLayout>
#include <QColorDialog>
#include <QRadioButton>

class reduction_bmp: public QDialog
{
    Q_OBJECT
public:
    reduction_bmp(QDialog* parent = nullptr);
    ~reduction_bmp();
private:
    QLabel* text;
    QPushButton* button_ok;
    QRadioButton* button_centr;
    QRadioButton* button_leftup;
    QRadioButton* button_rightup;
    QRadioButton* button_leftdown;
    QRadioButton* button_rightdown;
    QVBoxLayout* vertical_lay;
    int point;
public slots:
    void make_reduction();
    void centr();
    void leftup();
    void leftdown();
    void rightup();
    void rightdown();
signals:
    void do_reduction(int);
};

#endif // REDUCTION_BMP_H
