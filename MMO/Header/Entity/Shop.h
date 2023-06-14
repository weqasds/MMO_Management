#pragma once
#include "..\..\pch.h"
class Shop : public Entity
{
public:

	// ͨ�� Entity �̳�
	virtual string Get_Id() override;
	virtual void To_String() override;
	virtual bool Equal(const Entity& t) override;
	virtual int Get_HashCode() override;
	/*virtual bool operator==(const Entity& t) override;*/

	//get&set
	void SetItemId(string id) { item_id = id; }
	string GetItemName() { return item_name; }
	int GetitemDescription() { return item_description; }
	int GetitemNum() { return item_num; }
	int GetItemCost() { return item_cost; }
	//���캯��
	Shop();
	Shop(mysqlx::Row& row);
	//����������
	friend istream& operator>>(istream& input, Shop& shop);
	friend ostream& operator<<(ostream& outpou, const Shop& shop);
private:

	string item_id;
	string item_name;
	int item_description;
	int item_num;
	int item_cost;
};

