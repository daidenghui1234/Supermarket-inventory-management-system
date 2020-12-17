/*****************************************************************************
@Project name: 02test
@Author: 代登辉
@Creation date : 2020-11-28
@Description: 用户管理界面头文件
@Completion date: 完成日期
*****************************************************************************/


#ifndef USERMANANGEFORM_H
#define USERMANANGEFORM_H

#include <QWidget>
#include "register.h"
#include "mysql.h"
#include <QStandardItemModel>

namespace Ui {
class UserManangeForm;
}

class UserManangeForm : public QWidget
{
    Q_OBJECT

public:
    explicit UserManangeForm(QWidget *parent = 0);
    ~UserManangeForm();


private slots:
    void on_pushButton_close_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_cancel_clicked();

    void on_pushButton_refresh_clicked();

    void on_pushButton_sure_clicked();

    void on_pushButton_find_clicked();

private:
    Ui::UserManangeForm *ui;

    Register *reg;

    Mysql sql;
    QStandardItemModel *model;

    int list[20];
    int size;
    void setTable(int i,std::vector<User>::iterator u);
    void getUser(int row,User & user);
    void initTable();
signals:
    // 自定义信号
    void UserManageclose();
};

#endif // USERMANANGEFORM_H
