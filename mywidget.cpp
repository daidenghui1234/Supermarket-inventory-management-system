/*****************************************************************************
@Project name: Description:
@Author: 代登辉
@Creation date : 2020-11-16
@Description: 主窗口cpp文件
@Completion date: 完成日期
*****************************************************************************/


#include "mywidget.h"
#include "ui_mywidget.h"
#include "login.h"  // 登陆界面
#include "register.h"  // 注册界面
#include "supplierform.h"  // 注册界面
#include <QDebug>
#include "user.h"


/*************************************************
Function: MyWidget
Description: MyWidget构造函数
*************************************************/
MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    this->setWindowTitle(QString("超市库存管理系统"));
    // 去掉窗口最大最小化，和关闭
    // this->setWindowFlags(Qt::Window|Qt::WindowTitleHint);

    // 界面
    login = new Login();
    login->show();
    userfrom = new UserManangeForm();
    supfrom = new SupplierForm();
    goodfrom = new GoodManangeForm();
    infrom = new InForm();
    outfrom = new OutForm();
    statementForm = new StatementForm();

    warningForm = new WarningForm();
    warningForm->hide();
    connect(warningForm,&WarningForm::myWarning,warningForm,&WarningForm::show);

    // 当登陆成功后显示主窗口
    connect(login,&Login::loginOk,this,&MyWidget::showMainwindow);
    connect(login,&Login::user,this,&MyWidget::setUser);

    // 供应商管理界面的显示和隐藏
    connect(ui->pushButton_supplier,&QPushButton::clicked,this,&MyWidget::showSupplier);
    connect(supfrom,&SupplierForm::Supplierclose,this,&MyWidget::showMainwindow);


    // 用户管理界面的显示和隐藏
    connect(ui->pushButton_user,&QPushButton::clicked,this,&MyWidget::showUserFrom);
    connect(userfrom,&UserManangeForm::UserManageclose,this,&MyWidget::showMainwindow);

    // 商品管理界面的隐藏和显示
    connect(ui->pushButton_good,&QPushButton::clicked,this,&MyWidget::showGoodFrom);
    connect(goodfrom,&GoodManangeForm::GoodManangeclose,this,&MyWidget::showMainwindow);

    // 入库管理界面的隐藏和显示
    connect(ui->pushButton_in,&QPushButton::clicked,this,&MyWidget::showInFrom);
    connect(infrom,&InForm::InFromclose,this,&MyWidget::showMainwindow);

    // 出库管理界面的隐藏和显示
    connect(ui->pushButton_out,&QPushButton::clicked,this,&MyWidget::showOutFrom);
    connect(outfrom,&OutForm::OutFromclose,this,&MyWidget::showMainwindow);

    // 报表管理界面的隐藏和显示
    connect(ui->pushButton_statement,&QPushButton::clicked,this,&MyWidget::showStatementFrom);
    connect(statementForm,&StatementForm::Statementclose,this,&MyWidget::showMainwindow);
}


/*************************************************
Function: MyWidget
Description:菜单析构函数
Others: 析构函数
*************************************************/
MyWidget::~MyWidget()
{
    delete ui;
}

/*************************************************
Function: showMainwindow
Description:  显示主窗口关闭登陆窗口
Others: // 槽函数
*************************************************/
void MyWidget::showMainwindow()
{
    this->show();
}

/*************************************************
Function: setUser
Description: 设置用户名
Others: 槽函数
*************************************************/
void MyWidget::setUser(User use)
{
    this->use = use;
    infrom->setUid(use.getId());
    outfrom->setUid(use.getId());
    statementForm->setUid(use.getId());
}

/*************************************************
Function: showSupplier
Description: 显示供应商界面，隐藏主窗口
Others: 槽函数
*************************************************/
void MyWidget::showSupplier()
{
    supfrom->show();
    this->hide();
}

/*************************************************
Function: showUserFrom
Description: 显示用户管理界面，隐藏主窗口
Others: 槽函数
*************************************************/
void MyWidget::showUserFrom()
{
    this->hide();
    userfrom->show();
}

/*************************************************
Function: showGoodFrom
Description: 显示商品管理界面，隐藏主窗口
Others: 槽函数
*************************************************/
void MyWidget::showGoodFrom()
{
    this->hide();
    goodfrom->show();
}

/*************************************************
Function: showInFrom
Description: 显示入库管理界面，隐藏主窗口
Others: 槽函数
*************************************************/
void MyWidget::showInFrom()
{
    this->hide();
    infrom->show();
}

/*************************************************
Function: showOutFrom
Description: 显示出库管理界面，隐藏主窗口
Others: 槽函数
*************************************************/
void MyWidget::showOutFrom()
{
    this->hide();
    outfrom->show();
}

/*************************************************
Function: showStatementFrom
Description: 显示报表管理界面，隐藏主窗口
Others: 槽函数
*************************************************/
void MyWidget::showStatementFrom()
{
    this->hide();
    statementForm->show();
}



