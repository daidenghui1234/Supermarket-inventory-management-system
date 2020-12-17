/*****************************************************************************
@Project name: Description:
@Author: 代登辉
@Creation date : 2020-11-16
@Description: 登陆界面
@Completion date: 完成日期
*****************************************************************************/


#include "login.h"
#include "ui_login.h"
#include <QString>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include "user.h"

#include "mysql.h"

/*************************************************
Function: Login
Description: Login
Others: // 其它说明
*************************************************/
Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    // 去掉窗口最大最小化，和关闭
    this->setWindowFlags(Qt::Window|Qt::WindowTitleHint);
    //setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint);

    this->setWindowTitle(QString("登录"));
}

/*************************************************
Function: Login
Description: 注册界面析构函数
Others: 析构函数
*************************************************/
Login::~Login()
{
    delete ui;
}


/*************************************************
Function: on_pushButton_login_clicked
Description: 自动生成槽函数---当点击登录后调用
*************************************************/
void Login::on_pushButton_login_clicked()
{
    Mysql sql;
    // 当登录验证成功，发送登录成功信号
    if(sql.verifyLogin(ui->lineEdit_uname->text(),ui->lineEdit_password->text())){
        int uid = sql.isUname(ui->lineEdit_uname->text());
        sql.setUser(uid,this->use);
        emit user(this->use);
        emit loginOk();
        ui->label_tip->clear();
        ui->label_tip->setStyleSheet(QString(""));
        ui->label_tip->setText(QString("欢迎登录"));
        this->close();
    }
    else{
        ui->label_tip->clear();
        ui->label_tip->setStyleSheet(QString("color:red;"));
        ui->label_tip->setText(QString("用户名或密码错误"));
    }
}

/*************************************************
Function: on_pushButton_login_clicked
Description: 自动生成槽函数---当点击退出后调用
*************************************************/
void Login::on_pushButton_exit_clicked()
{
    this->close();
}
