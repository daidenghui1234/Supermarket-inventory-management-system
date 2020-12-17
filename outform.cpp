/*****************************************************************************
@Project name: 02test
@Author: 代登辉
@Creation date : 2020-11-28
@Description: 商品出库界面cpp
@Completion date: 完成日期
*****************************************************************************/


#include "outform.h"
#include "ui_outform.h"
#include "readonlydelegate.h"
#include <QMessageBox>

/*************************************************
Function: OutForm
Description: 商品出库界面构造函数
Others: 构造函数
*************************************************/
OutForm::OutForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OutForm)
{
    ui->setupUi(this);
    this->setWindowTitle(QString("超市库存管理系统"));
    // 去掉窗口最大最小化，和关闭
    this->setWindowFlags(Qt::Window|Qt::WindowTitleHint);

    this->model = new QStandardItemModel;   //创建一个标准的条目模型
    this->ui->tableView->setModel(model);

    suppliercomboBox();
    categorycomboBox();
    on_pushButton_refresh_clicked();
}


/*************************************************
Function: ~OutForm
Description: 商品出库界面析构函数
Others: 析构函数
*************************************************/
OutForm::~OutForm()
{
    delete ui;
}

void OutForm::suppliercomboBox()
{
    ui->comboBox->clear();
    ui->comboBox->addItem(QString(""));
    ui->comboBox->addItems(sql.getSuppName());
}

void OutForm::categorycomboBox()
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

void OutForm::initTable()
{
    this->model->clear();
    this->model->setHorizontalHeaderItem(0, new QStandardItem(QString("商品编号")));
    this->model->setHorizontalHeaderItem(1, new QStandardItem(QString("名称")));
    this->model->setHorizontalHeaderItem(2, new QStandardItem(QString("总数量")));
    this->model->setHorizontalHeaderItem(3, new QStandardItem(QString("类别")));
    this->model->setHorizontalHeaderItem(4, new QStandardItem(QString("价格")));
    this->model->setHorizontalHeaderItem(5, new QStandardItem(QString("供货商名称")));
    this->model->setHorizontalHeaderItem(6, new QStandardItem(QString("入库时间")));
    this->model->setHorizontalHeaderItem(7, new QStandardItem(QString("到期时间")));
    this->model->setHorizontalHeaderItem(8, new QStandardItem(QString("出库量")));

    this->ui->tableView->setColumnWidth(0, 70);    //设置列的宽度
    this->ui->tableView->setColumnWidth(1, 90);
    this->ui->tableView->setColumnWidth(2, 90);
    this->ui->tableView->setColumnWidth(3, 70);
    this->ui->tableView->setColumnWidth(4, 90);
    this->ui->tableView->setColumnWidth(5, 130);
    this->ui->tableView->setColumnWidth(6, 200);
    this->ui->tableView->setColumnWidth(7, 200);
    this->ui->tableView->setColumnWidth(8, 80);
    //ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ReadOnlyDelegate* readOnlyDelegate = new ReadOnlyDelegate();
    for(int i =0;i<8;i++)
        ui->tableView->setItemDelegateForColumn(i, readOnlyDelegate); //设置某列只读
    //ui->tableView->setItemDelegateForRow(0, readOnlyDelegate);    //设置某行只读;
}

void OutForm::setTable(int i, std::vector<Goods>::iterator s)
{
    this->model->setItem(i, 0, new QStandardItem(QString("%1").arg(s->getCid())));
    this->model->setItem(i, 1, new QStandardItem(QString(s->getCname())));
    this->model->setItem(i, 2, new QStandardItem(QString("%1").arg(s->getNum())));
    this->model->setItem(i, 3, new QStandardItem(QString(s->getCategory())));
    this->model->setItem(i, 4, new QStandardItem(QString("%1元").arg(s->getPrice())));
    this->model->setItem(i, 5, new QStandardItem(QString(s->getSnmae())));
    this->model->setItem(i, 6, new QStandardItem(QString(s->getTime().toString("yyyy年MM月dd日 hh:mm:ss"))));
    this->model->setItem(i, 7, new QStandardItem(QString(s->getShelftime().toString("yyyy年MM月dd日 hh:mm:ss"))));
}

int OutForm::getUid() const
{
    return uid;
}

void OutForm::setUid(int value)
{
    uid = value;
}


/*************************************************
Function: on_pushButton_close_clicked
Description: 隐藏本窗口，发送窗口关闭事件
Others: 自动生成槽函数
*************************************************/
void OutForm::on_pushButton_close_clicked()
{
    this->close();
    emit OutFromclose();
}

void OutForm::on_pushButton_refresh_clicked()
{
    initTable();
    QString sname = ui->comboBox->currentText();
    QString catename = ui->comboBox_2->currentText();
    QString cname = ui->lineEdit->text();
    qDebug() << sname << "   " << catename;
    std::vector<Goods> *Slist = sql.getGoodsOut2(cname,sname,catename);
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

void OutForm::on_pushButton_out_clicked()
{
    int row = ui->tableView->currentIndex().row();
    int id = this->model->data(this->model->index(row,0)).toInt();
    int num = this->model->data(this->model->index(row,2)).toInt();
    int outnum = this->model->data(this->model->index(row,8)).toInt();

    if(num < outnum){
        QMessageBox::warning(nullptr, "警告", "出库数量超过库存");
        this->model->setItem(row, 8,new QStandardItem(QString("")));
        return;
    }
    if(outnum <= 0){
        QMessageBox::warning(nullptr, "警告", "请输入出库数量");

        return;
    }
    int out = num - outnum;
    QString tmp = QString("UPDATE [dbo].[in] "
                          "SET [num] = %1 WHERE [iid] = %2")
            .arg(out).arg(id);

    sql.outgood(id,outnum,uid);
    qDebug() << tmp;
    sql.Myexec(tmp);
    QMessageBox::warning(nullptr, "提示", "出库成功");
    on_pushButton_refresh_clicked();
}
