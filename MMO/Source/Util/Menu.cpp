#include "..\..\pch.h"

Menu::Menu()
{
	this->admin = Admin();
	Login();
	return;
}

void Menu::Login()
{
	cout << "";
	cin >> this->admin;
	admin.Set_Level(Level::normal);
	if (!this->admin) {
		/**/
		cout << "�˻���¼ʧ�ܣ�����" << endl;
		exit(1);
	}
	return;
}

void Menu::Main_Menu()
{
	int c;
	bool condtion = true;
	cout << endl;
	cout << "************************************************" << endl;
	cout << "********************����Ա�˵�********************" << endl;
	cout << "******************1���ݲ��ݹ���*******************" << endl;
	cout << "******************2���ݱ��ݻ�ԭ*******************" << endl;
	cout << "*******************3����̨ʹ��********************" << endl;
	cout << "********************4����Ȩ��*********************" << endl;
	cout << "********************5�߼�����*********************" << endl;
	cout << "********************6�˳���¼*********************" << endl;
	cout << endl;
	cout << "��ѡ��:";
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
			case 4:Apply();
				break;
			case 5:Advanced_Menu();
				break;
			case 6:
				condtion = false;
				break;
			default:
				cout << "ѡ�����������ѡ��";
				cin >> c;
				break;
			}
		}
	}
	catch (const std::exception& e)
	{
		cout << "�������쳣��������ϢΪ��" << e.what() << endl;
		cout << "�������������ֹ����" << endl;
		exit(100);
	}
}

void Menu::Data_Manipulation()
{
	int c;
	bool control = true;
	cout << endl;
	cout << "*************************************************" << endl;
	cout << "*********************�����˵�********************" << endl;
	cout << "*********************1.����**********************" << endl;
	cout << "*********************2.��ѯ**********************" << endl;
	cout << "*********************3.����**********************" << endl;
	cout << "*********************4.ɾ��**********************" << endl;
	cout << "*********************5.���**********************" << endl;
	cout << "*********************6.������һ���˵�**************" << endl;
	cout << "*********************7.����̨*********************" << endl;
	cout << "*************************************************" << endl;
	cout << "��ѡ��:";
	cin >> c;
	while (control)
	{
		switch (c)
		{
		case 1:
			;
		case 2:;
		case 3:;
		case 4:;
		case 5:;
		case 6:;
		case 7:;

		default:
			break;
		}
	}
}

void Menu::Data_RB_Menu()
{
}

void Menu::Advanced_Menu()
{
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
