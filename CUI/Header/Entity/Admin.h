#pragma once
#include"..\..\pch.h"
enum Level
{
	lowlest,
	normal,
	highest
};
class Admin :public Entity
{
public:
	// ͨ�� Entity �̳�
	virtual string Get_Id() override;
	virtual void To_String() override;
	virtual bool Equal(const Entity& t) override;
	virtual int Get_HashCode() override;
	virtual bool operator==(const Entity& t) override;

	//���캯��
	Admin();
	Admin(string, string, string, Level);
private:
	string admin_id;
	string admin_account;
	string admin_password = "123456";
	Level admin_level = normal;
};



