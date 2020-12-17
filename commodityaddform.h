#ifndef COMMODITYADDFORM_H
#define COMMODITYADDFORM_H

#include <QWidget>
#include "mysql.h"

namespace Ui {
class CommodityAddForm;
}

class CommodityAddForm : public QWidget
{
    Q_OBJECT

public:
    explicit CommodityAddForm(QWidget *parent = 0);
    ~CommodityAddForm();

private slots:
    void on_pushButton_exit_clicked();

    void on_pushButton_new_clicked();

private:
    Ui::CommodityAddForm *ui;
    Mysql sql;

    // 下拉框设置
    void suppliercomboBox();

signals:
    void commodhide();
};

#endif // COMMODITYADDFORM_H
