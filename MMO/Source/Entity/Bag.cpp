#include "..\..\pch.h"

string Bag::Get_Id()
{
    return string();
}

void Bag::To_String()
{
}

bool Bag::Equal(const Entity& t)
{
    return false;
}

int Bag::Get_HashCode()
{
    return 0;
}


istream& operator>>(istream& input, Bag& bag)
{
    // TODO: �ڴ˴����� return ���
    cout << "����������:";
    input >> bag.capacity;
    cout << endl;
    cout << "����������:";
    input >> bag.bag_data;
    return input;
}

ostream& operator<<(ostream& output, Bag& bag)
{
    // TODO: �ڴ˴����� return ���
    output << bag.bag_id << bag.capacity << bag.bag_data << endl;
    return output;
}
