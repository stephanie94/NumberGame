#ifndef BUTTONDIALOG_H
#define BUTTONDIALOG_H

#include <QWidget>
#include <QtWidgets>

class buttonDialog : public QWidget
{
    Q_OBJECT
public:
    explicit buttonDialog(QWidget *parent = 0);

    void setAntall(int value);

private:
    QDialog *dialog;
    QHBoxLayout* dialogLay;
    int antall;

signals:

public slots:

    void antallforsok(int);
    void runprg();
};

#endif // BUTTONDIALOG_H
