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
    // TODO: 在此处插入 return 语句
    cout << "请输入容量:";
    input >> bag.capacity;
    cout << endl;
    cout << "请输入数据:";
    input >> bag.bag_data;
    return input;
}

ostream& operator<<(ostream& output, Bag& bag)
{
    // TODO: 在此处插入 return 语句
    output << bag.bag_id << bag.capacity << bag.bag_data << endl;
    return output;
}
