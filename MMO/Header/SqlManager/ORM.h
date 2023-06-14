#pragma once
#include"..\..\pch.h"
class ORM
{
public:
	//构造函数&析构函数
	ORM(string coonstr,bool t);
	template<typename ...T>
	ORM(T...option);
	~ORM();
	//功能函数
	void Backup();//备份
	void Data_Restore();//恢复
	void AddTable(string name);//增加表
	void DeleteTable(string name);//删除表
	//get set方法
	mysqlx::Table* GetSelectTable() {
		return this->selectTable;
	}
	mysqlx::Schema GetSeelectDb() {
		return this->selectDb;
	}
	list<mysqlx::Schema>* GetAllDbs() {
		return &(this->dbs);
	}
	vector<mysqlx::Table*>* GetAllTables() {
		return &(this->tables);
	}
	Admin GetAdmin(string s) {
		return (adminSet.find(s))->second;
	}
	string GetRootPwd() { return rootpwd; }

private:
	mysqlx::Session coon;
	mysqlx::Schema selectDb;
	mysqlx::Table* selectTable;
	list<mysqlx::Schema> dbs;
	vector<mysqlx::Table*> tables;
	string rootpwd;
	map<string,Admin> adminSet;
};

