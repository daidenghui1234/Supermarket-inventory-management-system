/*****************************************************************************
@Project name: 02test
@Author: 代登辉
@Creation date : 2020-11-28
@Description: 供应商管理界面cpp
@Completion date: 完成日期
*****************************************************************************/


#include "supplierform.h"
#include "ui_supplierform.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QString>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QItemSelectionModel>
#include "readonlydelegate.h"

/*************************************************
Function: SupplierForm
Description: 供货商界面构造函数
Others: 构造函数
*************************************************/
SupplierForm::SupplierForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SupplierForm)
{
    ui->setupUi(this);
    // 去掉窗口最大最小化，和关闭
    this->setWindowTitle(QString("超市库存管理系统"));
    // 去掉窗口最大最小化，和关闭
    this->setWindowFlags(Qt::Window|Qt::WindowTitleHint);

    this->model = new QStandardItemModel;   //创建一个标准的条目模型
    this->ui->tableView->setModel(model);


    on_pushButton_refresh_clicked();
}

/*************************************************
Function: ~SupplierForm
Description: 供货商界面析构函数
Others: 析构函数
*************************************************/
SupplierForm::~SupplierForm()
{
    delete ui;
}

/*************************************************
Function: on_pushButton_close_clicked
Description: 隐藏本窗口，发送窗口关闭事件
Others: 自动生成槽函数
*************************************************/
void SupplierForm::on_pushButton_close_clicked()
{
    this->hide();
    emit Supplierclose();
}

void SupplierForm::initTable()
{
    for(int i = 0; i < 20; i++){
        list[i] = 0;
    }
    size = 0;
    this->model->setHorizontalHeaderItem(0, new QStandardItem(QString("供应商编号")));
    this->model->setHorizontalHeaderItem(1, new QStandardItem(QString("姓名")));
    this->model->setHorizontalHeaderItem(2, new QStandardItem(QString("地址")));
    this->model->setHorizontalHeaderItem(3, new QStandardItem(QString("电话")));


    this->ui->tableView->setColumnWidth(0, 90);    //设置列的宽度
    this->ui->tableView->setColumnWidth(1, 200);
    this->ui->tableView->setColumnWidth(2, 200);
    this->ui->tableView->setColumnWidth(3, 200);
    //ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ReadOnlyDelegate* readOnlyDelegate = new ReadOnlyDelegate();
    ui->tableView->setItemDelegateForColumn(0 , readOnlyDelegate); //设置某列只读
}

/*************************************************
Function: setTable
Description: 设置表格内容,i表示行
Input: // 输入参数说明，包括每个参数的作// 用、取值说明及参数间关系。
Output: // 对输出参数的说明。
Return: // 函数返回值的说明
Others: 自定函数
*************************************************/
void SupplierForm::setTable(int i, std::vector<Supplier>::iterator s)
{
    this->model->setItem(i, 0, new QStandardItem(QString("%1").arg(s->getSid())));
    this->model->setItem(i, 1, new QStandardItem(QString(s->getSname())));
    this->model->setItem(i, 2, new QStandardItem(QString(s->getAddr())));
    this->model->setItem(i, 3, new QStandardItem(QString(s->getTel())));
}

/*************************************************
Function: getSupplier
Description: 根据所选中的行设置供应商内容
Others: 自定义函数
*************************************************/
void SupplierForm::getSupplier(int row, Supplier &supplier)
{
    supplier.setSid(model->data(model->index(row,0)).toInt());
    supplier.setExist(1);
    supplier.setSname(model->data(model->index(row,1)).toString());
    supplier.setAddr(model->data(model->index(row,2)).toString());
    supplier.setTel(model->data(model->index(row,3)).toString());
}

void SupplierForm::upadteSupplier(const Supplier &supplier)
{
    if((sql.isSupplier(supplier)) == true){
        QMessageBox::warning(nullptr, "警告", "修改失败");
    }else{
        sql.updateSupplier(supplier);
    }
}

/*************************************************
Function: addSupplier
Description: 添加供应商到数据库
Others: 自定义函数
*************************************************/
int SupplierForm::addSupplier(const Supplier &supplier)
{
    qDebug() << (sql.isSupplier(supplier));
    if((sql.isSupplier(supplier)) == true){
        sql.addSupplier(supplier);
        return 0;
    }else{
        if(supplier.getSid() != 0)
            QMessageBox::warning(nullptr, "警告", "供应商编号或名称冲突");
        return -1;
    }
}

// 槽函数刷新
void SupplierForm::on_pushButton_refresh_clicked()
{
    this->model->clear();
    initTable();
    std::vector<Supplier> *Slist = sql.getSupplier();
    int i = 0;
    for(std::vector<Supplier>::iterator it=(*Slist).begin();it!=(*Slist).end();it++){
        /*setItem设置条目栏中的一个格子的信息*/
        setTable(i,it);
        i++;
    }
    if(Slist!=NULL)
        delete Slist;
    Slist = NULL;
}

// 槽函数新建
void SupplierForm::on_pushButton_add_clicked()
{
    this->model->appendRow(new QStandardItem());
}

// 槽函点击确认
void SupplierForm::on_pushButton_sure_clicked()
{
    if(size<=0){
        int row = ui->tableView->currentIndex().row();
        Supplier supplier;
        getSupplier(row,supplier);
        supplier.printSupplier();
        addSupplier(supplier);
    }

    for(int i = 0;i<size&&i<20;i++){
        sql.deleteSupplier(list[i]);
    }
    for(int i = 0;i<20;i++){
        list[i] = 0;
    }
    size = 0;
}

// 点击修改
void SupplierForm::on_pushButton_alter_clicked()
{
    int row = ui->tableView->currentIndex().row();
    Supplier supplier;
    getSupplier(row,supplier);
    supplier.printSupplier();
    upadteSupplier(supplier);
}

// 点击删除
void SupplierForm::on_pushButton_delete_clicked()
{
    int row = ui->tableView->currentIndex().row();
    int id = this->model->data(this->model->index(row,0)).toInt();
    list[size] =id;
    qDebug() << list[size]  << "row = " << row;
    size++;
    model->removeRow(ui->tableView->currentIndex().row());
}

// 点击查询
void SupplierForm::on_pushButton_find_clicked()
{
    this->model->clear();
    initTable();
    std::vector<Supplier> *Slist = sql.getSupplier(ui->lineEdit_find->text());
    int i = 0;
    for(std::vector<Supplier>::iterator it=(*Slist).begin();it!=(*Slist).end();it++){
        /*setItem设置条目栏中的一个格子的信息*/
        setTable(i,it);
        i++;
    }
    if(Slist!=NULL)
        delete Slist;
    Slist = NULL;
}
