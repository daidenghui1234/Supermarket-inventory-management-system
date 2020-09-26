#include "mysql.h"
#include <iostream>

#define _HOST_ "127.0.0.1"
#define _USER_ "root"  //���ݿ��û�
#define _PASSWD_ "123456"
#define _DBNAME_ "mydb1"

using namespace std;

// �������ݵ����ݿ�
void inster_data() {
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

	// �����ַ���ʽ
	char rSql[256] = { 0 };
	strcpy_s(rSql, "set names gbk");
	if (mysql_query(mysql, rSql) != 0) {
		cout << "�����ַ���ʽʧ��" << endl;
		exit(1);
	}
	// ��������
	strcpy_s(rSql, "INSERT INTO emp VALUE(5,'��',1,'2018-08-27',20000,'2020-07-05','һ����ɵ��')");
	if (mysql_query(mysql, rSql) != 0) {
		cout << "2�������" << endl;
		exit(1);
	}


	//3. close
	mysql_close(mysql);
}

// �õ����ݿ������
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
	cout << "hello mysql!" << endl;


	// ����
	char rSql[256] = { 0 };
	// ���ñ����ʽ
	strcpy_s(rSql, "set names gbk");
	if (mysql_query(mysql, rSql) != 0) {
		cout << "�����ַ���ʽʧ��" << endl;
		exit(1);
	}
	strcpy_s(rSql, "select * from emp");
	if (mysql_query(mysql, rSql) != 0) {
		cout << "��ѯʧ��" << endl;
		exit(1);
	}
	// ȡ�ؽ����
	MYSQL_RES * result = mysql_store_result(mysql);
	MYSQL_ROW row;
	int i = 0;
	if (result != NULL) {
		// ��Ҫ��ӡ�����
		// ѭ��ȡһ��
		while ((row = mysql_fetch_row(result)) != NULL ) {
			for (i = 0; i < 7; i++) {
				cout << row[i] << " ";
			}
			cout << endl;
		}
		// �ͷŽ����
		mysql_free_result(result);
	}
	//3. close
	mysql_close(mysql);
}
int main()
{
	//inster_data();
	get_data();
	return 0;
}
