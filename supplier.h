/*****************************************************************************
@Project name: 02test
@Author: 代登辉
@Creation date : 2020-11-28
@Description: 供应商实体类
@Completion date: 完成日期
*****************************************************************************/


#ifndef SUPPLIER_H
#define SUPPLIER_H
#include <QString>

class Supplier
{
public:
    Supplier();


    int getSid() const;
    void setSid(int value);

    int getExist() const;
    void setExist(int value);

    QString getSname() const;
    void setSname(const QString &value);

    QString getAddr() const;
    void setAddr(const QString &value);

    QString getTel() const;
    void setTel(const QString &value);

    void printSupplier();
private:
    int sid;
    int exist;
    QString sname;
    QString addr;
    QString tel;
};

#endif // SUPPLIER_H
