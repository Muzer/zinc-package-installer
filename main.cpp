#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    if (argc > 1)
    {
        w.set_filename(string(argv[1]));
    }
    w.load_file();
    w.show();
    return a.exec();
}
