/*****************************************************************************
@Project name: 02test
@Author: 代登辉
@Creation date : 2020-11-28
@Description: 商品管理界面cpp
@Completion date: 完成日期
*****************************************************************************/


#include "goodmanangeform.h"
#include "ui_goodmanangeform.h"

/*************************************************
Function: GoodManangeForm
Description: 商品管理界面构造方法
Input: // 输入参数说明，包括每个参数的作// 用、取值说明及参数间关系。
Others: 构造方法
*************************************************/
GoodManangeForm::GoodManangeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GoodManangeForm)
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
Function: ~GoodManangeForm
Description: 商品管理界面析构函数
Others: 析构函数
*************************************************/
GoodManangeForm::~GoodManangeForm()
{
    delete ui;
}

/*************************************************
Function: on_pushButton_close_clicked
Description: 隐藏本窗口，发送窗口关闭事件
Others: 自动生成槽函数
*************************************************/
void GoodManangeForm::on_pushButton_close_clicked()
{
    this->hide();
    emit GoodManangeclose();
}

// 设置供应商下拉框
void GoodManangeForm::suppliercomboBox()
{
    ui->comboBox->clear();
    ui->comboBox->addItem(QString(""));
    ui->comboBox->addItems(sql.getSuppName());
}

// 设置商品类别下拉框
void GoodManangeForm::categorycomboBox()
{
    ui->comboBox_2->clear();
    ui->comboBox_2->addItem(QString(""));
    ui->comboBox_2->addItem(QString("学习用品"));
    ui->comboBox_2->addItem(QString("酒水饮料"));
    ui->comboBox_2->addItem(QString("日用百货"));
    ui->comboBox_2->addItem(QString("水果"));
    ui->comboBox_2->addItem(QString("零食"));
    ui->comboBox_2->addItem(QString("洗漱用品"));

}

void GoodManangeForm::initTable()
{
    this->model->clear();
    this->model->setHorizontalHeaderItem(0, new QStandardItem(QString("商品编号")));
    this->model->setHorizontalHeaderItem(1, new QStandardItem(QString("名称")));
    this->model->setHorizontalHeaderItem(2, new QStandardItem(QString("总数量")));
    this->model->setHorizontalHeaderItem(3, new QStandardItem(QString("类别")));
    this->model->setHorizontalHeaderItem(4, new QStandardItem(QString("供货商名称")));
    this->model->setHorizontalHeaderItem(5, new QStandardItem(QString("供货商地址")));
    this->model->setHorizontalHeaderItem(6, new QStandardItem(QString("供货商电话")));


    this->ui->tableView->setColumnWidth(0, 70);    //设置列的宽度
    this->ui->tableView->setColumnWidth(1, 120);
    this->ui->tableView->setColumnWidth(2, 90);
    this->ui->tableView->setColumnWidth(3, 120);
    this->ui->tableView->setColumnWidth(4, 180);
    this->ui->tableView->setColumnWidth(5, 150);
    this->ui->tableView->setColumnWidth(6, 150);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void GoodManangeForm::setTable(int i, std::vector<Goods>::iterator s)
{
    this->model->setItem(i, 0, new QStandardItem(QString("%1").arg(s->getCid())));
    this->model->setItem(i, 1, new QStandardItem(QString(s->getCname())));
    this->model->setItem(i, 2, new QStandardItem(QString("%1").arg(s->getNum())));
    this->model->setItem(i, 3, new QStandardItem(QString(s->getCategory())));
    this->model->setItem(i, 4, new QStandardItem(QString(s->getSnmae())));
    this->model->setItem(i, 5, new QStandardItem(QString(s->getAddr())));
    this->model->setItem(i, 6, new QStandardItem(QString(s->getTel())));
}

void GoodManangeForm::on_pushButton_refresh_clicked()
{
    suppliercomboBox();
    categorycomboBox();
    on_pushButton_find_clicked();
}

void GoodManangeForm::on_pushButton_find_clicked()
{
    initTable();
    QString sname = ui->comboBox->currentText();
    QString catename = ui->comboBox_2->currentText();
    qDebug() << sname << "   " << catename;
    std::vector<Goods> *Slist = sql.getGoods(sname,catename);
    int i = 0;
    for(std::vector<Goods>::iterator it=(*Slist).begin();it!=(*Slist).end();it++){
        /*setItem设置条目栏中的一个格子的信息*/
        setTable(i,it);
        i++;
    }
    if(Slist!=NULL)
        delete Slist;
    Slist = NULL;
}
