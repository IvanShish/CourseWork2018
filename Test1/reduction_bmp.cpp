#include "reduction_bmp.h"

reduction_bmp::reduction_bmp(QDialog* parent) : QDialog(parent)
{
    point = 0;
    text = new QLabel;
    text->setText("Выберите точку, относительно которой будет будет производиться действие");
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

    vertical_lay = new QVBoxLayout;
    vertical_lay->addWidget(text);
    vertical_lay->addWidget(button_centr);
    vertical_lay->addWidget(button_rightup);
    vertical_lay->addWidget(button_rightdown);
    vertical_lay->addWidget(button_leftup);
    vertical_lay->addWidget(button_leftdown);
    vertical_lay->addWidget(button_ok);
    setLayout(vertical_lay);

    connect(button_ok, SIGNAL(clicked()), this, SLOT(close()));
    connect(button_centr, SIGNAL(pressed()), this, SLOT(centr()));
    connect(button_leftup, SIGNAL(pressed()), this, SLOT(leftup()));
    connect(button_leftdown, SIGNAL(pressed()), this, SLOT(leftdown()));
    connect(button_rightup, SIGNAL(pressed()), this, SLOT(rightup()));
    connect(button_rightdown, SIGNAL(pressed()), this, SLOT(rightdown()));
    connect(button_ok, SIGNAL(clicked()), this, SLOT(make_reduction()));
}

reduction_bmp::~reduction_bmp(){
    delete text;
    delete button_ok;
    delete vertical_lay;
    delete button_centr;
    delete button_leftup;
    delete button_rightup;
    delete button_leftdown;
    delete button_rightdown;
}

void reduction_bmp::centr()
{
    point = 0;
}

void reduction_bmp::leftup()
{
    point = 1;
}

void reduction_bmp::leftdown()
{
    point = 2;
}

void reduction_bmp::rightup()
{
    point = 3;
}

void reduction_bmp::rightdown()
{
    point = 4;
}

void reduction_bmp::make_reduction()
{
    emit do_reduction(point);
}
