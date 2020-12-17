/*****************************************************************************
@Project name: Description:
@Author: 代登辉
@Creation date : 2020-11-16
@Description: 登陆界面头文件
@Completion date: 完成日期
*****************************************************************************/


#ifndef LOGIN_H
#define LOGIN_H
#include <QWidget>
#include <QSqlDatabase>
#include "user.h"

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

    // 自定义函数
    bool verifyLogin(const QString name,const QString password); //登陆验证

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_exit_clicked();

private:
    Ui::Login *ui;

    // 自定义属性
    QSqlDatabase mysql; //数据库
    User use;

signals:
    void loginOk(); // 登陆成功信号
    void user(User use);    // 不能用大写 和User构造函数相同
};

#endif // LOGIN_H
