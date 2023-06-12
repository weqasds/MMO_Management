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

bool Shop::operator==(const Entity& t)
{
	return false;
}

Shop::Shop()
{
	item_description = 0;
	item_num = 0;
	item_cost = 0;
}

istream& operator>>(istream& input, Shop& shop)
{
	// TODO: 在此处插入 return 语句
	cout << "请输入物品id：";
	input >> shop.item_id;
	cout << endl;
	cout << "请输入物品名称：";
	input >> shop.item_name;
	cout << endl;
	cout << "请输入物品描述：";
	input >> shop.item_description;
	cout << endl;
	cout << "请输入物品剩余数量：";
	input >> shop.item_num;
	cout << endl;
	cout << "请输入物品价格：";
	input >> shop.item_cost;
	cout << endl;
}
