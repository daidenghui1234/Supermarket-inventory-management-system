#include "commodityaddform.h"
#include "ui_commodityaddform.h"
#include <QMessageBox>

CommodityAddForm::CommodityAddForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CommodityAddForm)
{
    ui->setupUi(this);
    suppliercomboBox();
    // 去掉窗口最大最小化，和关闭
    this->setWindowFlags(Qt::Window|Qt::WindowTitleHint);

}

CommodityAddForm::~CommodityAddForm()
{
    delete ui;
}

void CommodityAddForm::on_pushButton_exit_clicked()
{
    this->hide();
    emit commodhide();
}

void CommodityAddForm::suppliercomboBox()
{
    ui->comboBox->clear();
    ui->comboBox->addItem(QString(""));
    ui->comboBox->addItems(sql.getSuppName());
}

void CommodityAddForm::on_pushButton_new_clicked()
{
    QString name = ui->lineEdit_cname->text();
    QString category = ui->comboBox_category->currentText();
    QString suppliername = ui->comboBox->currentText();
    if(suppliername.isEmpty()){
        this->ui->label_tip->setText("请先选择供应商");
        return;
    }
    int sid = sql.SupplierID(suppliername);

    int maxnum = ui->lineEdit_MAX->text().toInt();
    int minnum = ui->lineEdit_MIN->text().toInt();

    QString tmp = QString("INSERT INTO [dbo].[commodity]([cname],"
            " [sid], [category], [minnum], [maxmun]) "
            "VALUES ('%1', %2, '%3', %4, %5)")
            .arg(name).arg(sid).arg(category)
            .arg(minnum).arg(maxnum);
    qDebug() << tmp;
    sql.Myexec(tmp);
    suppliercomboBox();
    QMessageBox::warning(nullptr, "提示", "商品信息创建成功");
}
