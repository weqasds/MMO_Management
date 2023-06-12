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
	if (pos != string::npos) { // 如果找到了&符号
		this->rootpwd = coonstr.substr(pos + 10); // 从该位置开始截取到最后一个&符号的位置
		cout << "Password: " << rootpwd << endl; // 输出password字符串
	}
	else {
		cout << "No password found." << endl; // 没有找到password字符串
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
