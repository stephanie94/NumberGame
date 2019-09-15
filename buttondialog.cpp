#include "buttondialog.h"
#include <QPushButton>
#include <iostream>
#include <QtWidgets>
#include <ctime>
#include <cstdlib>
#include <QDialog>
#include <string>
#include <sstream>

buttonDialog::buttonDialog(QWidget *parent) : QWidget(parent)
{
     dialogLay = new QHBoxLayout();
     dialog = new QDialog();
     dialog->setLayout(dialogLay);



}

void buttonDialog::setAntall(int value)
{
    antall = value;
}

void buttonDialog::antallforsok(int tall)
{

    antall=tall;


}

void buttonDialog::runprg()
{

    std::string Result;
    std::stringstream convert;
    convert << antall;
    Result = convert.str();

    Result = "Du brukte  " + Result + " forsok";

    QMovie *movie = new QMovie(":/new/prefix1/giphy.gif");
    QLabel *processLabel = new QLabel(this);
    processLabel->setMovie(movie);
    movie->start();
    dialogLay->addWidget(processLabel);

    const char * c = Result.c_str();
    QLabel *lbl = new QLabel("Gratulerer du vant hele spillet!");
    QLabel *txt = new QLabel(c);
    QFont font = lbl->font();
    font.setPointSize(15);
    lbl->setFont(font);
    txt->setFont(font);

    dialogLay->addWidget(lbl);
    dialogLay->addWidget(txt);

    QPushButton *slutt = new QPushButton("Ok, start på nytt");
    dialogLay->addWidget(slutt);
    connect(slutt, SIGNAL(clicked()), dialog, SLOT(close()));

    dialog->exec();


}
