#pragma once
#include "..\..\pch.h"
class Player_Behaviour : public Entity
{
public:
	// 通过 Entity 继承
	virtual string Get_Id() override;
	virtual void To_String() override;
	virtual bool Equal(const Entity& t) override;
	virtual int Get_HashCode() override;
	virtual bool operator==(const Entity& t) override;

	//构造函数
	Player_Behaviour();
private:
	string player_id;
	int behavior_type;
	string behavior_time;
	string behavior_detail;
};

