#pragma once
#include"..\..\pch.h"
enum Level
{
	lowlest,
	normal,
	highest
};
class Admin : public Entity
{
public:
	// 通过 Entity 继承
	virtual string Get_Id() override;
	virtual void To_String() override;
	virtual bool Equal(const Entity& t) override;
	virtual int Get_HashCode() override;
	/*virtual bool operator==(const Entity& t) override;*/

	//get&set
	Level Get_Level();
	void Set_Level(Level level);

	operator bool();
	//构造函数
	Admin();
	Admin(string, string, string, Level);
	Admin(const mysqlx::Row& row);
	//运算符重载
	friend istream& operator>>(istream& input,Admin& admin);

	friend ostream& operator<<(ostream& outpou,Admin& admin);
private:
	string admin_id;
	string admin_account;
	string admin_password = "123456";
	Level admin_level = Level::normal;
};

