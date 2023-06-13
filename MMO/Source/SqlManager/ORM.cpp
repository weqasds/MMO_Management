#include "..\..\pch.h"

//  mysqlx://localhost:33060/test?user=user&password=password
ORM::ORM(string coonstr,bool t):
	coon(coonstr),
	selectDb(coon.getSchema("game",true))
{
	/*cout << SelectDb.getName();*/
	this->dbs = this->coon.getSchemas();
	auto list = selectDb.getTables();
	for (auto table : list)
	{
		mysqlx::Table* ntable = new DbSet(table);
		/*((DbSet*)ntable)*/
		this->tables.push_back(ntable);
	}
	this->selectTable = nullptr;
	int pos=coonstr.find("root");
	if (pos != string::npos) { // 如果找到了&符号
		this->rootpwd = coonstr.substr(pos + 5,13); // 从该位置开始截取到最后一个&符号的位置
#ifdef _DEBUG
		cout << "Password: " << rootpwd << endl; // 输出password字符串
#endif
	}
	else {
		cout << "No password found." << endl; // 没有找到password字符串
		exit(1);
	}

	try
	{
		mysqlx::Table t=selectDb.getTable("admin_entity", true);
		if (t.isView())cout << "获取admin失败，请确保admin表存在或者admin不是视图" << endl;
		mysqlx::RowResult set=t.select("admin_id", "admin_account", "admin_password", "admin_level")
			                   .execute();
		for (auto i : set.fetchAll()) {
			adminSet.push_back(i);
		}
	}
	catch (const std::exception& e)
	{
		cout << e.what();
	}
	mysqlx::Table temp = this->selectDb.getTable("admin_entity", true);
	mysqlx::Table* tempt = new DbSet(temp);
	this->selectTable = tempt;

}
template<typename ...T>
ORM::ORM(T...option):
	coon(new mysqlx::Session()),
	selectDb(this->coon->getSchema("game", true))
{
	this->dbs = this->coon->getSchemas();
	
	for (mysqlx::Table table : selectDb.getTables())
	{
		mysqlx::Table* ntable = new DbSet(table);
		this->tables.push_back(ntable);
	}
	mysqlx::Table temp = this->selectDb.getTable("admin_entity", true);
	mysqlx::Table* tempt = new DbSet(temp);
	this->selectTable = tempt;
}

ORM::~ORM()
{
	if (!(selectTable == nullptr))
		delete selectTable;
	for (mysqlx::Table* table : tables)
	{
		delete table;
	}
	coon.close();
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
