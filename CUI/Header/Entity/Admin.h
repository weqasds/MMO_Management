#pragma once
#include"..\..\pch.h"
#include"..\ORM\Define.h"
enum Level
{
	lowlest,
	normal,
	highest
};
class Admin :public Entity
{
	ORMAP("Admin", admin_id, admin_account, admin_password, admin_level);
public:
	// 通过 Entity 继承
	virtual string Get_Id() override;
	virtual void To_String() override;
	virtual bool Equal(const Entity& t) override;
	virtual int Get_HashCode() override;
	virtual bool operator==(const Entity& t) override;

	//构造函数
	Admin();
	Admin(string, string, string, Level);
private:
	string admin_id;
	string admin_account;
	string admin_password = "123456";
	Level admin_level = Level::normal;
};



