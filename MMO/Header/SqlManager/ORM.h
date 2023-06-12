#pragma once
#include"..\..\pch.h"
class ORM
{
public:
	//构造函数&析构函数
	ORM(string coonstr,bool t);
	template<typename Arg,typename ...T>
	ORM(Arg arg,T...option);
	~ORM();
	//功能函数
	void Backup();//备份
	void Data_Restore();//恢复
	void AddTable(string name);//增加表
	void DeleteTable(string name);//删除表
	//get set方法
	mysqlx::Table* GetSelectTable() {
		return this->SelectTable;
	}
	mysqlx::Schema GetSeelectDb() {
		return this->SelectDb;
	}
	list<mysqlx::Schema>* GetAllDbs() {
		return &(this->dbs);
	}
	list<mysqlx::Table*>* GetAllTables() {
		return &(this->tables);
	}

private:
	mysqlx::Schema SelectDb;
	mysqlx::Table* SelectTable;
	list<mysqlx::Schema> dbs;
	list<mysqlx::Table*> tables;
	mysqlx::Session* coon;
	string rootpwd;
};

