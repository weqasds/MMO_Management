#pragma once
#include"..\..\pch.h"
class ORM
{
public:
	//���캯��&��������
	ORM(string coonstr,bool t);
	template<typename Arg,typename ...T>
	ORM(Arg arg,T...option);
	~ORM();
	//���ܺ���
	void Backup();//����
	void Data_Restore();//�ָ�
	void AddTable(string name);//���ӱ�
	void DeleteTable(string name);//ɾ����
	//get set����
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

