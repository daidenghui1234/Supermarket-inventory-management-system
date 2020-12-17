/*****************************************************************************
@Project name: 02test
@Author: 代登辉
@Creation date : 2020-11-17
@Description: 数据库头文件
@Completion date: 完成日期
*****************************************************************************/


#ifndef MYSQL_H
#define MYSQL_H

#include <QSqlDatabase>
#include <QString>
#include <QStringList>
#include "user.h"
#include "supplier.h"
#include "goods.h"
#include <vector>

class Mysql
{
public:
    Mysql();

    // 判断用户名和密码是否存在
    bool verifyLogin(const QString name,const QString password);
    // 申请用户名和密码
    bool applyAccount(User user);
    // 用户名是否存在
    int isUname(const QString name);
    bool isUid(int id);
    // 根据uid设置user内容
    bool setUser(int uid,User &user);
    // 返回所有用户列表
    std::vector<User>* getUsers();
    std::vector<User>* getUsers(QString name);
    bool deleteUser(int id);

    // 返回供应商列表
    std::vector<Supplier>* getSupplier();
    std::vector<Supplier>* getSupplier(QString name);
    bool isSupplier(const Supplier supplier);
    int SupplierID(const QString name);
    void addSupplier(const Supplier supplier);
    void updateSupplier(const Supplier supplier);
    void deleteSupplier(int id);
    void outgood(int Iid,int num, int uid);
    QStringList getSuppName();

    QSqlDatabase getsql();

    // 获取商品信息
    std::vector<Goods>* getGoods();
    std::vector<Goods>* getGoods(const QString name,const QString category);

    std::vector<Goods>* getGoodsOut(const QString name,const QString category);
    std::vector<Goods>* getGoodsOut2(const QString cname,const QString sname,const QString category);


    int getGoodCid(const QString supplier,
                   const QString category,
                   const QString cname
                   );

    void Myexec(QString tmp);

    std::vector<Goods> *getinGoods(const QString time);
    std::vector<Goods> *getoutGoods(const QString time);
    std::vector<Goods> *getIOGoods(const QString io,const QString time);


private:
    QSqlDatabase sql; //数据库
};

#endif // MYSQL_H
