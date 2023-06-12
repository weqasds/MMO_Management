#include "..\..\pch.h"

string Player_Behaviour::Get_Id()
{
	return string();
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

}
