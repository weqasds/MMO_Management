#pragma once
#include "..\..\pch.h"
#include"..\ORM\Define.h"
class Player : public Entity
{
    ORMAP("Player", player_id, character_id, account, nickname, gender, age);
public:
    // 通过 Entity 继承
    virtual string Get_Id() override;
    virtual void To_String() override;
    virtual bool Equal(const Entity& t) override;
    virtual int Get_HashCode() override;
    virtual bool operator==(const Entity& t) override;

    //构造函数
    Player();
private:
    string player_id;
    string character_id;
    string account;
    string nickname;
    Sex gender=Sex::Male;
    int age;
};

