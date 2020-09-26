#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mysql.h"

#define _HOST_ "127.0.0.1"
#define _USER_ "root"  //数据库用户
#define _PASSWD_ "123456"
#define _DBNAME_ "mydb1"


int main()
{
	//1. init 
	MYSQL*mysql = mysql_init(NULL);
	if (mysql == NULL) {
		printf("init err\n");
		exit(1);
	}
	//2. real_connect
	mysql = mysql_real_connect(mysql, _HOST_, _USER_, _PASSWD_, _DBNAME_, 0, NULL, 0);

	if (mysql == NULL) {
		printf("connect err\n");
		exit(1);
	}
	printf("hello mysql!\n");
	//3. close
	mysql_close(mysql);
	return 0;
}
