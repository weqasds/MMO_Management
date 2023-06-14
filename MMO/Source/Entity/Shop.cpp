#include "..\..\pch.h"

string Shop::Get_Id()
{
	return item_id;
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

Shop::Shop(mysqlx::Row& row)
{
	this->item_id=row[0].get<string>();
	this->item_name=row[1].get<string>();
	this->item_num=row[2].get<int>();
	this->item_cost=row[3].get<int>();
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
	return input;
}

ostream& operator<<(ostream& output, const Shop& shop)
{
	// TODO: 在此处插入 return 语句
	output << "物品id:" << shop.item_id << "物品名称:" << shop.item_name << "物品描述:" << shop.item_description << endl
		<< "物品数量:" << shop.item_num << "物品花费:" << shop.item_cost << endl;
	return output;
}
