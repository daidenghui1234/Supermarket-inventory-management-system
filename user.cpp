/*****************************************************************************
@Project name: 02test
@Author: 代登辉
@Creation date : 2020-11-17
@Description: 管理员cpp文件
@Completion date: 完成日期
*****************************************************************************/


#include "user.h"
#include <QDebug>
#include <QString>

/*************************************************
Function: User()
Description: User无参构造函数
*************************************************/
User::User() :User(1,"","","",0,"")
{
}

/*************************************************
Function: User
Description: User有参构造函数
Input: (int exit):[用户是否有效],(QString uname):[用户名],
       (QString upassword):[密码],(QString sex):[性别],
       (QString tel):[电话]
*************************************************/
User::User(int exit, QString uname, QString upassword, QString sex, int age, QString tel)
{
    this->exit = exit;
    this->uname = uname;
    this->upassword = upassword;
    this->sex = sex;
    this->age = age;
    this->tel = tel;
}

void User::setId(int id)
{
    this->id = id;
}

// 设置是否有效
void User::setExit(int exit)
{
    this->exit = exit;
}

// 设置是否有效
void User::setAge(int age)
{
    this->age = age;
}

// 设置时间
void User::setTime(QDateTime time)
{
    this->time = time;
}
// 设置用户名
void User::setUname(QString uname)
{
    this->uname = uname;
}

// 设置密码
void User::setUpassword(QString upassword)
{
    this->upassword = upassword;
}

// 设置性别
void User::setSex(QString sex)
{
    this->sex = sex;
}

// 设置电话
void User::setTel(QString tel)
{
    this->tel = tel;
}

// 打印用户
void User::printUser()
{
    QString tmp = QString("是否有效:[%1],用户id: [%8], 用户名:[%2],"
                          " 密码:[%3], 性别:[%4], "
                          "年龄:[%5], 电话:[%6], 注册时间[%7]").arg(exit).arg(uname).
                        arg(upassword).arg(sex).arg(age)
                        .arg(tel).arg(time.toString()).arg(id);
    qDebug() <<tmp;
}

// 方便sql语句
QString User::getUser()
{
    usercommd.clear();
    usercommd = QString("%7, %1,'%2','%3','%4',%5,'%6'").arg(exit).arg(uname).arg(upassword).arg(sex).arg(age).arg(tel).arg(id);
    return usercommd;
}

// 获取id
int User::getId()
{
    return this->id;
}

// 获取是否存在
int User::getExit()
{
    return this->exit;
}

// 获取姓名
QString User::getUname()
{
    return this->uname;
}

// 获取密码
QString User::getUpassword()
{
    return this->upassword;
}

// 获取性别
QString User::getSex()
{
    return this->sex;
}

// 获取年龄
int User::getAge()
{
    return this->age;
}

// 获取电话
QString User::getTel()
{
    return this->tel;
}

// 返回时间
QDateTime User::getTime()
{
    return this->time;
}
