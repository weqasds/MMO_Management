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
	// TODO: 在此处插入 return 语句
	cout << "请输入玩家id：";
	input >> player.player_id;
	cout << endl;
	cout << "请输入角色id：";
	input >> player.character_id;
	cout << endl;
	cout << "请输入玩家账号：";
	input >> player.account;
	cout << endl;
	cout << "请输入昵称：";
	input >> player.nickname;
	cout << endl;
	cout << "请输入玩家性别：";
	input >> player.gender;
	cout << endl;
	cout << "请输入玩家年龄：";
	input >> player.age;
	cout << endl;
}
