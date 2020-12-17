/*****************************************************************************
@Project name: 02test
@Author: 代登辉
@Creation date : 2020-11-17
@Description: 注册
@Completion date: 完成日期
*****************************************************************************/


#include "register.h"
#include "ui_register.h"
#include "user.h"
#include "mysql.h"
#include <QDebug>
#include <QMessageBox>

/*************************************************
Function: Register
Description:
Others:
*************************************************/
Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);

    this->setWindowTitle(QString("超市库存管理系统"));
    // 去掉窗口最大最小化，和关闭
    this->setWindowFlags(Qt::Window|Qt::WindowTitleHint);

}
/*************************************************
Function: Reguster
Description:
Others: 析构函数
*************************************************/
Register::~Register()
{
    delete ui;
}

// 当注册页面的注册按下
void Register::on_pushButton_login_clicked()
{
    Mysql sql;
    if(sql.isUid(ui->lineEdit_id->text().toInt())){
        ui->label_tip->clear();
        ui->label_tip->setStyleSheet(QString("color:red;"));
        ui->label_tip->setText(QString("编号已存在"));
        return;
    }
    // 用户名是否存在
    if(sql.isUname(ui->lineEdit_uname->text())!=-1){
        ui->label_tip->clear();
        ui->label_tip->setStyleSheet(QString("color:red;"));
        ui->label_tip->setText(QString("用户名已存在"));
        return;
    }
    // 两次密码是否一致
    if((QString::compare(ui->lineEdit_password->text(),ui->lineEdit_password_2->text(),
        Qt::CaseSensitive) == 0))
    {
        User user;
        user.setId(ui->lineEdit_id->text().toInt());
        user.setUname(ui->lineEdit_uname->text());
        user.setUpassword(ui->lineEdit_password->text());
        user.setExit(1);
        int age = ui->lineEdit_age->text().toInt();
        if(age>0&&age<200){ // 年龄
            user.setAge(age);
        }else{
            ui->label_tip->clear();
            ui->label_tip->setStyleSheet(QString("color:red;"));
            ui->label_tip->setText(QString("年龄错误"));
            return;
        }
        user.setSex(ui->combo_sex->currentText());
        user.setTel(ui->lineEdit_tel->text());
        if(sql.applyAccount(user)){
            user.printUser();
            QMessageBox::warning(nullptr, "注意", "用户创建成功");
            on_pushButton_clear_clicked();
        }

    }else { // 两次密码不一样
        ui->label_tip->clear();
        ui->label_tip->setStyleSheet(QString("color:red;"));
        ui->label_tip->setText(QString("两次密码不一致"));
    }
}

// 退出注册界面
void Register::on_pushButton_exit_clicked()
{
    this->hide();
    emit CreateEnd();
}

// 清空注册界面
void Register::on_pushButton_clear_clicked()
{
    ui->label_tip->clear();
    ui->label_tip->setStyleSheet(QString(""));
    ui->label_tip->setText(QString("欢迎注册"));
    ui->lineEdit_age->clear();
    ui->lineEdit_password->clear();
    ui->lineEdit_password_2->clear();
    ui->lineEdit_tel->clear();
    ui->lineEdit_uname->clear();
    ui->combo_sex->setCurrentIndex(0);
    ui->lineEdit_id->clear();
}
