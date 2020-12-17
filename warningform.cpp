#include "warningform.h"
#include "ui_warningform.h"

#include <QString>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QStandardItemModel>

WarningForm::WarningForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WarningForm)
{
    ui->setupUi(this);
    f = OVER;
    this->model = new QStandardItemModel;   //创建一个标准的条目模型
    this->ui->tableView->setModel(model);
    // 去掉窗口最大最小化，和关闭
    this->setWindowFlags(Qt::Window|Qt::WindowTitleHint);
    initDataBase();
    inittable();
    flash();
    m_timer = new QTimer(this);
    connect(m_timer,&QTimer::timeout,this,&WarningForm::myTimeer);
    m_timer->start(1000*60); //every 1 minutes
}

WarningForm::~WarningForm()
{
    delete ui;
}

void WarningForm::initDataBase()
{
    // 初始化数据库
    sql = QSqlDatabase::addDatabase("QODBC");
    sql.setHostName("(local)");//服务器名
    sql.setDatabaseName("QSQLServer");//数据源名
    sql.setUserName("sa");//连接数据库用户名
    sql.setPassword("123456");//连接数据库密码

    if (!sql.open()) {
        qDebug("Sql connect failed.");
        qDebug() << sql.lastError().text();
        QMessageBox::warning(nullptr, "警告", "无法连接数据库");
    } else {
        qDebug("Sql connected.");
    }
}

std::vector<Goods> WarningForm::getgoods()
{
    std::vector<Goods> goodlist;
    QSqlQuery query;
    query.exec(QString("SELECT * from goodsin where shelftime < GETDATE()"));
    while (query.next()) {
        Goods good;
        initGoods(good,query);//设置商品属性
        goodlist.push_back(good);
    }
    return goodlist;
}

std::vector<Goods> WarningForm::getExpiringgoods()
{
    std::vector<Goods> goodlist;
    QSqlQuery query;
    query.exec(QString("SELECT * from goodsin where shelftime < GETDATE()+30 and shelftime > GETDATE()"));
    while (query.next()) {
        Goods good;
        initGoods(good,query);//设置商品属性
        goodlist.push_back(good);
    }
    return goodlist;
}

std::vector<Goods> WarningForm::getlackgoods()
{
    std::vector<Goods> goodlist;
    QSqlQuery query;
    query.exec(QString("SELECT * from goods WHERE goods.[SUM] <  minnum"));
    while (query.next()) {
        Goods good;
        initGoodgoods(good,query);  //设置商品属性
        goodlist.push_back(good);
    }
    return goodlist;
}

std::vector<Goods> WarningForm::getnimietygoods()
{
    std::vector<Goods> goodlist;
    QSqlQuery query;
    query.exec(QString("SELECT * from goods WHERE goods.[SUM] > maxmun"));
    while (query.next()) {
        Goods good;
        initGoodgoods(good,query);//设置商品属性
        goodlist.push_back(good);
    }
    return goodlist;
}

void WarningForm::outgood(int Iid, int num, int uid)
{
    QSqlQuery query;
    QString tmp = QString("select cid,price from [in] where iid = %1").arg(Iid);
    query.exec(tmp);
    query.next();
    int cid = query.value(0).toInt();
    float price = query.value(1).toFloat();
    QString tmpout = QString("INSERT INTO [dbo].[out]( [cid], [price], [time], [num], [uid], [weight]) VALUES "
                           "(%1, %2,GETDATE(), %3, %4, 0)")
            .arg(cid).arg(price).arg(num).arg(uid);
    query.exec(tmpout);
}

void WarningForm::deletegoods()
{
    // 添加出库信息
    QSqlQuery query;
    query.exec(QString("SELECT * from goodsin where shelftime < GETDATE()"));
    while (query.next()) {
        Goods good;
        initGoods(good,query);//设置商品属性
        outgood(good.getCid(),good.getNum(),good.getUid());
    }
    // 删除入库信息
    query.exec(QString("delete from [in] where shelftime < GETDATE()"));

}

void WarningForm::deleteExpiringgoods()
{
    QSqlQuery query;
    query.exec(QString("delete from [in] where shelftime < GETDATE()+30"));
}

void WarningForm::inittable()
{
    this->model->clear();
    this->model->setHorizontalHeaderItem(0, new QStandardItem(QString("入库编号")));
    this->model->setHorizontalHeaderItem(1, new QStandardItem(QString("商品名称")));
    this->model->setHorizontalHeaderItem(2, new QStandardItem(QString("供货商名称")));
    this->model->setHorizontalHeaderItem(3, new QStandardItem(QString("类别")));
    this->model->setHorizontalHeaderItem(4, new QStandardItem(QString("价格")));
    this->model->setHorizontalHeaderItem(5, new QStandardItem(QString("入库时间")));
    this->model->setHorizontalHeaderItem(6, new QStandardItem(QString("过期时间")));
    this->model->setHorizontalHeaderItem(7, new QStandardItem(QString("入库数量")));
    this->model->setHorizontalHeaderItem(8, new QStandardItem(QString("操作员编号")));
    this->model->setHorizontalHeaderItem(9, new QStandardItem(QString("操作员姓名")));
    this->model->setHorizontalHeaderItem(10, new QStandardItem(QString("重量")));
    this->model->setHorizontalHeaderItem(11, new QStandardItem(QString("最大库存量")));
    this->model->setHorizontalHeaderItem(12, new QStandardItem(QString("最小库存量")));

    this->ui->tableView->setColumnWidth(0, 80);
    this->ui->tableView->setColumnWidth(1, 80);
    this->ui->tableView->setColumnWidth(2, 140);
    this->ui->tableView->setColumnWidth(3, 100);
    this->ui->tableView->setColumnWidth(4, 80);
    this->ui->tableView->setColumnWidth(5, 100);    //设置列的宽度
    this->ui->tableView->setColumnWidth(6, 100);
    this->ui->tableView->setColumnWidth(7, 90);
    this->ui->tableView->setColumnWidth(8, 50);
    this->ui->tableView->setColumnWidth(9, 100);
    this->ui->tableView->setColumnWidth(10, 90);
    this->ui->tableView->setColumnWidth(11, 60);
    this->ui->tableView->setColumnWidth(12, 60);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void WarningForm::inittableGoods()
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

void WarningForm::settable(int i,std::vector<Goods>::iterator s)
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
    this->model->setItem(i, 10, new QStandardItem(QString("%1").arg(s->getWeight())));
    this->model->setItem(i, 11, new QStandardItem(QString("%1").arg(s->getMinnum())));
    this->model->setItem(i, 12, new QStandardItem(QString("%1").arg(s->getMaxnum())));
}

void WarningForm::settableGoods(int i, std::vector<Goods>::iterator s)
{
    s->printGoods();
    this->model->setItem(i, 0, new QStandardItem(QString("%1").arg(s->getCid())));
    this->model->setItem(i, 1, new QStandardItem(QString(s->getCname())));
    this->model->setItem(i, 2, new QStandardItem(QString("%1").arg(s->getNum())));
    this->model->setItem(i, 3, new QStandardItem(QString(s->getCategory())));
    this->model->setItem(i, 4, new QStandardItem(QString(s->getSnmae())));
    this->model->setItem(i, 5, new QStandardItem(QString(s->getAddr())));
    this->model->setItem(i, 6, new QStandardItem(QString(s->getTel())));
}
void WarningForm::Overdue()
{
    ui->label->clear();
    ui->label->setText(QString("过期商品警告"));
    std::vector<Goods> goodlist = getgoods();
    int i = 0;
    for(std::vector<Goods>::iterator it=goodlist.begin();it!=goodlist.end();it++){
        /*setItem设置条目栏中的一个格子的信息*/
        settable(i,it);
        i++;
    }
}

void WarningForm::Expiring()
{
    ui->label->clear();
    ui->label->setText(QString("即将过期商品警告"));
    std::vector<Goods> goodlist = getExpiringgoods();
    int i = 0;
    for(std::vector<Goods>::iterator it=goodlist.begin();it!=goodlist.end();it++){
        /*setItem设置条目栏中的一个格子的信息*/
        settable(i,it);
        i++;
    }
}

void WarningForm::lack()
{
    ui->label->clear();
    ui->label->setText(QString("商品库存不足警告"));
    std::vector<Goods> goodlist = getlackgoods();
    int i = 0;
    for(std::vector<Goods>::iterator it=goodlist.begin();it!=goodlist.end();it++){
        /*setItem设置条目栏中的一个格子的信息*/
        settableGoods(i,it);
        i++;
    }
}

void WarningForm::nimiety()
{
    ui->label->clear();
    ui->label->setText(QString("商品库存过量警告"));
    std::vector<Goods> goodlist = getnimietygoods();
    int i = 0;
    for(std::vector<Goods>::iterator it=goodlist.begin();it!=goodlist.end();it++){
        /*setItem设置条目栏中的一个格子的信息*/
        settableGoods(i,it);
        i++;
    }
}

bool WarningForm::ifOverdue()
{
    QSqlQuery query;
    query.exec(QString("SELECT * from goodsin where shelftime < GETDATE()"));
    query.next();
    return !query.value(1).toString().isEmpty();
}

bool WarningForm::ifExpiring()
{
    QSqlQuery query;
    query.exec(QString("SELECT * from goodsin where shelftime < GETDATE()+30 and shelftime > GETDATE()"));
    query.next();
    return !query.value(1).toString().isEmpty();
}

bool WarningForm::iflack()
{
    QSqlQuery query;
    query.exec(QString("SELECT * from goodsin where num < minnum"));
    query.next();
    return !query.value(1).toString().isEmpty();
}

bool WarningForm::ifnimiety()
{
    QSqlQuery query;
    query.exec(QString("SELECT * from goodsin where num > maxmun"));
    query.next();
    return !query.value(1).toString().isEmpty();
}


void WarningForm::myTimeer()
{
    flash();
    ui->pushButton_refresh->setText("刷新");
    static int i = 0;
    switch (i%4) {
    case 0:
    {
        ui->pushButton_refresh->setText("一键处理");
        qDebug() << ifOverdue() << "  " <<1;
        if(ifOverdue()){
            this->f = OVER;
            inittable();
            emit myWarning();
        }
        break;
    }
    case 1:
    {
        if(ifExpiring()){
            this->f = EXPI;
            inittable();
            emit myWarning();
        }
        break;
    }
    case 2:
    {
        if(iflack()){
            this->f = LACK;
            inittableGoods();
            emit myWarning();
        }
        break;
    }
    case 3:
    {
        if(ifnimiety()){
            this->f = NIMI;
            inittableGoods();
            emit myWarning();
        }
        break;
    }
    default:
        break;
    }

    qDebug() << i;
    i++;
    switch (this->f) {
    case Flag::OVER:
        Overdue();
        break;
    case Flag::EXPI:
        Expiring();
        break;
    case Flag::LACK:
        lack();
        break;
    case Flag::NIMI:
        nimiety();
        break;
    default:
        break;
    }
}

void WarningForm::flash()
{
    switch (this->f) {
    case Flag::OVER:
        Overdue();
        break;
    case Flag::EXPI:
        Expiring();
        break;
    case Flag::LACK:
        lack();
        break;
    case Flag::NIMI:
        nimiety();
        break;
    default:
        break;
    }
}

void WarningForm::on_pushButton_refresh_clicked()
{
    switch (this->f) {
    case Flag::OVER:
        deletegoods();
        Overdue();
        QMessageBox::warning(nullptr, "提示", "处理完成");
        this->hide();
        break;
    case Flag::EXPI:
        Expiring();
        break;
    case Flag::LACK:
        lack();
        break;
    case Flag::NIMI:
        nimiety();
        break;
    default:
        break;
    }
}

void WarningForm::initGoods(Goods &good,QSqlQuery &query)
{
    good.setCid(query.value(0).toInt());
    good.setCname(query.value(1).toString());
    good.setSnmae(query.value(2).toString());
    good.setCategory(query.value(3).toString());
    good.setPrice(query.value(4).toFloat());
    good.setTime(query.value(5).toDateTime());
    good.setShelftime(query.value(6).toDateTime());
    good.setNum(query.value(7).toInt());
    good.setUid(query.value(8).toInt());
    good.setUname(query.value(9).toString());
    good.setWeight(query.value(10).toFloat());
    good.setMaxnum(query.value(11).toInt());
    good.setMinnum(query.value(12).toInt());
}

void WarningForm::initGoodgoods(Goods &good, QSqlQuery &query)
{
    good.setCid(query.value(0).toInt());
    good.setCname(query.value(1).toString());
    good.setNum(query.value(2).toInt());
    good.setCategory(query.value(3).toString());
    good.setSnmae(query.value(4).toString());
    good.setAddr(query.value(5).toString());
    good.setTel(query.value(6).toString());
    good.setMinnum(query.value(7).toInt());
    good.setMaxnum(query.value(8).toInt());
}

void WarningForm::on_pushButton_close_clicked()
{
    this->hide();
}
