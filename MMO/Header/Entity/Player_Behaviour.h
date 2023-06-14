#pragma once
#include "..\..\pch.h"
class Player_Behaviour : public Entity
{
public:
	// ͨ�� Entity �̳�
	virtual string Get_Id() override;
	virtual void To_String() override;
	virtual bool Equal(const Entity& t) override;
	virtual int Get_HashCode() override;
	/*virtual bool operator==(const Entity& t) override;*/

	//get&set
	void SetPlayerId(string playerid) { player_id = playerid; }
	int GetBehaviorType() { return behavior_type; }
	string GetBehaviorTime() { return behavior_time; }
	string GetBehaviorDetail() { return behavior_detail; }

	//���캯��
	Player_Behaviour();
	Player_Behaviour(mysqlx::Row& row);
	//����������
	friend istream& operator>>(istream& input, Player_Behaviour& player_behaviour);
	friend ostream& operator<<(ostream& outpou, const Player_Behaviour& player_behaviour);
private:
	string player_id;
	int behavior_type;
	string behavior_time;
	string behavior_detail;
};

