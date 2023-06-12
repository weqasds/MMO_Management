#include "..\..\pch.h"

string Shop::Get_Id()
{
	return string();
}

void Shop::To_String()
{
}

bool Shop::Equal(const Entity& t)
{
	return false;
}

int Shop::Get_HashCode()
{
	return 0;
}


Shop::Shop()
{
	item_description = 0;
	item_num = 0;
	item_cost = 0;
}