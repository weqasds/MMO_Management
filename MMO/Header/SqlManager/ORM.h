#pragma once
#include"..\..\pch.h"
class ORM
{
public:
	ORM();
	ORM(string coonstr);
	
	ORM(mysqlx::Session coon);
	
	void Backup();
	void Data_Restore();
	void Console();
	void AddTable(string name);
	void DeleteTable(string name);
private:
	mysqlx::Schema SelectDb;
	mysqlx::Table* SelectTable;
	list<mysqlx::Schema*> dbs;
	list<mysqlx::Table*> tables;
	mysqlx::Session* coon;
	string rootpwd;
};

