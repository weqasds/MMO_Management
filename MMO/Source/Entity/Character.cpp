#include "..\..\pch.h"
string Character::Get_Id()
{
	return this->player_id;
}

void Character::To_String()
{
}

bool Character::Equal(const Entity& t)
{
	return false;
}

int Character::Get_HashCode()
{
	return 0;
}

Character::Character()
{
}

Character::Character(const mysqlx::Row& row)
{
	this->player_id = row[0].get<string>();
	this->character_id = row[1].get<string>();
	this->gender = static_cast<Sex>(row[2].get<int>());
	this->exp = row[3].get<int>();
	this->profession = row[4].get<string>();
	this->hp = row[5].get<int>();
	this->attack = row[6].get<int>();
	this->def = row[7].get<int>();
	this->physical_resist = row[8].get<float>();
	this->equip_name = row[9].get<string>();
	this->equip_id = row[10].get<string>();
	this->bag_id = row[11].get<string>();
}

istream& operator>>(istream& input, Character& character)
{
// TODO: 在此处插入 return 语句istream& operator>>(istream& input,Admin& admin)
	cout << "请输入角色id：";
	input >> character.character_id;
	cout << endl;
	cout << "请输入角色性别：";
	/*input >> character.gender;*/
	cout << endl;
	cout << "请输入角色职业：";
	input >> character.profession;
	cout << endl;
	cout << "请输入角色生命值：";
	input >> character.hp;
	cout << endl;
	cout << "请输入角色攻击值：";
	input >> character.attack;
	cout << endl;
	cout << "请输入角色防御值：";
	input >> character.defense;
	cout << endl;
	cout << "请输入角色物理抗性值：";
	input >> character.physical_resist;
	cout << endl;
	return input;
}

ostream& operator<<(ostream& output, const Character& character)
{
	// TODO: 在此处插入 return 语句
	output << "角色信息如下:" << endl;
	output << "角色id:" << character.character_id << " 玩家id" << character.player_id <<
		" 角色性别:" << character.gender << " 角色经验值:" << character.exp << endl;
	output << "角色职业:" << character.profession << "" << endl;
	output << "角色血量:" << character.hp << " 角色攻击力:" << character.attack << "角色防御力" << character.defense <<
		" 角色物理抗性:" << character.physical_resist << endl;
	output << "角色装备id:" << character.equip_id << "角色装备名称:" << character.equip_name << endl;
	output << "角色背包id:" << character.bag_id << endl;
}
