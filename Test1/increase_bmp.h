#ifndef INCREASE_BMP_H
#define INCREASE_BMP_H

#include <QDialog>
#include <QPushButton>
#include <QCheckBox>
#include <QLabel>
#include <QSpinBox>
#include <QColor>
#include <QLayout>
#include <QColorDialog>
#include <QRadioButton>

class increase_bmp: public QDialog
{
    Q_OBJECT
public:
    increase_bmp(QDialog* parent = nullptr);
    ~increase_bmp();
private:
    QLabel* text;
    QPushButton* choose_color;
    QPushButton* button_ok;
    QRadioButton* button_centr;
    QRadioButton* button_leftup;
    QRadioButton* button_rightup;
    QRadioButton* button_leftdown;
    QRadioButton* button_rightdown;
    QColor* chosen_color;
    QHBoxLayout* horizontal_lay;
    QVBoxLayout* vertical_lay;
    int point;
public slots:
    void set_color();
    void make_increase();
    void centr();
    void leftup();
    void leftdown();
    void rightup();
    void rightdown();
signals:
    void do_increase(QColor*, int);
};

#endif // INCREASE_BMP_H
