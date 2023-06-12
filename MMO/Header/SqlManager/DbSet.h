#pragma once
#include"..\..\pch.h"
class DbSet :public mysqlx::Table
{
public:
	DbSet(mysqlx::Table& t);
	DbSet(mysqlx::Table& t,int type);
	void Insert();
	void Select();
	void Update();
	void Remove();
	
private:
	int name_type;
};

