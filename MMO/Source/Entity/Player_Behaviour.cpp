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

}
