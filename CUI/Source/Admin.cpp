#include "..\pch.h"

string Admin::Get_Id()
{
	return string();
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

bool Admin::operator==(const Entity& t)
{
	return false;
}

Admin::Admin()
{
}
Admin::Admin(string id, string account, string pwd, Level level) 
{

}
