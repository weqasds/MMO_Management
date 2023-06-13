#include "..\..\pch.h"
string Character::Get_Id()
{
	return string();
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

istream& operator>>(istream& input, Character& character)

// TODO: 在此处插入 return 语句istream& operator>>(istream& input,Admin& admin)
{
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
