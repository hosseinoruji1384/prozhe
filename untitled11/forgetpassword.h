#ifndef FORGETPASSWORD_H
#define FORGETPASSWORD_H

#include <QWidget>

namespace Ui {
class ForgetPassword;
}

class ForgetPassword : public QWidget
{
    Q_OBJECT

public:
    explicit ForgetPassword(QWidget *parent = nullptr);
    ~ForgetPassword();

private slots:
    void on_submitButton_clicked();

    void on_backButton_clicked();

private:
    Ui::ForgetPassword *ui;
    bool verifyEmailOrPhone(const QString &username, const QString &input);
};

#endif // FORGETPASSWORD_H
