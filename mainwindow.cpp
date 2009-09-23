#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    filename = "none";
    app_version = "0.1 SVN";
}

void MainWindow::set_filename(string name)
{
    filename = name;
}

void MainWindow::show_about_dialog()
{
    QMessageBox about_dialog;
    about_dialog.setText("<b>Zinc Package Installer</b><br>Thomas Leese - TomMan81@googlemail.com");
    QString text = "Licensed Under GPLv3 or more.\nVersion: ";
    text.append(app_version.c_str());
    about_dialog.setDetailedText(text);
    about_dialog.exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}
