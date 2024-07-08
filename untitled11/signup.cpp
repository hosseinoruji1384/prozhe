#include "signup.h"
#include "ui_signup.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "login.h"
#include "mainwindow.h"

Signup::Signup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Signup)
{
    ui->setupUi(this);
}

Signup::~Signup()
{
    delete ui;
}

void Signup::on_signupButton_clicked()
{
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    QString email = ui->emailLineEdit->text();
    QString phone = ui->phoneLineEdit->text();

    if (!validatePhoneNumber(phone)) {
        QMessageBox::warning(this, "Error", "Phone number must be 11 digits and start with 09.");
        return;
    }

    if (!validateEmail(email)) {
        QMessageBox::warning(this, "Error", "Email must be a valid Gmail address (example@gmail.com).");
        return;
    }

    if (saveUser(username, password, email, phone)) {
        QMessageBox::information(this, "Success", "Signup successful.");
        // Navigate to the login window
        Login *loginWindow = new Login();
        loginWindow->show();
        this->close();
    } else {
        QMessageBox::warning(this, "Error", "Signup failed. Please try again.");
    }
}

bool Signup::saveUser(const QString &username, const QString &password, const QString &email, const QString &phone)
{
    QFile file("users.txt");
    if (!file.open(QIODevice::Append | QIODevice::Text))
        return false;

    QTextStream out(&file);
    out << username << "," << password << "," << email << "," << phone << "\n";

    return true;
}

bool Signup::validatePhoneNumber(const QString &phone)
{
    return phone.length() == 11 && phone.startsWith("09") && phone.toLongLong();
}

bool Signup::validateEmail(const QString &email)
{
    return email.endsWith("@gmail.com");
}

void Signup::on_backButton_clicked()
{
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
    this->close();
}

