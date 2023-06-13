#include "..\..\pch.h"
#define BUFSIZE 4096 
//HANDLE g_hChildStd_IN_Rd = NULL;
//HANDLE g_hChildStd_IN_Wr = NULL;
//HANDLE g_hChildStd_OUT_Rd = NULL;
//HANDLE g_hChildStd_OUT_Wr = NULL;
//void ErrorExit(PTSTR lpszFunction)
//
//// Format a readable error message, display a message box, 
//// and exit from the application.
//{
//	LPVOID lpMsgBuf;
//	LPVOID lpDisplayBuf;
//	DWORD dw = GetLastError();
//
//	FormatMessage(
//		FORMAT_MESSAGE_ALLOCATE_BUFFER |
//		FORMAT_MESSAGE_FROM_SYSTEM |
//		FORMAT_MESSAGE_IGNORE_INSERTS,
//		NULL,
//		dw,
//		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
//		(LPTSTR)&lpMsgBuf,
//		0, NULL);
//
//	lpDisplayBuf = (LPVOID)LocalAlloc(LMEM_ZEROINIT,
//		(lstrlen((LPCTSTR)lpMsgBuf) + lstrlen((LPCTSTR)lpszFunction) + 40) * sizeof(TCHAR));
//	StringCchPrintf((LPTSTR)lpDisplayBuf,
//		LocalSize(lpDisplayBuf) / sizeof(TCHAR),
//		TEXT("%s failed with error %d: %s"),
//		lpszFunction, dw, lpMsgBuf);
//	MessageBox(NULL, (LPCTSTR)lpDisplayBuf, TEXT("Error"), MB_OK);
//
//	LocalFree(lpMsgBuf);
//	LocalFree(lpDisplayBuf);
//	ExitProcess(1);
//}
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
				return;
			default:
				cout << "选择错误，请重新选择：";
				cin >> c;
				break;
			}
			cout << "执行完毕请重新选择:";
			cin >> c;
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
	mysqlx::Table* t = this->cache.GetSelectTable();
	DbSet* d = dynamic_cast<DbSet*>(t);
	while (condtion)
	{
		switch (c)
		{
		case 1:
			d->Insert();
			break;
		case 2:
			d->Select();
			break;
		case 3:
			d->Update();
			break;
		case 4:
			d->Remove();
			break;
		case 5:
			;
			break;
		case 6:
			condtion = false;
			return;
		case 7:
			Console();
			break;
		default:
			cout << "输入错误，请重新输入:";
			break;
		}
		cout << "执行完成，请重新选择:";
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
	cout << "********************3.增加表格*******************" << endl;
	cout << "********************4.删除表格*******************" << endl;
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
	cache.Data_Restore();
}

void Menu::Data_Backup()
{
	cache.Backup();
}

void Menu::Console()
{
	//SECURITY_ATTRIBUTES saAttr;
	//saAttr.nLength = sizeof(SECURITY_ATTRIBUTES);
	//saAttr.bInheritHandle = TRUE;
	//saAttr.lpSecurityDescriptor = NULL;
	//if (!CreatePipe(&g_hChildStd_OUT_Rd, &g_hChildStd_OUT_Wr, &saAttr, 0))
	//	ErrorExit(PTSTR("StdoutRd CreatePipe"));
	//STARTUPINFO siInfo;
	//PROCESS_INFORMATION piInfo;
	//BOOL bSuccess = FALSE;
	//ZeroMemory(&piInfo, sizeof(PROCESS_INFORMATION));
	//ZeroMemory(&siInfo, sizeof(STARTUPINFO));
	//siInfo.cb = sizeof(STARTUPINFO);
	//siInfo.hStdError = g_hChildStd_OUT_Wr;
	//siInfo.hStdOutput = g_hChildStd_OUT_Wr;
	//siInfo.hStdInput = g_hChildStd_IN_Rd;
	//siInfo.dwFlags |= SW_HIDE;
	//try
	//{
	//	
	//	/*WinExec("C:\Program Files\MySQL\MySQL Shell 8.0\bin\mysqlsh.exe", SW_HIDE);*/
	//	bSuccess=CreateProcess(TEXT("C:\Program Files\MySQL\MySQL Shell 8.0\bin\mysqlsh.exe"),
	//		NULL,// command line 
	//		NULL,// process security attributes
	//		NULL,// primary thread security attributes 
	//		TRUE,// handles are inherited 
	//		0,   // creation flags 
	//		NULL,// use parent's environment 
	//		NULL,// use parent's current directory
	//		&siInfo,// STARTUPINFO pointer
	//		&piInfo// receives PROCESS_INFORMATION 
	//	    );
	//	if(!bSuccess)
	//		ErrorExit(PTSTR("CreateProcess"));
	//	else
	//	{
	//		// Close handles to the child process and its primary thread.
	//		// Some applications might keep these handles to monitor the status
	//		// of the child process, for example. 

	//		CloseHandle(piInfo.hProcess);
	//		CloseHandle(piInfo.hThread);

	//		// Close handles to the stdin and stdout pipes no longer needed by the child process.
	//		// If they are not explicitly closed, there is no way to recognize that the child process has ended.

	//		CloseHandle(g_hChildStd_OUT_Wr);
	//		CloseHandle(g_hChildStd_IN_Rd);
	//	}
	//}
	//catch(exception& e)
	//{
	//	cout << e.what() << endl;
	//}
}

void Menu::Apply()
{
}

void Menu::Data_Maintenance()
{
}

void Menu::Data_Migrate()//数据迁移
{
}


void Menu::Add()//增加表格
{
	string name;
	cout << "请输入新建表格名字:";
	cin >> name;
	cache.AddTable(name);
}

void Menu::Delete()//删除表格
{
	string name;
	cout << "请输入删除表格名字:";
	cin >> name;
	this->cache.DeleteTable(name);
}

Menu::~Menu()
{
	cout << "退出程序" << endl;
}
