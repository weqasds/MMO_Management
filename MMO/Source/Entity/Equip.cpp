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
    // TODO: �ڴ˴����� return ���
    cout << "������װ��id��";
    input >> equip.equip_id;
    cout << endl;
    cout << "������װ�����ƣ�";
    input >> equip.equip_name;
    cout << endl;
    cout << "������װ�����ͣ�";
    input >> equip.equip_type;
    cout << endl;
    cout << "������װ�����ӵ�����ֵ";
    input >> equip.hp;
    cout << endl;
    cout << "������װ�����ӵĹ���ֵ";
    input >> equip.attack;
    cout << endl;
    cout << "������װ�����ӵķ���ֵ";
    input >> equip.def;
    cout << endl;
    cout << "������װ�����ӵ�������ֵ";
    input >> equip.phys_resist;
    cout << endl;
}
