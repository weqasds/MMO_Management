#include "..\..\pch.h"

string Equip::Get_Id()
{
    return string();
}

void Equip::To_String()
{
}

bool Equip::Equal(const Entity& t)
{
    return false;
}

int Equip::Get_HashCode()
{
    return 0;
}

bool Equip::operator==(const Entity& t)
{
    return false;
}

Equip::Equip()
{
}

istream& operator>>(istream& input, Equip& equip)
{
    // TODO: 在此处插入 return 语句
    cout << "请输入装备id：";
    input >> equip.equip_id;
    cout << endl;
    cout << "请输入装备名称：";
    input >> equip.equip_name;
    cout << endl;
    cout << "请输入装备类型：";
    input >> equip.equip_type;
    cout << endl;
    cout << "请输入装备增加的生命值";
    input >> equip.hp;
    cout << endl;
    cout << "请输入装备增加的攻击值";
    input >> equip.attack;
    cout << endl;
    cout << "请输入装备增加的防御值";
    input >> equip.def;
    cout << endl;
    cout << "请输入装备增加的物理抗性值";
    input >> equip.phys_resist;
    cout << endl;
}
