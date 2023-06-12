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
	// ͨ�� Entity �̳�
	virtual string Get_Id() override;
	virtual void To_String() override;
	virtual bool Equal(const Entity& t) override;
	virtual int Get_HashCode() override;
	/*virtual bool operator==(const Entity& t) override;*/

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
	int defense;
	float physical_resist;
	string equip_name;
	string equip_id;
	string bag_id;
	string hash_id;
	//���������
	friend istream& operator>>(istream& input, Character& character);
	friend ostream& operator<<(ostream& outpou, Character& character);
};

