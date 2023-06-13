#include "..\..\pch.h"
istream& operator>>(istream& input,Admin& admin)
{
	cout << "ÇëÊäÈëÕËºÅ£º";
	input >> admin.admin_account;
	cout << "ÇëÊäÈëÕË»§ÃÜÂë£º";
	input >> admin.admin_password;
	return input;
}

ostream& operator<<(ostream& output, Admin& admin)
{
	// TODO: ÔÚ´Ë´¦²åÈë return Óï¾ä
	return output;
}

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

Level Admin::Get_Level()
{
	return this->admin_level;
}

void Admin::Set_Level(Level level)
{
	this->admin_level = level;
}


Admin::operator bool()
{
	if(true)
		return true;
	return false;
}

Admin::Admin()
{
}
Admin::Admin(string id, string account, string pwd, Level level)
{

}

Admin::Admin(const mysqlx::Row& row)
{
	this->admin_id = row[0].get<string>();
	this->admin_account = row[1].get<string>();
	this->admin_password = row[2].get<string>();
	this->admin_level = static_cast<Level>(row[3].get<int>());
}

