#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_loginButton_clicked();
    void on_forgotPasswordButton_clicked();

    void on_backButton_clicked();

private:
    Ui::Login *ui;
    bool authenticate(const QString &username, const QString &password);
};

#endif // LOGIN_H
