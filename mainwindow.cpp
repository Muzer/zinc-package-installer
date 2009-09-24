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
    about_dialog.setText("<b>Zinc Package Installer</b><br>Thomas Leese - <a href=\"mailto:TomMan81@googlemail.com\">TomMan81@googlemail.com</a><br>Murray Colpman - <a href=\"mailto:muzerakascooby@gmail.com\">muzerakascooby@gmail.com</a>");
    QString text = "Licensed Under GPLv3 or more.\nVersion: ";
    text.append(app_version.c_str());
    about_dialog.setDetailedText(text);
    about_dialog.exec();
}

void MainWindow::load_file()
{
    QString file = filename.c_str();
    if (filename == "none")
    {
        //dialog.setFilter("*.deb; *.rpm; *.bin");
        file = QFileDialog::getOpenFileName(0, "Select file to install...");
    }
    if (file == NULL)
    {
        exit(0);
    }
    filename = file.toStdString();
    ui->lbl_app_name->setText(QString(filename.c_str()));
}

MainWindow::~MainWindow()
{
    delete ui;
}