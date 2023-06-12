#pragma once
#include"..\..\pch.h"
class DbSet : mysqlx::Table
{
public:
	void Insert();
	void Select();
	void Update();
	void Remove();
private:
	string name;
};

