#include "..\..\pch.h"

string Equip::Get_Id()
{
    return equip_id;
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


Equip::Equip()
{
}

Equip::Equip(const mysqlx::Row& row)
{
    this->equip_id=row[0].get<string>();
    this->equip_name=row[1].get<string>();
    this->equip_type=row[2].get<string>();
    this->hp=row[3].get<int>();
    this->attack=row[4].get<int>();
    this->def=row[5].get<int>();
    this->phys_resist=row[6].get<float>();
}

istream& operator>>(istream& input, Equip& equip)
{
    // TODO: 在此处插入 return 语句
    cout << "请输入装备id:";
    input >> equip.equip_id;
    cout << endl;
    cout << "请输入装备名称:";
    input >> equip.equip_name;
    cout << endl;
    cout << "请输入装备类型:";
    input >> equip.equip_type;
    cout << endl;
    cout << "请输入装备增加的生命值:";
    input >> equip.hp;
    cout << endl;
    cout << "请输入装备增加的攻击值:";
    input >> equip.attack;
    cout << endl;
    cout << "请输入装备增加的防御值:";
    input >> equip.def;
    cout << endl;
    cout << "请输入装备增加的物理抗性值:";
    input >> equip.phys_resist;
    cout << endl;
    return input;
}

ostream& operator<<(ostream& output, const Equip& equip)
{
    // TODO: 在此处插入 return 语句
    cout << "装备id:" << equip.equip_id << " 装备名称:" << equip.equip_name << " 装备类型:" << equip.equip_type << endl;
    cout << "装备增加的生命值:" << equip.hp << " 装备增加的攻击值:" << equip.attack << " 装备增加的防御值:" << equip.def << " 装备增加的物理抗性值:" << equip.phys_resist << endl;
    return output;
}
