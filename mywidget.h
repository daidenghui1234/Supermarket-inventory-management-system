/*****************************************************************************
@Project name: Description:
@Author: 代登辉
@Creation date : 2020-11-16
@Description: 主窗口头文件
@Completion date: 完成日期
*****************************************************************************/


#ifndef MYWIDGET_H
#define MYWIDGET_H
#include <QWidget>
#include "user.h"
#include "login.h"  // 登陆界面
#include "register.h"  // 注册界面
#include "supplierform.h"  // 供应商界面
#include "usermanangeform.h"  // 用户管理
#include "goodmanangeform.h"  // 商品管理
#include "inform.h"  // 商品入库
#include "outform.h" // 商品出库
#include "statementform.h"  // 报表管理

#include "warningform.h"

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget();

    // 槽函数
    void showMainwindow();      // 显示主窗口
    void setUser(User use);     // 从注册界面得到用户名
    void showSupplier();        // 显示供应商管理界面
    void showMainHideSup();     // 隐藏供应商界面显示主窗口
    void showUserFrom();        // 显示用户管理界面
    void showGoodFrom();        // 显示商品管理界面
    void showInFrom();          // 显示商品入库界面
    void showOutFrom();         // 显示商品出库界面
    void showStatementFrom();   // 显示报表管理界面


private:
    Ui::MyWidget *ui;

    // 页面
    Login *login;
    SupplierForm *supfrom;
    UserManangeForm *userfrom;
    GoodManangeForm *goodfrom;
    InForm *infrom;
    OutForm *outfrom;
    StatementForm *statementForm;
    WarningForm *warningForm;

    // 自定义属性
    User use;
};

#endif // MYWIDGET_H
