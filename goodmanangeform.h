/*****************************************************************************
@Project name: 02test
@Author: 代登辉
@Creation date : 2020-11-28
@Description: 商品管理界面头文件
@Completion date: 完成日期
*****************************************************************************/


#ifndef GOODMANANGEFORM_H
#define GOODMANANGEFORM_H

#include <QWidget>
#include "mysql.h"
#include <QStandardItemModel>

namespace Ui {
class GoodManangeForm;
}

class GoodManangeForm : public QWidget
{
    Q_OBJECT

public:
    explicit GoodManangeForm(QWidget *parent = 0);
    ~GoodManangeForm();

private slots:
    // 自动生成的槽函数
    void on_pushButton_close_clicked();  // 按下关闭按钮

    void on_pushButton_refresh_clicked();

    void on_pushButton_find_clicked();

private:
    Ui::GoodManangeForm *ui;
    QStandardItemModel *model;
    Mysql sql;

    // 下拉框设置
    void suppliercomboBox();
    void categorycomboBox();

    void initTable();
    void setTable(int i,std::vector<Goods>::iterator s);
signals:
    // 自定义信号
    void GoodManangeclose();  // 窗口关闭
};

#endif // GOODMANANGEFORM_H
