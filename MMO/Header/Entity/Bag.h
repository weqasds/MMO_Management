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

	//构造函数
	Bag();
	Bag(string, int, string);
private:
	string bag_id;
	int capacity = 10;
	string bag_data;
};

