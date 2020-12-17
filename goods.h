/*****************************************************************************
@Project name: 02test
@Author: 代登辉
@Creation date : 2020-11-29
@Description: 商品实体类
@Completion date: 完成日期
*****************************************************************************/


#ifndef GOODS_H
#define GOODS_H
#include <QString>
#include <QDebug>
#include <qdatetime.h>

class Goods
{
public:
    Goods();

    int getCid() const;
    void setCid(int value);

    QString getCname() const;
    void setCname(const QString &value);

    int getNum() const;
    void setNum(int value);

    QString getCategory() const;
    void setCategory(const QString &value);

    QString getSnmae() const;
    void setSnmae(const QString &value);

    QString getAddr() const;
    void setAddr(const QString &value);

    QString getTel() const;
    void setTel(const QString &value);

    int getMinnum() const;
    void setMinnum(int value);

    int getMaxnum() const;
    void setMaxnum(int value);

    void printGoods();

    QDateTime getShelftime() const;
    void setShelftime(const QDateTime &value);

    QDateTime getTime() const;
    void setTime(const QDateTime &value);


    float getPrice() const;
    void setPrice(float value);

    int getUid() const;
    void setUid(int value);

    QString getUname() const;
    void setUname(const QString &value);

    float getWeight() const;
    void setWeight(float value);

private:
    int cid;             // 入库或出库的id
    QString cname;      // 商品名称
    int num;            // 数量
    QString category;   // 商品类别
    QString sname;      // 供货商名称
    QString addr;       // 地址
    QString tel;        // 电话
    int minnum;         // 最小库存
    int maxnum;         // 最大库存
    QDateTime shelftime;
    QDateTime time;
    float price;
    int uid;
    QString uname;
    float weight;

};

#endif // GOODS_H
