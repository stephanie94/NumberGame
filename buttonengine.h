#ifndef BUTTONENGINE_H
#define BUTTONENGINE_H

#include <QWidget>
#include <buttondialog.h>

class buttonEngine : public QWidget
{
    Q_OBJECT
public:
    explicit buttonEngine(QWidget *parent = 0);
    int tilfeldigtall;
    int antallforsok;
    buttonDialog *dialog;



signals:

    void riktig(int,int);
    void forlite(int);
    void forstort(int);
    void antall(int);

public slots:

    void startgjett();
    void tallregn(int);

};

#endif // BUTTONENGINE_H
