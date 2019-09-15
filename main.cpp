#include <QApplication>
#include <QtWidgets>
#include <buttonengine.h>
#include <buttonpresentation.h>
#include <buttondialog.h>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    buttonPresentation* window = new buttonPresentation();
    buttonEngine* engine = new buttonEngine();
    buttonDialog* dialog = new buttonDialog();


    QWidget::connect(window, SIGNAL(startprogram()), engine, SLOT(startgjett()));
    QWidget::connect(window, SIGNAL(tallregnut(int)), engine, SLOT(tallregn(int)));
    QWidget::connect(engine, SIGNAL(riktig(int,int)), window, SLOT(riktigtall(int,int)));
    QWidget::connect(engine, SIGNAL(forstort(int)), window, SLOT(forstorttall(int)));
    QWidget::connect(engine, SIGNAL(forlite(int)), window, SLOT(forlitetall(int)));
    QWidget::connect(engine, SIGNAL(antall(int)), dialog, SLOT(antallforsok(int)));

    return app.exec();
}
