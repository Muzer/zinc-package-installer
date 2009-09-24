#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QtGui/QErrorMessage>
#include <QtGui/QMainWindow>
#include <QtGui/QMessageBox>
#include <QtGui/QFileDialog>

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
    void load_file();
    string get_file_type();

private:
    Ui::MainWindow *ui;
    string filename;
    string app_version;
    string accepted_formats[1];

private slots:
    void show_about_dialog();
};

int array_find(string array[], int length, string target);
vector<string> split_string(string str, string token);

#endif // MAINWINDOW_H
