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
	/*input >> player.gender;*/
	cout << endl;
	cout << "请输入玩家年龄：";
	input >> player.age;
	cout << endl;
	return input;
}

ostream& operator<<(ostream& output, Player& player)
{
	// TODO: 在此处插入 return 语句
	output << "玩家id:" << player.player_id << " 角色id:" << player.character_id << endl 
		   << "玩家账号:" << player.account << " 玩家昵称:" << player.nickname << "玩家性别:" << player.gender <<" 玩家年龄:" << player.age << endl;
	return output;
}
