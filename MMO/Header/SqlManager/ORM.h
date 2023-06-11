#pragma once
#include"..\..\pch.h"
class ORM
{
public:
	ORM();
	ORM(string coonstr);
	
	ORM(mysqlx::Session coon);
	~ORM();
	void Backup();
	void Data_Restore();
	void Console();
	void AddTable(string name);
	void DeleteTable(string name);

	mysqlx::Table* GetSelectTable() {
		return this->SelectTable;
	}
	mysqlx::Schema* GetSeelectDb() {
		return this->SelectDb;
	}
	list<mysqlx::Schema*>* GetAllDbs() {
		return &(this->dbs);
	}
	list<mysqlx::Table*>* GetAllTables() {
		return &(this->tables);
	}

private:
	mysqlx::Schema* SelectDb;
	mysqlx::Table* SelectTable;
	list<mysqlx::Schema*> dbs;
	list<mysqlx::Table*> tables;
	mysqlx::Session* coon;
	string rootpwd;
};
