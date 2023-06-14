#pragma once
#include"..\..\pch.h"
class Bag:public Entity
{
public:
	// 通过 Entity 继承
	virtual string Get_Id() override;
	virtual void To_String() override;
	virtual bool Equal(const Entity& t) override;
	virtual int Get_HashCode() override;
	/*virtual bool operator==(const Entity& t) override;*/

	//get&set
	void SetId(string id){ 
		bag_id = id;
	}
	int GetCapacity() { return capacity; }
	void SetCapacity(int c) { capacity = c; }

	//构造函数
	Bag();
	Bag(string id, int c, string data);
	Bag(const mysqlx::Row& row);

	//运算符重载
	friend istream& operator>>(istream& input, Bag& bag);
	friend ostream& operator<<(ostream& output, Bag& bag);
	bool operator==(const Bag& t) const;
private:
	string bag_id;
	int capacity = 10;
	string bag_data;
};

