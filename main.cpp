#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    int arg_loop;
    if (argc > 1)
    {
        for(arg_loop = 1; arg_loop < argc; arg_loop++){
            if(argv[arg_loop][0] != '-'){
                w.set_filename(string(argv[arg_loop]));
                w.load_file();
                w.show();
                a.exec();
                while(!w.isHidden()){
                    sleep(1);
                }
            } else {
                // parsing code
            }
        }
    } else {
        w.load_file();
        w.show();
        return a.exec();
    }
}
