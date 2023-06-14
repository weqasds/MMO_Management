#include "..\..\pch.h"

string Bag::Get_Id()
{
    return this->bag_id;
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

Bag::Bag()
{}

Bag::Bag(string id, int c, string data):
    bag_id(id),capacity(c),bag_data(data)
{}

Bag::Bag(const mysqlx::Row& row) 
{
    this->bag_id = row[0].get<string>();
    this->capacity = row[1].get<int>();
    this->bag_data = row[2].get<string>();
}

bool Bag::operator==(const Bag& t) const
{
    if (this->bag_id == t.bag_id && capacity == t.capacity && bag_data == t.bag_data)
        return true;
    return false;
}

istream& operator>>(istream& input, Bag& bag)
{
    // TODO: 在此处插入 return 语句
    cout << "请输入容量:";
    input >> bag.capacity;
    cout << endl;
    return input;
}

ostream& operator<<(ostream& output, Bag& bag)
{
    // TODO: 在此处插入 return 语句
    output<<"背包的id，容量分别是:" << bag.bag_id << bag.capacity << endl;
    return output;
}
