#include "mysql.h"
#include <iostream>

#define _HOST_ "127.0.0.1"
#define _USER_ "root"  //数据库用户
#define _PASSWD_ "123456"
#define _DBNAME_ "mydb1"

using namespace std;
int main()
{
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
	cout << "hello mysql!" << endl;

	char rSql[256] = { 0 };
	//
	strcpy_s(rSql,"INSERT INTO aa VALUE(10,'代')");
	if (mysql_query(mysql, rSql) != 0) {
		cout << "插入错误" << endl;
		exit(1);
	}


	//3. close
	mysql_close(mysql);
	return 0;
}
