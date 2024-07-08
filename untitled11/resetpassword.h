#ifndef RESETPASSWORD_H
#define RESETPASSWORD_H

#include <QWidget>

namespace Ui {
class ResetPassword;
}

class ResetPassword : public QWidget
{
    Q_OBJECT

public:
    explicit ResetPassword(QWidget *parent = nullptr);
    ~ResetPassword();

private slots:
    void on_submitButton_clicked();

    void on_backButton_clicked();

private:
    Ui::ResetPassword *ui;
    bool resetUserPassword(const QString &username, const QString &newPassword, const QString &confirmPassword);
};

#endif // RESETPASSWORD_H
