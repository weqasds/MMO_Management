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
// TODO: �ڴ˴����� return ���istream& operator>>(istream& input,Admin& admin)
	cout << "�������ɫid��";
	input >> character.character_id;
	cout << endl;
	cout << "�������ɫ�Ա�";
	/*input >> character.gender;*/
	cout << endl;
	cout << "�������ɫְҵ��";
	input >> character.profession;
	cout << endl;
	cout << "�������ɫ����ֵ��";
	input >> character.hp;
	cout << endl;
	cout << "�������ɫ����ֵ��";
	input >> character.attack;
	cout << endl;
	cout << "�������ɫ����ֵ��";
	input >> character.defense;
	cout << endl;
	cout << "�������ɫ������ֵ��";
	input >> character.physical_resist;
	cout << endl;
	return input;
}

ostream& operator<<(ostream& output, const Character& character)
{
	// TODO: �ڴ˴����� return ���
	output << "��ɫ��Ϣ����:" << endl;
	output << "��ɫid:" << character.character_id << " ���id" << character.player_id <<
		" ��ɫ�Ա�:" << character.gender << " ��ɫ����ֵ:" << character.exp << endl;
	output << "��ɫְҵ:" << character.profession << "" << endl;
	output << "��ɫѪ��:" << character.hp << " ��ɫ������:" << character.attack << "��ɫ������" << character.defense <<
		" ��ɫ������:" << character.physical_resist << endl;
	output << "��ɫװ��id:" << character.equip_id << "��ɫװ������:" << character.equip_name << endl;
	output << "��ɫ����id:" << character.bag_id << endl;
}
