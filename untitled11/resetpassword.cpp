#include "resetpassword.h"
#include "ui_resetpassword.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "mainwindow.h"

ResetPassword::ResetPassword(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ResetPassword)
{
    ui->setupUi(this);
}

ResetPassword::~ResetPassword()
{
    delete ui;
}

void ResetPassword::on_submitButton_clicked()
{
    QString username = ui->usernameLineEdit->text();
    QString newPassword = ui->newPasswordLineEdit->text();
    QString confirmPassword = ui->confirmPasswordLineEdit->text();

    if (resetUserPassword(username, newPassword, confirmPassword)) {
        QMessageBox::information(this, "Success", "Password reset successfully.");
        MainWindow *mainWindow = new MainWindow();
        mainWindow->show();
        this->close();
    } else {
        QMessageBox::warning(this, "Error", "Passwords do not match or username is incorrect.");
    }
}

bool ResetPassword::resetUserPassword(const QString &username, const QString &newPassword, const QString &confirmPassword)
{
    if (newPassword != confirmPassword)
        return false;

    QFile file("users.txt");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
        return false;

    QStringList lines;
    QTextStream in(&file);
    while (!in.atEnd()) {
        lines.append(in.readLine());
    }

    file.resize(0);

    QTextStream out(&file);
    bool userFound = false;
    for (QString &line : lines) {
        QStringList fields = line.split(",");
        if (fields[0] == username) {
            fields[1] = newPassword;
            userFound = true;
        }
        out << fields.join(",") << "\n";
    }

    return userFound;
}

void ResetPassword::on_backButton_clicked()
{
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
    this->close();
}

