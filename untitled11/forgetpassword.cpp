#include "forgetpassword.h"
#include "ui_forgetpassword.h"
#include "resetpassword.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "login.h"

ForgetPassword::ForgetPassword(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ForgetPassword)
{
    ui->setupUi(this);
}

ForgetPassword::~ForgetPassword()
{
    delete ui;
}

void ForgetPassword::on_submitButton_clicked()
{
    QString username = ui->usernameLineEdit->text();
    QString input = ui->emailOrPhoneLineEdit->text();

    if (verifyEmailOrPhone(username, input)) {
        ResetPassword *resetWindow = new ResetPassword();
        resetWindow->show();
        this->close();
    } else {
        QMessageBox::warning(this, "Error", "Username, email, or phone number is incorrect.");
    }
}

bool ForgetPassword::verifyEmailOrPhone(const QString &username, const QString &input)
{
    QFile file("users.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        if (fields[0] == username && (fields[2] == input || fields[3] == input)) {
            return true;
        }
    }
    return false;
}

void ForgetPassword::on_backButton_clicked()
{
    Login *loginWindow = new Login();
    loginWindow->show();
    this->close();
}

