#include <QApplication>
#include "Igra.h"

Igra* igra;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    igra = new Igra();
    igra->show();
    igra->displayMainMenu();

    return a.exec();
}
