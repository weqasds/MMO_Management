#include "..\..\pch.h"
Menu::Menu(ORM& c):cache(c)
{
	this->admin = Admin();
	Login();
	return;
}

void Menu::Login()//登录
{
	cout << "";
	cin >> this->admin;
	admin.Set_Level(Level::normal);
	if (!this->admin) {
		/**/
		cout << "账户登录失败！！！" << endl;
		exit(1);
	}
	return;
}

void Menu::Main_Menu()//主菜单
{
	int c;
	bool condtion = true;
	cout << endl;
	cout << "************************************************" << endl;
	cout << "*********************主菜单**********************" << endl;
	cout << "******************1数据操纵功能*******************" << endl;
	cout << "******************2数据备份还原*******************" << endl;
	cout << "*******************3控制台使用********************" << endl;
	cout << "********************4申请权限*********************" << endl;
	cout << "********************5高级功能*********************" << endl;
	cout << "********************6退出登录*********************" << endl;
	cout << "************************************************" << endl;
	cout << endl;
	cout << "请选择:";
	cin >> c;
	try
	{
		while (condtion)
		{
			switch (c)
			{
			case 1:
				Data_Manipulation();
				break;
			case 2:
				Data_RB_Menu();
				break;
			case 3:
				Console();
				break;
			case 4:
				Apply();
				break;
			case 5:Advanced_Menu();
				break;
			case 6:
				condtion = false;
				break;
			default:
				cout << "选择错误，请重新选择：";
				cin >> c;
				break;
			}
		}
	}
	catch (const std::exception& e)
	{
		cout << "程序发生异常，错误信息为：" << e.what() << endl;
		cout << "程序产生错误，终止运行" << endl;
		exit(100);
	}
}

void Menu::Data_Manipulation()
{
	int c;
	bool condtion = true;
	cout << endl;
	cout << "*************************************************" << endl;
	cout << "*********************操作菜单********************" << endl;
	cout << "*********************1.插入**********************" << endl;
	cout << "*********************2.查询**********************" << endl;
	cout << "*********************3.更新**********************" << endl;
	cout << "*********************4.删除**********************" << endl;
	cout << "*********************5.清空**********************" << endl;
	cout << "*********************6.返回上一级菜单**************" << endl;
	cout << "*********************7.控制台*********************" << endl;
	cout << "*************************************************" << endl;
	cout << "请选择:";
	cin >> c;
	while (condtion)
	{
		switch (c)
		{
		case 1:
			((DbSet*)this->cache.GetSelectTable())->Insert();
			break;
		case 2:
			((DbSet*)this->cache.GetSelectTable())->Select();
			break;
		case 3:
			((DbSet*)this->cache.GetSelectTable())->Update();
			break;
		case 4:
			((DbSet*)this->cache.GetSelectTable())->Remove();
			break;
		case 5:
			;
			break;
		case 6:
			condtion = false;
			break;
		case 7:
			Console();
			break;
		default:
			cout << "输入错误，请重新输入:";
			break;
		}
		cin >> c;
	}
}

void Menu::Data_RB_Menu()
{
	int c;
	bool condtion = true;
	cout << endl;
	cout << "*************************************************" << endl;
	cout << "*********************操作菜单**********************" << endl;
	cout << "*********************1.备份数据********************" << endl;
	cout << "*********************2.还原数据********************" << endl;
	cout << "*********************3.返回上一级菜单***************" << endl;
	cout << "*************************************************" << endl;
	cout << "请选择:";
	cin >> c;
	while (condtion)
	{
		switch (c)
		{
		case 1:
			Data_Backup();
			break;
		case 2:
			Data_Restore();
			break;
		case 3:
			condtion = false;
			break;
		default:
			cout << "输入错误，请重新输入:";
			break;
		}
		cin >> c;
	}
}

void Menu::Advanced_Menu()
{
	int c;
	bool condtion = true;
	cout << endl;
	cout << "************************************************" << endl;
	cout << "********************高级菜单*********************" << endl;
	cout << "********************1.数据迁移*******************" << endl;
	cout << "********************2.数据维护*******************" << endl;
	cout << "********************3.增加功能*******************" << endl;
	cout << "********************4.删除功能*******************" << endl;
	cout << "********************5.控制台*********************" << endl;
	cout << "********************6.返回上一级菜单**************" << endl;
	cout << "************************************************" << endl;
	cout << endl;
	cout << "请选择功能:";
	cin >> c;
	while (condtion)
	{
		switch (c)
		{
		case 1:
			Data_Migrate();
			break;
		case 2:
			Data_Maintenance();
			break;
		case 3:
			Add();
			break;
		case 4:
			Delete();
			break;
		case 5:
			Console();
			break;
		case 6:
			condtion = false;
			break;
		default:
			cout << "输入错误，请重新输入:";
			break;
		}
	}

}

void Menu::Data_Restore()
{
}

void Menu::Data_Backup()
{
}

void Menu::Console()
{
}

void Menu::Apply()
{
}

void Menu::Data_Maintenance()
{
}

void Menu::Data_Migrate()
{
}


void Menu::Add()
{
}

void Menu::Delete()
{
}

Menu::~Menu()
{
}
