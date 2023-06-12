#pragma once
#include"pch.h"
using namespace std;

int main() {
	string coon = "sa";
	ORM sqlcontrol(coon,true);
	//ORM sqlcontrol2(coon);//编译器无法分清是调用哪个构造函数，这里存在两个潜在的构造函数
	cout << endl;
	Menu menu(sqlcontrol);
	menu.Main_Menu();
	return 0;
}