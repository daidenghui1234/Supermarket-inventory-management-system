/*****************************************************************************
@Project name: 02test
@Author: 代登辉
@Creation date : 2020-11-28
@Description: 商品出库界面头文件
@Completion date: 完成日期
*****************************************************************************/


#ifndef OUTFORM_H
#define OUTFORM_H

#include <QWidget>
#include "mysql.h"
#include <QStandardItemModel>

namespace Ui {
class OutForm;
}

class OutForm : public QWidget
{
    Q_OBJECT

public:
    explicit OutForm(QWidget *parent = 0);
    ~OutForm();

    int getUid() const;
    void setUid(int value);

private:
    Ui::OutForm *ui;

    QStandardItemModel *model;
    Mysql sql;

    // 下拉框设置
    void suppliercomboBox();
    void categorycomboBox();

    void initTable();
    void setTable(int i,std::vector<Goods>::iterator s);

    int uid;
signals:
    void OutFromclose();
private slots:
    void on_pushButton_close_clicked();
    void on_pushButton_refresh_clicked();
    void on_pushButton_out_clicked();
};

#endif // OUTFORM_H
