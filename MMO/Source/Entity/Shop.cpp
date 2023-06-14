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
	// TODO: �ڴ˴����� return ���
	cout << "��������Ʒid��";
	input >> shop.item_id;
	cout << endl;
	cout << "��������Ʒ���ƣ�";
	input >> shop.item_name;
	cout << endl;
	cout << "��������Ʒ������";
	input >> shop.item_description;
	cout << endl;
	cout << "��������Ʒʣ��������";
	input >> shop.item_num;
	cout << endl;
	cout << "��������Ʒ�۸�";
	input >> shop.item_cost;
	cout << endl;
	return input;
}

ostream& operator<<(ostream& output, const Shop& shop)
{
	// TODO: �ڴ˴����� return ���
	output << "��Ʒid:" << shop.item_id << "��Ʒ����:" << shop.item_name << "��Ʒ����:" << shop.item_description << endl
		<< "��Ʒ����:" << shop.item_num << "��Ʒ����:" << shop.item_cost << endl;
	return output;
}
