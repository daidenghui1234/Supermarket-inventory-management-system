/*****************************************************************************
@Project name: 02test
@Author: 代登辉
@Creation date : 2020-11-19
@Description: 商品类头文件
@Completion date: 完成日期
*****************************************************************************/


#ifndef GOODSIN_H
#define GOODSIN_H

#include <QWidget>

namespace Ui {
class GoodsIn;
}

class GoodsIn : public QWidget
{
    Q_OBJECT

public:
    explicit GoodsIn(QWidget *parent = 0);
    ~GoodsIn();

private:
    Ui::GoodsIn *ui;
};

#endif // GOODSIN_H
