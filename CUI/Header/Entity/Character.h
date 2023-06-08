#pragma once
#include"..\..\pch.h"
enum Sex
{
	Male,
	FeMale
};
class Character : public Entity
{
public:
	// 通过 Entity 继承
	virtual string Get_Id() override;
	virtual void To_String() override;
	virtual bool Equal(const Entity& t) override;
	virtual int Get_HashCode() override;
	virtual bool operator==(const Entity& t) override;

	//构造函数
	Character();
private:
	string player_id;
	string character_id;
	Sex gender = Male;
	int exp;
	string profession;
	int hp;
	int attack;
	float physical_resist;
	string equip_name;
	string equip_id;
	string bag_id;
	string hash_id;
};

