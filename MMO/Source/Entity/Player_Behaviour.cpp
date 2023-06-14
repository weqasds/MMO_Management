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
	// TODO: �ڴ˴����� return ���
	cout << "���������id��";
	input >> player_behaviour.player_id;
	cout << endl;
	cout << "��������Ϊ���ͣ�";
	input >> player_behaviour.behavior_type;
	cout << endl;
	cout << "��������Ϊʱ�䣺";
	input >> player_behaviour.behavior_time;
	cout << endl;
	cout << "��������Ϊ���飺";
	input >> player_behaviour.behavior_detail;
	cout << endl;
	return input;
}

ostream& operator<<(ostream& output, const Player_Behaviour& player_behaviour)
{
	// TODO: �ڴ˴����� return ���
	cout << "���id:" << player_behaviour.player_id << "��Ϊ����:" << player_behaviour.behavior_type << endl
		<< "��Ϊʱ��:" << player_behaviour.behavior_time << "��Ϊ��ϸ��Ϣ:" << player_behaviour.behavior_detail << endl;
	return output;
}
