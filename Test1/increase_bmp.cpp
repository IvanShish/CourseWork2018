#include "increase_bmp.h"

increase_bmp::increase_bmp(QDialog* parent) : QDialog(parent)
{
    point = 0;
    text = new QLabel;
    text->setText("Выберите точку, относительно которой будет будет производиться действие");
    choose_color = new QPushButton;
    choose_color->setText("Выбрать цвет");
    button_ok = new QPushButton;
    button_ok->setText("OK");

    button_centr = new QRadioButton;
    button_centr->setText("Центр");
    button_centr->setChecked(true);
    button_leftup = new QRadioButton;
    button_leftup->setText("Левая верхняя");
    button_rightup = new QRadioButton;
    button_rightup->setText("Правая верхняя");
    button_leftdown = new QRadioButton;
    button_leftdown->setText("Левая нижняя");
    button_rightdown = new QRadioButton;
    button_rightdown->setText("Правая нижняя");

    chosen_color = new QColor;
    chosen_color->setRgb(0, 0, 0);
    horizontal_lay = new QHBoxLayout;
    vertical_lay = new QVBoxLayout;

    vertical_lay->addWidget(text);
    horizontal_lay->addWidget(button_centr);
    horizontal_lay->addWidget(button_rightup);
    horizontal_lay->addWidget(button_rightdown);
    horizontal_lay->addWidget(button_leftup);
    horizontal_lay->addWidget(button_leftdown);
    vertical_lay->addLayout(horizontal_lay);
    vertical_lay->addWidget(choose_color);
    vertical_lay->addWidget(button_ok);
    setLayout(vertical_lay);

    connect(button_ok, SIGNAL(clicked()), this, SLOT(close()));
    connect(button_centr, SIGNAL(pressed()), this, SLOT(centr()));
    connect(button_leftup, SIGNAL(pressed()), this, SLOT(leftup()));
    connect(button_leftdown, SIGNAL(pressed()), this, SLOT(leftdown()));
    connect(button_rightup, SIGNAL(pressed()), this, SLOT(rightup()));
    connect(button_rightdown, SIGNAL(pressed()), this, SLOT(rightdown()));
    connect(choose_color, SIGNAL(clicked()), this, SLOT(set_color()));
    connect(button_ok, SIGNAL(clicked()), this, SLOT(make_increase()));
}

increase_bmp::~increase_bmp(){
    delete text;
    delete choose_color;
    delete button_ok;
    delete chosen_color;
    delete horizontal_lay;
    delete vertical_lay;
    delete button_centr;
    delete button_leftup;
    delete button_rightup;
    delete button_leftdown;
    delete button_rightdown;
}

void increase_bmp::set_color()
{
    *chosen_color = QColorDialog::getColor();
}

void increase_bmp::centr()
{
    point = 0;
}

void increase_bmp::leftup()
{
    point = 1;
}

void increase_bmp::leftdown()
{
    point = 2;
}

void increase_bmp::rightup()
{
    point = 3;
}

void increase_bmp::rightdown()
{
    point = 4;
}

void increase_bmp::make_increase()
{
    emit do_increase(chosen_color, point);
}
