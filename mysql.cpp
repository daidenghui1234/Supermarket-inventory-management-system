/*****************************************************************************
@Project name: 02test
@Author: 代登辉
@Creation date : 2020-11-17
@Description: 数据库操作
@Completion date: 完成日期
*****************************************************************************/


#include "mysql.h"
#include <QString>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include "user.h"


/*************************************************
Function: Mysql
Description: Mysql
*************************************************/
Mysql::Mysql()
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

/*************************************************
Function: verifyLogin
Description: 顺序比对用户名和密码是否存在
Table Accessed: 表user
Table Updated: 无
Input: 用户名和密码
Output: 用户名和密码存在返回ture否则返回flase
登录
*************************************************/
bool Mysql::verifyLogin(const QString name,const QString password)
{
    QSqlQuery query;
    query.exec("select * from [user] where exist = 1");
    bool chekname=false;
    bool chekpassword=false;
    // 打印输出用户名和密码
    while (query.next()) {
        qDebug() << query.value(0).toInt()
                 << query.value(1).toInt()
                 << query.value(2).toString();
        if(query.value(1).toInt() ==1 ){
            chekname = (QString::compare(name,query.value(2).toString(),
                                         Qt::CaseSensitive) == 0);
            chekpassword = (QString::compare(password,query.value(3).toString(),
                                             Qt::CaseSensitive) == 0);
        }else{
            continue;
        }

        if(chekname&&chekpassword){
            return true;
        }
    }
    return false;
}

/*************************************************
Function: applyAccount
Description: 将用户写入数据库
Table Accessed: user
Table Updated: user
Input: 用户user
Output: 插入成功返回true 否则返回false
用户注册
*************************************************/
bool Mysql::applyAccount(User user)
{
    QSqlQuery query;
    query.exec(QString("select uid from [user] where uid = %1 or uname = '%2'")
               .arg(user.getId()).arg(user.getUname()));
    while (query.next()){
        query.exec(QString("UPDATE [dbo].[user] SET [exist] = 1 WHERE [uid] = &1")
                   .arg(query.value(0).toInt()));
    }
    if(query.size() <= 0){
        QString sqlcommand = QString("INSERT INTO [user] "
                                     " VALUES "
                                     "(%1,GETDATE());").arg(user.getUser());
        qDebug() << sqlcommand;
        query.exec(sqlcommand);
    }

    return true;
}

/*************************************************
Function: isUname
Description: 判断用户名是否存在
Table Accessed: user
Table Updated: user
Input: 用户名
Output: 用户id 【uid】

*************************************************/
int Mysql::isUname(const QString name)
{
    QSqlQuery query;
    query.exec("select * from [user]");
    bool chekname=false;
    // 打印输出用户名和密码
    while (query.next()) {
        if(query.value(1).toInt() ==1 ){
            chekname = (QString::compare(name,query.value(2).toString(),
                                         Qt::CaseSensitive) == 0);
            if(chekname){
                return query.value(0).toInt();
            }
        }else{
            continue;
        }

    }
    return -1;
}

bool Mysql::isUid(int id)
{
    QSqlQuery query;
    query.exec(QString("select * from [user] where uid = %1").arg(id));
    while (query.next()) {
        if(query.value(0) == id){
            return true;
        }
    }
    return false;
}

/*************************************************
Function: setUser
Description: 根据用户id设置用户内容
Table Accessed: user
Input: uid用户id, user用户
Output: 设置成功返回true否则返回false
*************************************************/
bool Mysql::setUser(int uid,User &user)
{
    QSqlQuery query;
    query.exec(QString("select * from [user] where uid = %1").arg(uid));
    if(query.first()){
        user.setId(query.value(0).toInt());
        user.setExit(query.value(1).toInt());
        user.setUname(query.value(2).toString());
        user.setUpassword(query.value(3).toString());
        user.setSex(query.value(4).toString());
        user.setAge(query.value(5).toInt());
        user.setTel(query.value(6).toString());
        user.setTime(query.value(7).toDateTime());
    }
    return true;
}


/*************************************************
Function: getUsers
Description: 查询数据库返回可显示的管理者对象列表
Table Accessed: user
Output: std::vector<User>
Others: 自定义函数
*************************************************/
std::vector<User>* Mysql::getUsers()
{
    std::vector<User> *List = new std::vector<User>;

    QSqlQuery query;
    query.exec("select * from [user] where exist = 1");
    while (query.next()) {
        User user;
        user.setId(query.value(0).toInt());
        user.setExit(query.value(1).toInt());
        user.setUname(query.value(2).toString());
        user.setUpassword(query.value(3).toString());
        user.setSex(query.value(4).toString());
        user.setAge(query.value(5).toInt());
        user.setTel(query.value(6).toString());
        user.setTime(query.value(7).toDateTime());
        List->push_back(user);
    }

    return List;
}

std::vector<User> *Mysql::getUsers(QString name)
{
    std::vector<User> *List = new std::vector<User>;
    QSqlQuery query;
    query.exec(QString("select * from [user] where exist = 1 and uname like '%%1%'").arg(name));
    while (query.next()) {
        User user;
        user.setId(query.value(0).toInt());
        user.setExit(query.value(1).toInt());
        user.setUname(query.value(2).toString());
        user.setUpassword(query.value(3).toString());
        user.setSex(query.value(4).toString());
        user.setAge(query.value(5).toInt());
        user.setTel(query.value(6).toString());
        user.setTime(query.value(7).toDateTime());
        List->push_back(user);
    }
    return List;
}

bool Mysql::deleteUser(int id)
{
    QSqlQuery query;
    return query.exec(QString("UPDATE [dbo].[user] SET [exist] = 0 WHERE [uid] = %1").arg(id));
}

std::vector<Supplier> *Mysql::getSupplier()
{
    std::vector<Supplier> *list = new std::vector<Supplier>;
    QSqlQuery query;
    query.exec(QString("select * from [supplier] where exist = 1"));
    while (query.next()) {
        Supplier supplier;
        supplier.setSid(query.value(0).toInt());
        supplier.setExist(query.value(1).toInt());
        supplier.setSname(query.value(2).toString());
        supplier.setAddr(query.value(3).toString());
        supplier.setTel(query.value(4).toString());
        list->push_back(supplier);
    }
    return list;
}

// 模糊查询
std::vector<Supplier> *Mysql::getSupplier(QString name)
{
    std::vector<Supplier> *list = new std::vector<Supplier>;
    QSqlQuery query;
    query.exec(QString("select * from [supplier] where exist = 1 and sname LIKE '%%1%'").arg(name));
    while (query.next()) {
        Supplier supplier;
        supplier.setSid(query.value(0).toInt());
        supplier.setExist(query.value(1).toInt());
        supplier.setSname(query.value(2).toString());
        supplier.setAddr(query.value(3).toString());
        supplier.setTel(query.value(4).toString());
        list->push_back(supplier);
    }
    return list;
}

bool Mysql::isSupplier(const Supplier supplier)
{
   QSqlQuery query;
   query.exec(QString("select * from [supplier] where sid = %1 or sname = '%2'")
               .arg(supplier.getSid()).arg(supplier.getSname()));
   query.next();
   return query.value(0).isNull();

}

int Mysql::SupplierID(const QString name)
{
    QSqlQuery query;
    query.exec(QString("select sid from [supplier] where sname = '%1'")
                .arg(name));
    qDebug() << QString("select sid from [supplier] where sname = '%1'")
                .arg(name);
    query.next();
    qDebug() << query.value(0).toInt();
    return query.value(0).toInt();
}

void Mysql::addSupplier(const Supplier supplier)
{
    QSqlQuery query;
    query.exec(QString("INSERT INTO [dbo].[supplier]( [exist], [sname], [addr], [tel]) "
                       "VALUES (%1, '%2', '%3', '%4')")
               .arg(supplier.getExist())
               .arg(supplier.getSname()).arg(supplier.getAddr()).arg(supplier.getTel())
               );
}

void Mysql::updateSupplier(const Supplier supplier)
{
    //UPDATE [dbo].[supplier] SET [exist] = 1, [sname] = '宝鸡批发商', [addr] = '陕西', [tel] = '44444444444' WHERE [sid] = 5;
    QSqlQuery query;
    QString tmp = QString("UPDATE [dbo].[supplier] SET "
                          "[exist] = %1, [sname] = '%2', [addr] = '%3', [tel] = '%4'"
                          "WHERE [sid] = %5")
                  .arg(supplier.getExist()).arg(supplier.getSname())
                  .arg(supplier.getAddr()).arg(supplier.getTel()).arg(supplier.getSid());
    qDebug() << tmp;
    query.exec(tmp);
}

void Mysql::deleteSupplier(int id)
{
    QSqlQuery query;
    QString tmp = QString("UPDATE [dbo].[supplier] SET "
                          "[exist] = 0 WHERE [sid] = %1").arg(id);
    qDebug() << tmp;
    query.exec(tmp);
}

void Mysql::outgood(int Iid, int num, int uid)
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

QStringList Mysql::getSuppName()
{
    QSqlQuery query;
    QStringList list;
    query.exec(QString("select sname from [supplier] where exist = 1"));
    while (query.next()) {
        list.append(query.value(0).toString());
    }
    return list;
}

// 返回sql
QSqlDatabase Mysql::getsql()
{
    return sql;
}

std::vector<Goods> *Mysql::getGoods()
{
    std::vector<Goods> *list = new std::vector<Goods>;
    QSqlQuery query;
    query.exec(QString("SELECT * from goods"));
    while (query.next()) {
        Goods good;
        good.setCid(query.value(0).toInt());
        good.setCname(query.value(1).toString());
        good.setNum(query.value(2).toInt());
        good.setCategory(query.value(3).toString());
        good.setSnmae(query.value(4).toString());
        good.setAddr(query.value(5).toString());
        good.setTel(query.value(6).toString());
        good.setMinnum(query.value(7).toInt());
        good.setMaxnum(query.value(8).toInt());
        list->push_back(good);
    }
    return list;
}

// 模糊查询
std::vector<Goods> *Mysql::getGoods(const QString name, const QString category)
{
    std::vector<Goods> *list = new std::vector<Goods>;
    QSqlQuery query;
    query.exec(QString("SELECT * from goods "
                       "where sname like '%%1%' "
                       "and category like '%%2%'")
               .arg(name).arg(category));

    while (query.next()) {
        Goods good;
        good.setCid(query.value(0).toInt());
        good.setCname(query.value(1).toString());
        good.setNum(query.value(2).toInt());
        good.setCategory(query.value(3).toString());
        good.setSnmae(query.value(4).toString());
        good.setAddr(query.value(5).toString());
        good.setTel(query.value(6).toString());
        good.setMinnum(query.value(7).toInt());
        good.setMaxnum(query.value(8).toInt());
        list->push_back(good);
    }
    return list;
}

// 模糊查询
std::vector<Goods> *Mysql::getGoodsOut(const QString name, const QString category)
{
    std::vector<Goods> *list = new std::vector<Goods>;
    QSqlQuery query;
    query.exec(QString("SELECT * from goodsin "
                       "where sname like '%%1%' "
                       "and category like '%%2%'")
               .arg(name).arg(category));

    while (query.next()) {
        Goods good;
        good.setCid(query.value(0).toInt());
        good.setCname(query.value(1).toString());
        good.setNum(query.value(7).toInt());
        good.setCategory(query.value(3).toString());
        good.setSnmae(query.value(2).toString());
        good.setMinnum(query.value(11).toInt());
        good.setMaxnum(query.value(12).toInt());
        good.setShelftime(query.value(6).toDateTime());
        good.setTime(query.value(5).toDateTime());
        good.setPrice(query.value(4).toFloat());
        list->push_back(good);
    }
    return list;
}

// 视图查询
int Mysql::getGoodCid(const QString supplier, const QString category, const QString cname)
{
     QSqlQuery query;
     QString tmp = QString("SELECT cid from getGoodCid "
                           "WHERE cname = '%1' "
                           "and category = '%2' "
                           "and sname = '%3'")
             .arg(cname).arg(category).arg(supplier);
     query.exec(tmp);
     query.next();
     return query.value(0).toInt();
}

void Mysql::Myexec(QString tmp)
{
    QSqlQuery query;
    query.exec(tmp);
}

// 查询视图
std::vector<Goods> *Mysql::getinGoods(const QString time)
{
    std::vector<Goods> *list = new std::vector<Goods>;
    QSqlQuery query;
    query.exec(QString("SELECT * from goodsinnn WHERE [time] >= '%1'")
               .arg(time));

    while (query.next()) {
        Goods good;
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
        list->push_back(good);
    }
    return list;
}

// 查询视图
std::vector<Goods> *Mysql::getoutGoods(const QString time)
{
    std::vector<Goods> *list = new std::vector<Goods>;
    QSqlQuery query;
    query.exec(QString("SELECT * from goodsout WHERE [time] >= '%1'")
               .arg(time));

    while (query.next()) {
        Goods good;
        good.setCid(query.value(0).toInt());
        good.setCname(query.value(1).toString());
        good.setSnmae(query.value(2).toString());
        good.setCategory(query.value(3).toString());
        good.setPrice(query.value(4).toFloat());
        good.setTime(query.value(5).toDateTime());
        good.setNum(query.value(6).toInt());
        good.setUid(query.value(7).toInt());
        good.setUname(query.value(8).toString());
        good.setWeight(query.value(9).toFloat());
        good.setMaxnum(query.value(10).toInt());
        good.setMinnum(query.value(11).toInt());
        list->push_back(good);
    }
    return list;
}

std::vector<Goods> *Mysql::getIOGoods(const QString io, const QString time)
{
    std::vector<Goods> *list = new std::vector<Goods>;
    QSqlQuery query;
    query.exec(QString("SELECT * from %1 WHERE [time] > '%2'")
               .arg(io).arg(time));

    while (query.next()) {
        Goods good;
        good.setCid(query.value(0).toInt());
        good.setCname(query.value(1).toString());
        good.setSnmae(query.value(2).toString());
        good.setCategory(query.value(3).toString());
        good.setPrice(query.value(4).toFloat());
        good.setTime(query.value(5).toDateTime());
        good.setNum(query.value(6).toInt());
        good.setUid(query.value(7).toInt());
        good.setUname(query.value(8).toString());
        good.setWeight(query.value(9).toFloat());
        good.setMaxnum(query.value(10).toInt());
        good.setMinnum(query.value(11).toInt());
        list->push_back(good);
    }
    return list;
}
