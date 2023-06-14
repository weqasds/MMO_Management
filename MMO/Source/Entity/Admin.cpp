#include "..\..\pch.h"
//重写基类函数
string Admin::Get_Id()
{
	return this->admin_id;
}

void Admin::To_String()
{
}

bool Admin::Equal(const Entity& t)
{
	return false;
}

int Admin::Get_HashCode()
{
	return 0;
}

//get&set方法
Level Admin::Get_Level()
{
	return this->admin_level;
}

void Admin::Set_Level(Level level)
{
	this->admin_level = level;
}

//构造函数
Admin::Admin()
{
}

Admin::Admin(string id, string account, string pwd, Level level)
	:admin_id(id),admin_account(account),admin_password(pwd),admin_level(level)
{

}

Admin::Admin(const mysqlx::Row& row)
{
	this->admin_id = row[0].get<string>();
	this->admin_account = row[1].get<string>();
	this->admin_password = row[2].get<string>();
	this->admin_level = static_cast<Level>(row[3].get<int>());
}

//运算符重载
istream& operator>>(istream& input,Admin& admin)
{
	cout << "请输入账号：";
	input >> admin.admin_account;
	cout << "请输入账户密码：";
	input >> admin.admin_password;
	return input;
}

ostream& operator<<(ostream& output,const Admin& admin)
{
	// TODO: 在此处插入 return 语句
	output << "账户账号密码分别是:" << endl;
	output << "账户:" << admin.admin_account << " 密码:" << admin.admin_password << endl;
	return output;
}

bool Admin::operator==(const Admin& t) const
{
	if (this->admin_account==t.admin_account && this->admin_password==t.admin_password)
		return true;
	return false;
}

Admin::operator string()
{
	return this->admin_account;
}
