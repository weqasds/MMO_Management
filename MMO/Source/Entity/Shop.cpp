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
}
