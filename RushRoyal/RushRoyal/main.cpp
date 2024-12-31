#include "Welcom_page.h"
#include "ResultWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    welcom_page w;
    ResultWindow x(100,1,1000,10);

    x.show();

    return a.exec();
}
