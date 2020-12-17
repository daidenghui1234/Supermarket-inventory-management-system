/*****************************************************************************
@Project name: 02test
@Author: 代登辉
@Creation date : 2020-11-28
@Description: 用户管理界面头文件
@Completion date: 完成日期
*****************************************************************************/


#include "usermanangeform.h"
#include "ui_usermanangeform.h"
#include <QDebug>
#include <QStandardItemModel>
#include <QDateTime>
#include <QString>

/*************************************************
Function: UserManangeForm
Description: 用户管理构造函数
Others: 构造函数
*************************************************/
UserManangeForm::UserManangeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserManangeForm)
{
    ui->setupUi(this);

    size = 0;
    for(int i =0;i<20;i++){
        list[i] = 0;
    }

    this->setWindowTitle(QString("超市库存管理系统"));
    // 去掉窗口最大最小化，和关闭
    this->setWindowFlags(Qt::Window|Qt::WindowTitleHint);

    reg = new Register();
    connect(reg,&Register::CreateEnd,this,&UserManangeForm::show);

    this->model = new QStandardItemModel;   //创建一个标准的条目模型
    this->ui->tableView->setModel(model);   //将tableview设置成model这个标准条目模型的模板, model设置的内容都将显示在tableview上

    on_pushButton_find_clicked();

}

/*************************************************
Function: ~UserManangeForm
Description: 用户管理析构函数
Others: 析构函数
*************************************************/
UserManangeForm::~UserManangeForm()
{
    delete ui;
    delete reg;
}

/*************************************************
Function: on_pushButton_close_clicked
Description: 隐藏本窗口，发送窗口关闭事件
Others: 自动生成槽函数
*************************************************/
void UserManangeForm::on_pushButton_close_clicked()
{
    this->hide();
    emit UserManageclose();
}

/*************************************************
Function: on_pushButton_add_clicked
Description: 隐藏本窗口，显示注册界面
Others: 自动生成槽函数
*************************************************/
void UserManangeForm::on_pushButton_add_clicked()
{
    reg->show();
    this->hide();
}

/*************************************************
Function: on_pushButton_delete_clicked
Description: 删除用户
Others: 自动生成槽函数
*************************************************/
void UserManangeForm::on_pushButton_delete_clicked()
{

    int row = ui->tableView->currentIndex().row();
    int id = this->model->data(this->model->index(row,0)).toInt();
    list[size] =id;
    qDebug() << list[size]  << "row = " << row;
    size++;
    model->removeRow(ui->tableView->currentIndex().row());
}

void UserManangeForm::setTable(int i,std::vector<User>::iterator u)
{
    this->model->setItem(i, 0, new QStandardItem(QString("%1").arg(u->getId())));
    this->model->setItem(i, 1, new QStandardItem(QString(u->getUname())));
    this->model->setItem(i, 2, new QStandardItem(QString(u->getUpassword())));
    this->model->setItem(i, 3, new QStandardItem(QString(u->getSex())));
    this->model->setItem(i, 4, new QStandardItem(QString("%1").arg(u->getAge())));
    this->model->setItem(i, 5, new QStandardItem(QString(u->getTel())));
    this->model->setItem(i, 6, new QStandardItem(u->getTime().toString("yyyy年MM月dd日 hh:mm:ss")));
}

void UserManangeForm::getUser(int row,User & user)
{
    user.setId(model->data(model->index(row,0)).toInt());
    user.setExit(1);
    user.setUname(model->data(model->index(row,1)).toString());
    user.setUpassword(model->data(model->index(row,2)).toString());
    user.setSex(model->data(model->index(row,3)).toString());
    user.setAge(model->data(model->index(row,4)).toInt());
    user.setTel(model->data(model->index(row,5)).toString());
    user.setTime(model->data(model->index(row,6)).toDateTime());
}

void UserManangeForm::initTable()
{
    this->model->setHorizontalHeaderItem(0, new QStandardItem(QString("管理员编号")));
    this->model->setHorizontalHeaderItem(1, new QStandardItem(QString("姓名")));
    this->model->setHorizontalHeaderItem(2, new QStandardItem(QString("密码")));
    this->model->setHorizontalHeaderItem(3, new QStandardItem(QString("性别")));
    this->model->setHorizontalHeaderItem(4, new QStandardItem(QString("年龄")));
    this->model->setHorizontalHeaderItem(5, new QStandardItem(QString("电话")));
    this->model->setHorizontalHeaderItem(6, new QStandardItem(QString("注册时间")));


    this->ui->tableView->setColumnWidth(0, 90);    //设置列的宽度
    this->ui->tableView->setColumnWidth(1, 120);
    this->ui->tableView->setColumnWidth(2, 120);
    this->ui->tableView->setColumnWidth(3, 90);
    this->ui->tableView->setColumnWidth(4, 90);
    this->ui->tableView->setColumnWidth(5, 150);
    this->ui->tableView->setColumnWidth(6, 200);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void UserManangeForm::on_pushButton_cancel_clicked()
{
    on_pushButton_refresh_clicked();
}

void UserManangeForm::on_pushButton_refresh_clicked()
{
    this->model->clear();
    initTable();
    int i = 0;
    std::vector<User> *Ulist = sql.getUsers();
    for(std::vector<User>::iterator it=(*Ulist).begin();it!=(*Ulist).end();it++){
        /*setItem设置条目栏中的一个格子的信息*/
        setTable(i,it);
        i++;
    }
    size = 0;
    for(int i =0;i<20;i++){
        list[i] = 0;
    }
    if(Ulist!=NULL)
        delete Ulist;
    Ulist = NULL;
}

void UserManangeForm::on_pushButton_sure_clicked()
{
    for(int i = 0;i<size&&i<20;i++){
        sql.deleteUser(list[i]);
        qDebug() << list[i];
    }
}

void UserManangeForm::on_pushButton_find_clicked()
{
    this->model->clear();
    initTable();
    int i = 0;
    std::vector<User> *Ulist = sql.getUsers(ui->lineEdit_find->text());
    for(std::vector<User>::iterator it=(*Ulist).begin();it!=(*Ulist).end();it++){
        /*setItem设置条目栏中的一个格子的信息*/
        setTable(i,it);
        i++;
    }
    size = 0;
    for(int i =0;i<20;i++){
        list[i] = 0;
    }

    if(Ulist!=NULL)
        delete Ulist;
    Ulist = NULL;
}
