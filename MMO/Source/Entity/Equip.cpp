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
    // TODO: �ڴ˴����� return ���
    cout << "������װ��id:";
    input >> equip.equip_id;
    cout << endl;
    cout << "������װ������:";
    input >> equip.equip_name;
    cout << endl;
    cout << "������װ������:";
    input >> equip.equip_type;
    cout << endl;
    cout << "������װ�����ӵ�����ֵ:";
    input >> equip.hp;
    cout << endl;
    cout << "������װ�����ӵĹ���ֵ:";
    input >> equip.attack;
    cout << endl;
    cout << "������װ�����ӵķ���ֵ:";
    input >> equip.def;
    cout << endl;
    cout << "������װ�����ӵ�������ֵ:";
    input >> equip.phys_resist;
    cout << endl;
    return input;
}

ostream& operator<<(ostream& output, const Equip& equip)
{
    // TODO: �ڴ˴����� return ���
    cout << "װ��id:" << equip.equip_id << " װ������:" << equip.equip_name << " װ������:" << equip.equip_type << endl;
    cout << "װ�����ӵ�����ֵ:" << equip.hp << " װ�����ӵĹ���ֵ:" << equip.attack << " װ�����ӵķ���ֵ:" << equip.def << " װ�����ӵ�������ֵ:" << equip.phys_resist << endl;
    return output;
}
