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

void Menu::Login()//��¼
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

void Menu::Main_Menu()//���˵�
{
	int c;
	bool condtion = true;
	cout << endl;
	cout << "************************************************" << endl;
	cout << "*********************���˵�**********************" << endl;
	cout << "******************1���ݲ��ݹ���*******************" << endl;
	cout << "******************2���ݱ��ݻ�ԭ*******************" << endl;
	cout << "*******************3����̨ʹ��********************" << endl;
	cout << "********************4����Ȩ��*********************" << endl;
	cout << "********************5�߼�����*********************" << endl;
	cout << "********************6�˳���¼*********************" << endl;
	cout << "************************************************" << endl;
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
			case 4:
				Apply();
				break;
			case 5:Advanced_Menu();
				break;
			case 6:
				condtion = false;
				return;
			default:
				cout << "ѡ�����������ѡ��";
				cin >> c;
				break;
			}
			cout << "ִ�����������ѡ��:";
			cin >> c;
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
	bool condtion = true;
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
			cout << "�����������������:";
			break;
		}
		cout << "ִ����ɣ�������ѡ��:";
		cin >> c;
	}
}

void Menu::Data_RB_Menu()
{
	int c;
	bool condtion = true;
	cout << endl;
	cout << "*************************************************" << endl;
	cout << "*********************�����˵�**********************" << endl;
	cout << "*********************1.��������********************" << endl;
	cout << "*********************2.��ԭ����********************" << endl;
	cout << "*********************3.������һ���˵�***************" << endl;
	cout << "*************************************************" << endl;
	cout << "��ѡ��:";
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
			cout << "�����������������:";
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
	cout << "********************�߼��˵�*********************" << endl;
	cout << "********************1.����Ǩ��*******************" << endl;
	cout << "********************2.����ά��*******************" << endl;
	cout << "********************3.���ӱ��*******************" << endl;
	cout << "********************4.ɾ�����*******************" << endl;
	cout << "********************5.����̨*********************" << endl;
	cout << "********************6.������һ���˵�**************" << endl;
	cout << "************************************************" << endl;
	cout << endl;
	cout << "��ѡ����:";
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
			cout << "�����������������:";
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

void Menu::Data_Migrate()//����Ǩ��
{
}


void Menu::Add()//���ӱ��
{
	string name;
	cout << "�������½��������:";
	cin >> name;
	cache.AddTable(name);
}

void Menu::Delete()//ɾ�����
{
	string name;
	cout << "������ɾ���������:";
	cin >> name;
	this->cache.DeleteTable(name);
}

Menu::~Menu()
{
	cout << "�˳�����" << endl;
}
