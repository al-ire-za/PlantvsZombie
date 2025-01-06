#include "Welcom_page.h"
#include "ResultWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    welcom_page w;
    ResultWindow x;

    x.show();

    return a.exec();
}
