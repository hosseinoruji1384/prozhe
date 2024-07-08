#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>

namespace Ui {
class Signup;
}

class Signup : public QWidget
{
    Q_OBJECT

public:
    explicit Signup(QWidget *parent = nullptr);
    ~Signup();

private slots:
    void on_signupButton_clicked();

    void on_backButton_clicked();

private:
    Ui::Signup *ui;
    bool saveUser(const QString &username, const QString &password, const QString &email, const QString &phone);
    bool validatePhoneNumber(const QString &phone);
    bool validateEmail(const QString &email);
};

#endif // SIGNUP_H
