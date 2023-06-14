#include "..\..\pch.h"

string Player::Get_Id()
{
	return player_id;
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

Player::Player(mysqlx::Row& row)
{
	this->player_id = row[0].get<string>();
	this->character_id = row[1].get<string>();
	this->account = row[2].get<string>();
	this->nickname = row[3].get<string>();
	this->gender = static_cast<Sex>(row[4].get<int>());
	this->age = row[5].get<int>();
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
	/*input >> player.gender;*/
	cout << endl;
	cout << "������������䣺";
	input >> player.age;
	cout << endl;
	return input;
}

ostream& operator<<(ostream& output, Player& player)
{
	// TODO: �ڴ˴����� return ���
	output << "���id:" << player.player_id << " ��ɫid:" << player.character_id << endl 
		   << "����˺�:" << player.account << " ����ǳ�:" << player.nickname << "����Ա�:" << player.gender <<" �������:" << player.age << endl;
	return output;
}
