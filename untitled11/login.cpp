#include "login.h"
#include "ui_login.h"
#include "forgetpassword.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "mainwindow.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_loginButton_clicked()
{
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    if (authenticate(username, password)) {
        QMessageBox::information(this, "Success", "Login successful.");
    } else {
        QMessageBox::warning(this, "Error", "Username or password is incorrect.");
    }
}

void Login::on_forgotPasswordButton_clicked()
{
    ForgetPassword *forgetWindow = new ForgetPassword();
    forgetWindow->show();
    this->close();
}

bool Login::authenticate(const QString &username, const QString &password)
{
    QFile file("users.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        if (fields[0] == username && fields[1] == password) {
            return true;
        }
    }
    return false;
}

void Login::on_backButton_clicked()
{
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
    this->close();
}

