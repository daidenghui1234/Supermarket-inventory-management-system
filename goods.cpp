#include "goods.h"

Goods::Goods()
{

}

int Goods::getCid() const
{
    return cid;
}

void Goods::setCid(int value)
{
    cid = value;
}

QString Goods::getCname() const
{
    return cname;
}

void Goods::setCname(const QString &value)
{
    cname = value;
}

int Goods::getNum() const
{
    return num;
}

void Goods::setNum(int value)
{
    num = value;
}

QString Goods::getCategory() const
{
    return category;
}

void Goods::setCategory(const QString &value)
{
    category = value;
}

QString Goods::getSnmae() const
{
    return sname;
}

void Goods::setSnmae(const QString &value)
{
    sname = value;
}

QString Goods::getAddr() const
{
    return addr;
}

void Goods::setAddr(const QString &value)
{
    addr = value;
}

QString Goods::getTel() const
{
    return tel;
}

void Goods::setTel(const QString &value)
{
    tel = value;
}

int Goods::getMinnum() const
{
    return minnum;
}

void Goods::setMinnum(int value)
{
    minnum = value;
}

int Goods::getMaxnum() const
{
    return maxnum;
}

void Goods::setMaxnum(int value)
{
    maxnum = value;
}

void Goods::printGoods()
{
    QString tmp = QString("id:%1, name:%2, num:%3, categroy:%4,"
                          " sname:%5, addr:%6, tel:%7, min:%8, max:%8")
            .arg(cid).arg(cname).arg(num).arg(category)
            .arg(sname).arg(addr).arg(minnum).arg(maxnum);
    qDebug() << tmp;
}

QDateTime Goods::getShelftime() const
{
    return shelftime;
}

void Goods::setShelftime(const QDateTime &value)
{
    shelftime = value;
}

QDateTime Goods::getTime() const
{
    return time;
}

void Goods::setTime(const QDateTime &value)
{
    time = value;
}

float Goods::getPrice() const
{
    return price;
}

void Goods::setPrice(float value)
{
    price = value;
}

int Goods::getUid() const
{
    return uid;
}

void Goods::setUid(int value)
{
    uid = value;
}

QString Goods::getUname() const
{
    return uname;
}

void Goods::setUname(const QString &value)
{
    uname = value;
}

float Goods::getWeight() const
{
    return weight;
}

void Goods::setWeight(float value)
{
    weight = value;
}
