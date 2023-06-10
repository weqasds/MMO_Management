#pragma once
#include"..\..\pch.h"
class Menu
{
public:
	Menu();//菜单
	void Login();//登录
	void Main_Menu();//主菜单
	void Data_Manipulation();//数据操纵功能
	void Data_RB_Menu();//数据备份还原菜单
	void Advanced_Menu();//高级菜单
	void Data_Restore();//数据还原功能
	void Data_Backup();//数据备份功能
	void Console();//控制台使用
	void Apply();//申请
	void Data_Maintenance();//数据维护
	void Data_Migrate();//数据迁移
	void Add();//增加新功能
	void Delete();//删除旧功能
	~Menu();
private:
	Admin admin;
};

