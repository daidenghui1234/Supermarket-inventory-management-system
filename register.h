#ifndef REGISTER_H
/*****************************************************************************
@Project name: 02test
@Author: 代登辉
@Creation date : 2020-11-17
@Description: 注册
@Completion date: 完成日期
*****************************************************************************/


#define REGISTER_H

#include <QWidget>

namespace Ui {
class Register;
}

class Register : public QWidget
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = 0);
    ~Register();

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_exit_clicked();

    void on_pushButton_clear_clicked();

private:
    Ui::Register *ui;
signals:
    void CreateEnd();
};

#endif // REGISTER_H
