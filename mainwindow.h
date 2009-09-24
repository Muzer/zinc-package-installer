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
    string get_root_cmd();
    string get_distro();
    void show_install_error_distro();
    string exec(string cmd);

private:
    Ui::MainWindow *ui;
    string filename;
    string filename_2;
    string filetype;
    string app_version;
    string accepted_formats[2];
    string root_cmd;

private slots:
    void show_about_dialog();
    void install_file();
};

int array_find(string array[], int length, string target);
vector<string> split_string(string str, string token);

#endif // MAINWINDOW_H
