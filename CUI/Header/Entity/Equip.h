#pragma once
#include"..\..\pch.h"
#include"..\ORM\Define.h"
class Equip : public Entity
{
	ORMAP("Equip", equip_id, equip_name, hp, attack, def, phys_resist);
public:
	// ͨ�� Entity �̳�
	virtual string Get_Id() override;
	virtual void To_String() override;
	virtual bool Equal(const Entity& t) override;
	virtual int Get_HashCode() override;
	virtual bool operator==(const Entity& t) override;

	//���캯��
	Equip();
private:
	string equip_id;
	string equip_name;
	string equip_type;
	int hp, attack, def;
	float phys_resist;
};

