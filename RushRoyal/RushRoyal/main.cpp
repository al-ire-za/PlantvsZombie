#include "Welcom_page.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    welcom_page w;

    w.show();
    return a.exec();
}
