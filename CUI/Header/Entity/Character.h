#pragma once
#include"..\..\pch.h"
#include"..\ORM\Define.h"
enum Sex
{
	Male,
	FeMale
};
class Character : public Entity
{
	ORMAP("Character", player_id, character_id, gender, exp, profession, hp, attack, physical_resist, equip_name, equip_id, bag_id, hash_id);
public:
	// ͨ�� Entity �̳�
	virtual string Get_Id() override;
	virtual void To_String() override;
	virtual bool Equal(const Entity& t) override;
	virtual int Get_HashCode() override;
	virtual bool operator==(const Entity& t) override;

	//���캯��
	Character();
private:
	string player_id;
	string character_id;
	Sex gender = Sex::Male;
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

