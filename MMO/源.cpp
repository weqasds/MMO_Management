#pragma once
#include"pch.h"
using namespace std;

int main() {
	////mysqlx://user_name@localhost:33065
	//// mysqlx://user:pwd@host:port/db
	//string coon1 = "mysqlx://root:qq13015461197@localhost:33060/game";
	string coon = "mysqlx://root:qq13015461197@localhost:33060";
	ORM sqlcontrol(coon,true);
	cout << endl;
	Menu menu(sqlcontrol);
	menu.Main_Menu();

	/*mysqlx::Session s(coon);
	mysqlx::Schema db = s.getSchema("game",true);
	auto table = db.getTables();
	for (auto t : table) {
		cout << t.getName() << endl;
	}*/
	//ORM sqlcontrol2(coon);//�������޷������ǵ����ĸ����캯���������������Ǳ�ڵĹ��캯��
	return 0;
}