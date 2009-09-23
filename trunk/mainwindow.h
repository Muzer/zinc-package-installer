#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QtGui/QMainWindow>
#include <QtGui/QMessageBox>

using namespace std;

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void set_filename(string name);

private:
    Ui::MainWindow *ui;
    string filename;
    string app_version;

private slots:
    void show_about_dialog();
};

#endif // MAINWINDOW_H
