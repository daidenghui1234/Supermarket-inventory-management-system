/*****************************************************************************
@Project name: 02test
@Author: 代登辉
@Creation date : 2020-11-28
@Description: 商品入库头文件
@Completion date: 完成日期
*****************************************************************************/


#ifndef INFORM_H
#define INFORM_H

#include <QWidget>
#include "mysql.h"
#include "user.h"
#include <QStandardItemModel>
#include "commodityaddform.h"

namespace Ui {
class InForm;
}

class InForm : public QWidget
{
    Q_OBJECT

public:
    explicit InForm(QWidget *parent = 0);
    ~InForm();
    void static setUser(User &use);

    int getUid() const;
    void setUid(int value);

private slots:
    // 自动生成槽函数
    void on_pushButton_close_clicked();  // 当点击关闭按钮

    void on_pushButton_clear_clicked();

    void on_pushButton_in_clicked();

    void on_pushButton_new_clicked();

private:
    Ui::InForm *ui;

    QStandardItemModel *model;
    Mysql sql;

    // 下拉框设置
    void suppliercomboBox();
    void categorycomboBox();

    static User &user;
    CommodityAddForm *commd;

    int uid;




signals:
    // 自定义信号
    void InFromclose();  // 窗口关闭信号
};

#endif // INFORM_H
