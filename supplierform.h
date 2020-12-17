/*****************************************************************************
@Project name: 02test
@Author: 代登辉
@Creation date : 2020-11-28
@Description: 供应商管理界面头文件
@Completion date: 完成日期
*****************************************************************************/


#ifndef SUPPLIERFORM_H
#define SUPPLIERFORM_H

#include "mysql.h"
#include <QWidget>
#include <QSqlDatabase>
#include <QStandardItemModel>

namespace Ui {
class SupplierForm;
}

class SupplierForm : public QWidget
{
    Q_OBJECT

public:
    explicit SupplierForm(QWidget *parent = 0);
    ~SupplierForm();

private slots:
    void on_pushButton_close_clicked();

    void on_pushButton_refresh_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_sure_clicked();

    void on_pushButton_alter_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_find_clicked();

private:
    Ui::SupplierForm *ui;
    Mysql sql;
    QStandardItemModel *model;

    void initTable();
    void setTable(int i,std::vector<Supplier>::iterator s);
    void getSupplier(int row,Supplier & supplier);

    int addSupplier(const Supplier &supplier);
    void upadteSupplier(const Supplier &supplier);
    int list[20];
    int size;

signals:
    void Supplierclose();
};

#endif // SUPPLIERFORM_H
