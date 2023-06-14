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
	/*virtual bool operator==(const Entity& t) override;*/

	//get&set
	void SetPlayerId(string playerid) { player_id = playerid; }
	string GetCharacterId() { return character_id; }
	void SetCharacterId(string characterid) { character_id = characterid; }
	Sex GetGender() { return gender; }
	int GetExp() { return exp; }
	string GetProfession() { return profession; }
	int GetHp() { return hp; }
	int GetAttack() { return attack; }
	int GetDef() { return def; }
	float GetPhysicalResist() { return physical_resist; }
	string GetEquipName() { return equip_name; }
	string GetEquipId() { return equip_id; }
	string GetBagId() { return bag_id; }
	//构造函数
	Character();
	Character(const mysqlx::Row& row);
	//运算符重载
	friend istream& operator>>(istream& input, Character& character);
	friend ostream& operator<<(ostream& outpou, const Character& character);
private:
	string player_id;
	string character_id;
	Sex gender = Sex::Male;
	int exp;
	string profession;
	int hp;
	int attack;
	int def;
	float physical_resist;
	string equip_name;
	string equip_id;
	string bag_id;
};

