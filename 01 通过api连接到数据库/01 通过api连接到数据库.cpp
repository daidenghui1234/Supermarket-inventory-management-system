#include "mysql.h"
#include <iostream>
#include <iomanip>
#define _HOST_ "127.0.0.1"
#define _USER_ "root"  //数据库用户
#define _PASSWD_ "123456"
#define _DBNAME_ "mydb1"

using namespace std;
void show_result(MYSQL_RES * result){
	MYSQL_ROW row;
	if (result != NULL) {
		// 取字段个数
		int num_fileds = mysql_num_fields(result);
		// 需要打印结果集
		// 打印表头
		MYSQL_FIELD * fieldes;
		fieldes = mysql_fetch_fields(result);
		for (int i = 0; i < num_fileds; i++) {
			cout << setw(5) << fieldes[i].name << "  ";
		}
		cout << endl;
		cout << "*************************************************************" << endl;
		// 循环取一行
		while ((row = mysql_fetch_row(result)) != NULL) {
			for (int i = 0; i < num_fileds; i++) {
				cout << setw(5) << (row[i] ? row[i] : "NULL") << "  ";
			}
			cout << endl;
		}
	}
}
// 插入数据到数据库
void inster_data() {
	//1. init 
	MYSQL* mysql = mysql_init(NULL);
	if (mysql == NULL) {
		cout << "数据库连接成功!" << endl;
		exit(1);
	}
	//2. real_connect
	mysql = mysql_real_connect(mysql, _HOST_, _USER_, _PASSWD_, _DBNAME_, 0, NULL, 0);

	if (mysql == NULL) {
		cout << "connect err" << endl;
		exit(1);
	}
	cout << "hello mysql!" << endl;

	// 设置字符格式
	char rSql[256] = { 0 };
	strcpy_s(rSql, "set names gbk");
	if (mysql_query(mysql, rSql) != 0) {
		cout << "设置字符格式失败" << endl;
		exit(1);
	}
	// 插入数据
	strcpy_s(rSql, "INSERT INTO emp VALUE(6,'代',1,'2018-08-27',20000,'2020-07-05','一个大傻逼')");
	if (mysql_query(mysql, rSql) != 0) {
		cout << "2插入错误" << endl;
		exit(1);
	}


	//3. close
	mysql_close(mysql);
}

// 得到数据库的数据
void get_data() {
	//1. init 
	MYSQL* mysql = mysql_init(NULL);
	if (mysql == NULL) {
		cout << "init err" << endl;
		exit(1);
	}
	//2. real_connect
	mysql = mysql_real_connect(mysql, _HOST_, _USER_, _PASSWD_, _DBNAME_, 0, NULL, 0);

	if (mysql == NULL) {
		cout << "connect err" << endl;
		exit(1);
	}
	cout << "数据库连接成功!" << endl;


	// 命令
	char rSql[256] = { 0 };
	// 设置编码格式
	strcpy_s(rSql, "set names gbk");
	if (mysql_query(mysql, rSql) != 0) {
		cout << "设置字符格式失败" << endl;
		exit(1);
	}
	strcpy_s(rSql, "select * from emp");
	if (mysql_query(mysql, rSql) != 0) {
		cout << "查询失败" << endl;
		exit(1);
	}
	// 取回结果集
	MYSQL_RES * result = mysql_store_result(mysql);
	show_result(result);
	// 释放结果集
	mysql_free_result(result);
	//3. close
	mysql_close(mysql);
}

int main()
{
	//inster_data();
	get_data();
	return 0;
}
