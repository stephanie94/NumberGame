#include "buttonpresentation.h"
#include "buttondialog.h"
#include <QtWidgets>
#include <iostream>

buttonPresentation::buttonPresentation(QWidget *parent) : QWidget(parent)
{

    centralWidget = new QWidget();
    layout = new QHBoxLayout();
    centralWidget->setWindowTitle("Tilfeldig terning");

    for (int i = 0; i<10; i++){

        knapp = new QPushButton(QString::number(i));
        knapp->setEnabled(false);
        layout->addWidget(knapp);
        knappene.push_back(knapp);

        knapp->show();


        QSignalMapper *mapper = new QSignalMapper(this);

          connect(knapp, SIGNAL(clicked()), mapper, SLOT(map()));
          mapper->setMapping(knapp, i);
          connect(mapper, SIGNAL(mapped(int)),this, SLOT(keytrykket(int)));

    }

    startprg=new QPushButton("Start nytt");
    startprg->show();
    layout->addWidget(startprg);
    connect(startprg, SIGNAL(clicked()), this, SLOT(startgjett()));


    centralWidget->setLayout(layout);
    centralWidget->show();



}


void buttonPresentation::startgjett()
{


    for(std::vector<QPushButton*>::iterator it = knappene.begin(); it != knappene.end(); ++it) {

        (*it)->setEnabled(true);
        (*it)->setStyleSheet("QPushButton {background-color: none;}");

    }


    emit startprogram();

}

void buttonPresentation::keytrykket(int nummer)
{

    startprg->setEnabled(false);

    emit tallregnut(nummer);


}

void buttonPresentation::riktigtall(int tall,int antall)
{

  knappene[tall]->setStyleSheet("QPushButton {background-color: green;}");


  buttonDialog dialog;

  dialog.setAntall(antall);

  dialog.runprg();


  startprg->setEnabled(true);

}

void buttonPresentation::forlitetall(int tall)
{

    int plusstall =tall;
    while(plusstall<10){

        knappene[plusstall]->setStyleSheet("QPushButton {background-color: red;}");
        plusstall++;

    }

}

void buttonPresentation::forstorttall(int tall)
{

    int plusstall =tall;
    while(plusstall>=0){

        knappene[plusstall]->setStyleSheet("QPushButton {background-color: red;}");
        plusstall--;

    }

}



