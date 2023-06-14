#pragma once
#include"..\..\pch.h"
class ORM
{
public:
	//���캯��&��������
	ORM(string coonstr,bool t);
	template<typename ...T>
	ORM(T...option);
	~ORM();
	//���ܺ���
	void Backup();//����
	void Data_Restore();//�ָ�
	void AddTable(string name);//���ӱ�
	void DeleteTable(string name);//ɾ����
	//get set����
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

