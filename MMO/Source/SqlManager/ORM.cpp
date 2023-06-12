#include "..\..\pch.h"

//  mysqlx://localhost:33060/test?user=user&password=password
ORM::ORM(string coonstr,bool t):
	coon(new mysqlx::Session(coonstr)),
	SelectDb(this->coon->getSchema("game", true))
{
	this->dbs = this->coon->getSchemas();

	for (mysqlx::Table table : SelectDb.getTables())
	{
		mysqlx::Table* ntable = new DbSet(table);
		/*((DbSet*)ntable)*/
		this->tables.push_back(ntable);
	}
	this->SelectTable = nullptr;
	int pos=coonstr.find("&");
	if (pos != string::npos) { // ����ҵ���&����
		this->rootpwd = coonstr.substr(pos + 10); // �Ӹ�λ�ÿ�ʼ��ȡ�����һ��&���ŵ�λ��
		cout << "Password: " << rootpwd << endl; // ���password�ַ���
	}
	else {
		cout << "No password found." << endl; // û���ҵ�password�ַ���
		exit(1);
	}
}
template<typename Arg, typename ...T>
ORM::ORM(Arg arg,T...option):
	coon(new mysqlx::Session()),
	SelectDb(this->coon->getSchema("game", true))
{
	this->dbs = this->coon->getSchemas();
	
	for (mysqlx::Table table : SelectDb.getTables())
	{
		mysqlx::Table* ntable = new DbSet(table);
		this->tables.push_back(ntable);
	}
	this->SelectTable = nullptr;
}

ORM::~ORM()
{
	if (!(SelectTable == nullptr))
		delete SelectTable;
	delete coon;
	for (mysqlx::Table* table : tables)
	{
		delete table;
	}
}

void ORM::Backup()
{
}

void ORM::Data_Restore()
{
}

void ORM::AddTable(string name)
{
}

void ORM::DeleteTable(string name)
{
}
