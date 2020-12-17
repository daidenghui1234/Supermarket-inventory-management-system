/*****************************************************************************
@Project name: 02test
@Author: 代登辉
@Creation date : 2020-11-19
@Description: 商品类cpp
@Completion date: 完成日期
*****************************************************************************/


#include "goodsin.h"
#include "ui_goodsin.h"

GoodsIn::GoodsIn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GoodsIn)
{
    ui->setupUi(this);
}

GoodsIn::~GoodsIn()
{
    delete ui;
}
