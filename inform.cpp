/*****************************************************************************
@Project name: 02test
@Author: 代登辉
@Creation date : 2020-11-28
@Description: 商品入库cpp
@Completion date: 完成日期
*****************************************************************************/


#include "inform.h"
#include "ui_inform.h"
#include <QMessageBox>
#include <QDateTime>
/*************************************************
Function: InForm
Description: 商品入库界面构造函数
Others: 构造函数
*************************************************/
InForm::InForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InForm)
{
    ui->setupUi(this);
    this->setWindowTitle(QString("超市库存管理系统"));
    // 去掉窗口最大最小化，和关闭
    this->setWindowFlags(Qt::Window|Qt::WindowTitleHint);
    on_pushButton_clear_clicked();
    commd = new CommodityAddForm();

    connect(commd,&CommodityAddForm::commodhide,this,&InForm::show);
    ui->dateTimeEdit->setMinimumDateTime(QDateTime::currentDateTime().addDays(1));
}

/*************************************************
Function: InForm
Description: 商品入库界面析构函数
Others: 析构函数
*************************************************/
InForm::~InForm()
{
    delete ui;
}

/*************************************************
Function: on_pushButton_close_clicked
Description: 隐藏本窗口，发送窗口关闭事件
Others: 自动生成槽函数
*************************************************/
void InForm::on_pushButton_close_clicked()
{
    this->hide();
    emit InFromclose();
}

void InForm::suppliercomboBox()
{
    ui->comboBox->clear();
    ui->comboBox->addItem(QString(""));
    ui->comboBox->addItems(sql.getSuppName());
}

void InForm::categorycomboBox()
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

int InForm::getUid() const
{
    return uid;
}

void InForm::setUid(int value)
{
    uid = value;
}



void InForm::on_pushButton_clear_clicked()
{
    suppliercomboBox();
    categorycomboBox();
    this->ui->lineEdit->clear();
    ui->spinBox_num->clear();
    ui->doubleSpinBox_price->clear();
    ui->dateTimeEdit->clear();
    ui->doubleSpinBox__kg->clear();
    ui->label_tip->clear();
    ui->label_tip->setText(QString("请输入入库的商品信息"));
}

void InForm::on_pushButton_in_clicked()
{
    QString sname = ui->comboBox->currentText();
    QString catename = ui->comboBox_2->currentText();
    QString cname = ui->lineEdit->text();

    int id = sql.getGoodCid(sname,catename,cname);
    if(id == 0){
        // 创建商品
        ui->label_tip->clear();
        ui->label_tip->setStyleSheet(QString("color:red;"));
        ui->label_tip->setText(QString("请先创建新商品"));
        return ;
    }
    int num = ui->spinBox_num->text().toInt();
    float price = ui->doubleSpinBox_price->text().toFloat();
    float weight = ui->doubleSpinBox__kg->text().toFloat();
    if(num <= 0 || price <= 0 || weight <= 0){
        ui->label_tip->clear();
        ui->label_tip->setStyleSheet(QString("color:red;"));
        ui->label_tip->setText(QString("商品数量、价格、质量不能为零"));
        return ;
    }
    QString selftime = ui->dateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss");
    QString tmpSql = QString("INSERT INTO [dbo].[in] ([cid], [price], [time], "
                             "[shelftime], [num], [uid], [weight] )"
                             "VALUES"
                             "( %1, %2, GETDATE(), '%3', %4, %5, %6 )")
            .arg(id).arg(price).arg(selftime).arg(num).arg(uid).arg(weight);
    QString tmpSql1 = QString("INSERT INTO [dbo].[in_copy] ([cid], [price], [time], "
                             "[shelftime], [num], [uid], [weight] )"
                             "VALUES"
                             "( %1, %2, GETDATE(), '%3', %4, %5, %6 )")
            .arg(id).arg(price).arg(selftime).arg(num).arg(uid).arg(weight);
    qDebug() << tmpSql;

    sql.Myexec(tmpSql);
    sql.Myexec(tmpSql1);
    QMessageBox::warning(nullptr, "提示", "入库成功");
    ui->label_tip->clear();
}

void InForm::on_pushButton_new_clicked()
{
    this->hide();
    commd->show();
}
