#include "utree.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UTree w;
    w.show();
    return a.exec();
}
