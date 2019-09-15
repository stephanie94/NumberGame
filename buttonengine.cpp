#include "buttonengine.h"
#include "buttonpresentation.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

buttonEngine::buttonEngine(QWidget *parent) : QWidget(parent)
{


}


void buttonEngine::startgjett()
{

    antallforsok=0;
    std::srand( std::time(0));
    int tilfeldigtallet=rand()%9+0;

    tilfeldigtall=tilfeldigtallet;

}

void buttonEngine::tallregn(int tall)
{

    antallforsok++;

    if(tall==tilfeldigtall){

      emit riktig(tall,antallforsok);
    }

    else if(tall<tilfeldigtall){

        emit forstort(tall);

    }

    else if(tall>tilfeldigtall){

        emit forlite(tall);


    }


}


