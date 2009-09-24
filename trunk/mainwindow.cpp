#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    filename = "none";
    app_version = "0.1 SVN";
    accepted_formats[0] = "deb";
}

MainWindow::~MainWindow()
{
    MainWindow::hide();
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
    filetype = get_file_type();
    if (array_find(accepted_formats, 1, filetype) == -1)
    {
        QErrorMessage msg;
        msg.setWindowTitle("Format not supported!");
        string message = "The format \"." + filetype + "\" isn't currently supported. If you think the format should be supported, submit a bug at <a href=\"http://code.google.com/p/zinc-package-installer\">code.google.com/p/zinc-package-installer</a>.";
        msg.showMessage(QString(message.c_str()));
        msg.exec();
        ui->btn_install->setEnabled(false);
    }
    ui->lbl_filetype->setText(filetype.c_str());
}

string MainWindow::get_file_type()
{
    string filetype = "???";
    unsigned int end = split_string(filename, ".").size();
    filetype = split_string(filename, ".")[end - 1];
    return filetype;
}

string MainWindow::get_root_cmd()
{
    string root_cmd = "konsole sudo";
    return root_cmd;
}

string MainWindow::get_distro()
{
    string distro = "fedora";
    return distro;
}

void MainWindow::show_install_error_distro()
{
    QErrorMessage msg;
    msg.setWindowTitle("Format not supported!");
    string message = "You have choosen to install " + filename_2 + " which is a deb file on " + get_distro() + " and that distro doesn't support that format, if you think this is wrong submit a bug at code.google.com/p/zin-package-installer.";
    msg.showMessage(QString(message.c_str()));
    msg.exec();
    ui->btn_install->setEnabled(false);
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

void MainWindow::install_file()
{
    filename_2 = split_string(filename, "_")[0];
    root_cmd = get_root_cmd();
    if (filetype == "deb")
    {
        if (get_distro() != "debian" || get_distro() != "ubuntu")
        {
            show_install_error_distro();
            return;
        }
        // Install file
    }
    else if (filetype == "rpm")
    {
        if (get_distro() != "fedora" || get_distro() != "redhat" || get_distro() != "opensuse" || get_distro() != "suse")
        {
            show_install_error_distro();
            return;
        }
        // Install file
    }
}

// Functions

int array_find(string array[], int length, string target)
{
    int flag = -1;
    int i;
    for (i = 0; i < length; i++)
    {
        if (target.compare(array[i].c_str()) == 0)
        {
            flag = i;
        }
    }
    return flag;
}

vector<string> split_string(string str, string token)
{
    vector<string> strings;
    int len = 0;
    unsigned int pos = str.find(token, len);
    while (pos != string::npos)
    {
        strings.push_back(str.substr(len, pos));
        str.erase(len, pos + 1);
        pos = str.find(token, len);
    }
    strings.push_back(str);
    return strings;
}
