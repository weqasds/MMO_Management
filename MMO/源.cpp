#pragma once
#include"pch.h"
using namespace std;

int main() {
	string coon = "sa";
	ORM sqlcontrol(coon,true);
	//ORM sqlcontrol2(coon);//�������޷������ǵ����ĸ����캯���������������Ǳ�ڵĹ��캯��
	cout << endl;
	Menu menu(sqlcontrol);
	menu.Main_Menu();
	return 0;
}