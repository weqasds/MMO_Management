#include "..\..\pch.h"

string Player::Get_Id()
{
	return string();
}

void Player::To_String()
{
}

bool Player::Equal(const Entity& t)
{
	return false;
}

int Player::Get_HashCode()
{
	return 0;
}


Player::Player()
{

}

istream& operator>>(istream& input, Player& player)
{
	// TODO: �ڴ˴����� return ���
	cout << "���������id��";
	input >> player.player_id;
	cout << endl;
	cout << "�������ɫid��";
	input >> player.character_id;
	cout << endl;
	cout << "����������˺ţ�";
	input >> player.account;
	cout << endl;
	cout << "�������ǳƣ�";
	input >> player.nickname;
	cout << endl;
	cout << "����������Ա�";
	input >> player.gender;
	cout << endl;
	cout << "������������䣺";
	input >> player.age;
	cout << endl;
}
