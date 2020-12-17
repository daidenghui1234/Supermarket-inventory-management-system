/*****************************************************************************
@Project name: 02test
@Author: 代登辉
@Creation date : 2020-11-28
@Description: 报表管理界面头文件
@Completion date: 完成日期
*****************************************************************************/


#ifndef STATEMENTFORM_H
#define STATEMENTFORM_H

#include "mysql.h"
#include <QWidget>
#include <QSqlDatabase>
#include <QStandardItemModel>

namespace Ui {
class StatementForm;
}

class StatementForm : public QWidget
{
    Q_OBJECT

public:
    explicit StatementForm(QWidget *parent = 0);
    ~StatementForm();

    int getUid() const;
    void setUid(int value);

private slots:
    void on_pushButton_close_clicked();

    void on_pushButton_refresh_clicked();

private:
    Ui::StatementForm *ui;

    Mysql sql;
    QStandardItemModel *model;

    void initable(int io);
    void setINTable(int i,std::vector<Goods>::iterator s);
    void setOUTable(int i,std::vector<Goods>::iterator s);
    int uid;
signals:
    void Statementclose();
};

#endif // STATEMENTFORM_H
