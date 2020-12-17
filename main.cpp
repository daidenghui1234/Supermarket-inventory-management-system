/*****************************************************************************
@Project name: Description:
@Author: 代登辉
@Creation date : 2020-11-16
@Description: 主文件，一般不做修改
@Completion date: 完成日期
*****************************************************************************/


#include "mywidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MyWidget w;
    // 让主窗口开始不显示
    // w.show();


    return a.exec();
}
