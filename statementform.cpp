/*****************************************************************************
@Project name: 02test
@Author: 代登辉
@Creation date : 2020-11-28
@Description: 报表管理界面cpp
@Completion date: 完成日期
*****************************************************************************/


#include "statementform.h"
#include "ui_statementform.h"
#include <QDebug>
#include <QDateTime>

/*************************************************
Function: StatemenForm
Description: 报表管理界面构造函数
Others: 构造函数
*************************************************/
StatementForm::StatementForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StatementForm)
{
    ui->setupUi(this);
    this->setWindowTitle(QString("超市库存管理系统"));
    // 去掉窗口最大最小化，和关闭
    this->setWindowFlags(Qt::Window|Qt::WindowTitleHint);

    this->model = new QStandardItemModel;   //创建一个标准的条目模型
    this->ui->tableView->setModel(model);

    on_pushButton_refresh_clicked();
}


/*************************************************
Function: ~StatemenForm
Description: 报表管理界面析构函数
Others: 析构函数
*************************************************/
StatementForm::~StatementForm()
{
    delete ui;
}


/*************************************************
Function: on_pushButton_close_clicked
Description: 隐藏本窗口，发送窗口关闭事件
Others: 自动生成槽函数
*************************************************/
void StatementForm::on_pushButton_close_clicked()
{
    this->hide();
    emit Statementclose();
}

void StatementForm::on_pushButton_refresh_clicked()
{
    QString IO = ui->comboBox->currentText();
    QString time = ui->comboBox_2->currentText();
    // 获取当前时间
    QDateTime data = QDateTime::currentDateTime();
    if(QString::compare(time,QString("一天以内")) == 0){
        //data = data.addDays(-1);
        time = data.toString("yyyy-MM-dd");
    }else if(QString::compare(time,QString("一个月内"))== 0){
        data = data.addMonths(-1);
        time = data.toString("yyyy-MM-dd");
    }else if(QString::compare(time,QString("一个季度内"))== 0){
        data = data.addMonths(-3);
        time = data.toString("yyyy-MM-dd");
    }else if(QString::compare(time,QString("一年以内"))== 0){
        data = data.addYears(-1);
        time = data.toString("yyyy-MM-dd");
    }else{
        time = QString("");
    }

    std::vector<Goods> *Slist;
    if(QString::compare(IO,QString("入库")) == 0){
        initable(1);
        Slist  = sql.getinGoods(time);
        int i = 0;
        for(std::vector<Goods>::iterator it=(*Slist).begin();it!=(*Slist).end();it++){
            /*setItem设置条目栏中的一个格子的信息*/
            setINTable(i,it);
            i++;
        }
        if(Slist!=NULL)
            delete Slist;
        Slist = NULL;
    }else{
        initable(2);
        Slist  = sql.getoutGoods(time);
        int i = 0;
        for(std::vector<Goods>::iterator it=(*Slist).begin();it!=(*Slist).end();it++){
            /*setItem设置条目栏中的一个格子的信息*/
            setOUTable(i,it);
            i++;
        }
        if(Slist!=NULL)
            delete Slist;
        Slist = NULL;
    }

    qDebug() << uid << "id   id";
    qDebug() << data.toString("yyyy-MM-dd") << "  " << IO ;
}

void StatementForm::initable(int io)
{
    model->clear();
    this->model->setHorizontalHeaderItem(0, new QStandardItem(QString("入库编号")));
    this->model->setHorizontalHeaderItem(1, new QStandardItem(QString("商品名称")));
    this->model->setHorizontalHeaderItem(2, new QStandardItem(QString("供货商名称")));
    this->model->setHorizontalHeaderItem(3, new QStandardItem(QString("类别")));
    this->model->setHorizontalHeaderItem(4, new QStandardItem(QString("价格")));
    this->ui->tableView->setColumnWidth(0, 80);    //设置列的宽度
    this->ui->tableView->setColumnWidth(1, 80);
    this->ui->tableView->setColumnWidth(2, 140);
    this->ui->tableView->setColumnWidth(3, 100);
    this->ui->tableView->setColumnWidth(4, 80);

    if(io == 1){
        this->model->setHorizontalHeaderItem(5, new QStandardItem(QString("入库时间")));
        this->model->setHorizontalHeaderItem(6, new QStandardItem(QString("过期时间")));
        this->model->setHorizontalHeaderItem(7, new QStandardItem(QString("入库数量")));
        this->model->setHorizontalHeaderItem(8, new QStandardItem(QString("操作员编号")));
        this->model->setHorizontalHeaderItem(9, new QStandardItem(QString("操作员姓名")));
        //this->model->setHorizontalHeaderItem(10, new QStandardItem(QString("重量")));
        this->model->setHorizontalHeaderItem(10, new QStandardItem(QString("最大库存量")));
        this->model->setHorizontalHeaderItem(11, new QStandardItem(QString("最小库存量")));

        this->ui->tableView->setColumnWidth(5, 100);    //设置列的宽度
        this->ui->tableView->setColumnWidth(6, 100);
        this->ui->tableView->setColumnWidth(7, 90);
        this->ui->tableView->setColumnWidth(8, 50);
        this->ui->tableView->setColumnWidth(9, 100);
        this->ui->tableView->setColumnWidth(10, 90);
        this->ui->tableView->setColumnWidth(11, 60);
        //this->ui->tableView->setColumnWidth(12, 60);

    }else{
        this->model->setHorizontalHeaderItem(5, new QStandardItem(QString("出库时间")));
        this->model->setHorizontalHeaderItem(6, new QStandardItem(QString("出库数量")));
        this->model->setHorizontalHeaderItem(7, new QStandardItem(QString("操作员编号")));
        this->model->setHorizontalHeaderItem(8, new QStandardItem(QString("操作员姓名")));
        //this->model->setHorizontalHeaderItem(9, new QStandardItem(QString("重量")));
        this->model->setHorizontalHeaderItem(9, new QStandardItem(QString("最大库存量")));
        this->model->setHorizontalHeaderItem(10, new QStandardItem(QString("最小库存量")));
        this->ui->tableView->setColumnWidth(5, 100);    //设置列的宽度
        this->ui->tableView->setColumnWidth(6, 100);
        this->ui->tableView->setColumnWidth(7, 100);
        this->ui->tableView->setColumnWidth(8, 100);
        this->ui->tableView->setColumnWidth(9, 90);
        this->ui->tableView->setColumnWidth(10, 80);
        //this->ui->tableView->setColumnWidth(11, 80);
    }

    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void StatementForm::setINTable(int i, std::vector<Goods>::iterator s)
{
    this->model->setItem(i, 0, new QStandardItem(QString("%1").arg(s->getCid())));
    this->model->setItem(i, 1, new QStandardItem(s->getCname()));
    this->model->setItem(i, 2, new QStandardItem(s->getSnmae()));
    this->model->setItem(i, 3, new QStandardItem(s->getCategory()));
    this->model->setItem(i, 4, new QStandardItem(QString("%1").arg(s->getPrice())));
    this->model->setItem(i, 5, new QStandardItem(s->getTime().toString("yyyy-MM-dd")));
    this->model->setItem(i, 6, new QStandardItem(s->getShelftime().toString("yyyy-MM-dd")));
    this->model->setItem(i, 7, new QStandardItem(QString("%1").arg(s->getNum())));
    this->model->setItem(i, 8, new QStandardItem(QString("%1").arg(s->getUid())));
    this->model->setItem(i, 9, new QStandardItem(s->getUname()));
    //this->model->setItem(i, 10, new QStandardItem(QString("%1").arg(s->getWeight())));
    this->model->setItem(i, 10, new QStandardItem(QString("%1").arg(s->getMinnum())));
    this->model->setItem(i, 11, new QStandardItem(QString("%1").arg(s->getMaxnum())));

}

void StatementForm::setOUTable(int i, std::vector<Goods>::iterator s)
{
    this->model->setItem(i, 0, new QStandardItem(QString("%1").arg(s->getCid())));
    this->model->setItem(i, 1, new QStandardItem(s->getCname()));
    this->model->setItem(i, 2, new QStandardItem(s->getSnmae()));
    this->model->setItem(i, 3, new QStandardItem(s->getCategory()));
    this->model->setItem(i, 4, new QStandardItem(QString("%1").arg(s->getPrice())));
    this->model->setItem(i, 5, new QStandardItem(s->getTime().toString("yyyy-MM-dd")));
    this->model->setItem(i, 6, new QStandardItem(QString("%1").arg(s->getNum())));
    this->model->setItem(i, 7, new QStandardItem(QString("%1").arg(s->getUid())));
    this->model->setItem(i, 8, new QStandardItem(s->getUname()));
    //this->model->setItem(i, 9, new QStandardItem(QString("%1").arg(s->getWeight())));
    this->model->setItem(i, 9, new QStandardItem(QString("%1").arg(s->getMinnum())));
    this->model->setItem(i, 10, new QStandardItem(QString("%1").arg(s->getMaxnum())));
}

int StatementForm::getUid() const
{
    return uid;
}

void StatementForm::setUid(int value)
{
    uid = value;
}
