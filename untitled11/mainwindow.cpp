#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "signup.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loginButton_clicked()
{
    Login *loginWindow = new Login();
    loginWindow->show();
    this->close();
}

void MainWindow::on_signupButton_clicked()
{
    Signup *signupWindow = new Signup();
    signupWindow->show();
    this->close();
}
