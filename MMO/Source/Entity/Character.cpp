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

// TODO: �ڴ˴����� return ���istream& operator>>(istream& input,Admin& admin)
{
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
