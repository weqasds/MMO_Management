#pragma once
#include"..\..\pch.h"
#include"..\ORM\Define.h"
class Bag:public Entity
{
	ORMAP("Bag", bag_id, capacity, bag_data);
public:
	// ͨ�� Entity �̳�
	virtual string Get_Id() override;
	virtual void To_String() override;
	virtual bool Equal(const Entity& t) override;
	virtual int Get_HashCode() override;
	virtual bool operator==(const Entity& t) override;

	//���캯��
	Bag();
	Bag(string, int, string);
private:
	string bag_id;
	int capacity = 10;
	string bag_data;
};

