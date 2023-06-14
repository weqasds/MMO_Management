#include "..\..\pch.h"

string Player_Behaviour::Get_Id()
{
	return player_id;
}

void Player_Behaviour::To_String()
{
}

bool Player_Behaviour::Equal(const Entity& t)
{
	return false;
}

int Player_Behaviour::Get_HashCode()
{
	return 0;
}

Player_Behaviour::Player_Behaviour()
{
}

Player_Behaviour::Player_Behaviour(mysqlx::Row& row)
{
	this->player_id=row[0].get<string>();
	this->behavior_type=row[1].get<int>();
	time_t temptime = row[2].get<int>();
	char time_buffer[80];
	this->behavior_time= strftime(time_buffer, 80, "%Y-%m-%d %H:%M:%S",localtime(&temptime));
	this->behavior_detail=row[3].get<string>();
}

istream& operator>>(istream& input, Player_Behaviour& player_behaviour)
{
	// TODO: 在此处插入 return 语句
	cout << "请输入玩家id：";
	input >> player_behaviour.player_id;
	cout << endl;
	cout << "请输入行为类型：";
	input >> player_behaviour.behavior_type;
	cout << endl;
	cout << "请输入行为时间：";
	input >> player_behaviour.behavior_time;
	cout << endl;
	cout << "请输入行为详情：";
	input >> player_behaviour.behavior_detail;
	cout << endl;
	return input;
}

ostream& operator<<(ostream& output, const Player_Behaviour& player_behaviour)
{
	// TODO: 在此处插入 return 语句
	cout << "玩家id:" << player_behaviour.player_id << "行为类型:" << player_behaviour.behavior_type << endl
		<< "行为时间:" << player_behaviour.behavior_time << "行为详细信息:" << player_behaviour.behavior_detail << endl;
	return output;
}
