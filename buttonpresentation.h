#ifndef BUTTONPRESENTATION_H
#define BUTTONPRESENTATION_H

#include <QWidget>
#include <QtWidgets>
#include <buttondialog.h>

class buttonPresentation : public QWidget
{
    Q_OBJECT
public:
    explicit buttonPresentation(QWidget *parent = 0);


private:

    QHBoxLayout * layout;
    QHBoxLayout * dialogLay;
    QPushButton *knapp;
    QPushButton *startprg;
    QPushButton *slutt;
    QWidget *centralWidget;
    std::vector<QPushButton*> knappene;




signals:

    void startprogram();
    void tallregnut(int);

public slots:

    void startgjett();
    void keytrykket(int);


    void riktigtall(int,int);
    void forlitetall(int);
    void forstorttall(int);

};

#endif // BUTTONPRESENTATION_H
