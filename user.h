/*****************************************************************************
@Project name: 02test
@Author: 代登辉
@Creation date : 2020-11-17
@Description: 管理员头文件
@Completion date: 完成日期
*****************************************************************************/


#ifndef USER_H
#define USER_H
#include <QString>
#include <QDateTime>

class User
{
public:
    User();
    User(int exit, QString uname, QString upassword, QString sex, int age, QString tel);

    void setId(int id);
    void setExit(int exit);
    void setUname(QString uname);
    void setUpassword(QString upassword);
    void setSex(QString sex);
    void setTel(QString tel);
    void setAge(int age);
    void setTime(QDateTime time);

    void printUser();
    QString getUser();
    int getId();
    int getExit();
    QString getUname();
    QString getUpassword();
    QString getSex();
    int getAge();
    QString getTel();
    QDateTime getTime();

private:
    int exit;  // 是否有效
    QString uname;  // 性名
    QString upassword;  // 密码
    QString sex;  // 性别
    int age;  // 年龄
    QString tel;  // 电话
    QString usercommd;  // 为了方便sql插入
    int id;
    QDateTime time;

};

#endif // USER_H
