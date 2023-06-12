#pragma once
#include "..\..\pch.h"
class Player : public Entity
{
public:
    // ͨ�� Entity �̳�
    virtual string Get_Id() override;
    virtual void To_String() override;
    virtual bool Equal(const Entity& t) override;
    virtual int Get_HashCode() override;
    /*virtual bool operator==(const Entity& t) override;*/

    //���캯��
    Player();
private:
    string player_id;
    string character_id;
    string account;
    string nickname;
    Sex gender = Sex::Male;
    int age;
    //����������
    friend istream& operator>>(istream& input, Player& player);
    friend ostream& operator<<(ostream& outpou, Player& player);
};

