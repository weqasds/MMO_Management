#pragma once
#include "..\..\pch.h"
class Shop : public Entity
{
public:

	// 通过 Entity 继承
	virtual string Get_Id() override;
	virtual void To_String() override;
	virtual bool Equal(const Entity& t) override;
	virtual int Get_HashCode() override;
	/*virtual bool operator==(const Entity& t) override;*/

	//构造函数
	Shop();
private:

	string item_id;
	string item_name;
	int item_description;
	int item_num;
	int item_cost;
};

