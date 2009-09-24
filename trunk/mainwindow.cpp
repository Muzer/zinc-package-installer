#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    filename = "none";
    app_version = "0.1 SVN";
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Methods

void MainWindow::set_filename(string name)
{
    filename = name;
}

void MainWindow::load_file()
{
    QString file = filename.c_str();
    if (filename == "none")
    {
        file = QFileDialog::getOpenFileName(0, "Select file to install...");
    }
    if (file == NULL)
    {
        exit(0);
    }
    filename = file.toStdString();
    ui->lbl_app_name->setText(QString(filename.c_str()));
    ui->lbl_filename->setText(QString(filename.c_str()));
    ui->lbl_filetype->setText(QString(get_file_type().c_str()));
}

string MainWindow::get_file_type()
{
    string filetype = "???";
    return filetype;
}

// Slots

void MainWindow::show_about_dialog()
{
    QMessageBox about_dialog;
    about_dialog.setText("<b>Zinc Package Installer</b><br>Thomas Leese - <a href=\"mailto:TomMan81@googlemail.com\">TomMan81@googlemail.com</a><br>Murray Colpman - <a href=\"mailto:muzerakascooby@gmail.com\">muzerakascooby@gmail.com</a>");
    QString text = "Licensed Under GPLv3 or more.\nVersion: ";
    text.append(app_version.c_str());
    about_dialog.setDetailedText(text);
    about_dialog.exec();
}
