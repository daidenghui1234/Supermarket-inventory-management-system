#include "supplier.h"
#include <QDebug>

Supplier::Supplier()
{

}


int Supplier::getSid() const
{
    return sid;
}

void Supplier::setSid(int value)
{
    sid = value;
}

int Supplier::getExist() const
{
    return exist;
}

void Supplier::setExist(int value)
{
    exist = value;
}

QString Supplier::getSname() const
{
    return sname;
}

void Supplier::setSname(const QString &value)
{
    sname = value;
}

QString Supplier::getAddr() const
{
    return addr;
}

void Supplier::setAddr(const QString &value)
{
    addr = value;
}

QString Supplier::getTel() const
{
    return tel;
}

void Supplier::setTel(const QString &value)
{
    tel = value;
}

void Supplier::printSupplier()
{
    qDebug() << QString("主键：%1; 是否存在：%2; 公司名：%3; 地址：%4; 电话：%5 ")
                .arg(sid).arg(exist).arg(sname).arg(addr).arg(tel);
}
