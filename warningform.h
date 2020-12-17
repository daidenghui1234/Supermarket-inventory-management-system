#ifndef WARNINGFORM_H
#define WARNINGFORM_H

#include <QWidget>
#include <QSqlDatabase>
#include <vector>
#include <goods.h>
#include <QStandardItemModel>
#include <QTimer>
enum Flag {OVER, EXPI, LACK, NIMI};

namespace Ui {
class WarningForm;
}

class WarningForm : public QWidget
{
    Q_OBJECT

public:
    explicit WarningForm(QWidget *parent = 0);
    ~WarningForm();

    void initDataBase();

private slots:
    void on_pushButton_refresh_clicked();

    void on_pushButton_close_clicked();

private:
    Ui::WarningForm *ui;

    QSqlDatabase sql;
    QStandardItemModel *model;

    void inittable();

    void inittableGoods();
    void initGoods(Goods &good);
    void initGoods(Goods &good,QSqlQuery &query);
    void initGoodgoods(Goods &good,QSqlQuery &query);
    void settable(int i,std::vector<Goods>::iterator s);
    void settableGoods(int i,std::vector<Goods>::iterator s);
    std::vector<Goods> getgoods();
    std::vector<Goods> getExpiringgoods();
    std::vector<Goods> getlackgoods();
    std::vector<Goods> getnimietygoods();

    void outgood(int Iid,int num, int uid);

    void deletegoods();
    void deleteExpiringgoods();
    void deletelackgoods();
    void deletenimietygoods();

    void Overdue(); // 过期
    void Expiring(); // 将过期
    void lack(); // 缺少
    void nimiety(); // 多余

    bool ifOverdue();
    bool ifExpiring();
    bool iflack();
    bool ifnimiety();

    Flag f;


    QTimer *m_timer;
    void myTimeer();
    void flash();
signals:
    void myWarning();
};

#endif // WARNINGFORM_H
