#pragma once
#include "..\..\pch.h"
class Player : public Entity
{
public:
    // 通过 Entity 继承
    virtual string Get_Id() override;
    virtual void To_String() override;
    virtual bool Equal(const Entity& t) override;
    virtual int Get_HashCode() override;
    /*virtual bool operator==(const Entity& t) override;*/

    //get&set
    void SetPlayerId(string playerid) { player_id = playerid; }
    string GetCharacterId() { return character_id; }
    void SetCharacterId(string characterid) { character_id = characterid; }
    string GetAccount() { return account; }
    string GetNickName() { return nickname; }
    Sex GetGender() { return gender; }
    int GetAge() { return age; }
    //构造函数
    Player();
    Player(mysqlx::Row& row);
    //运算器重载
    friend istream& operator>>(istream& input, Player& player);
    friend ostream& operator<<(ostream& output, Player& player);
private:
    string player_id;
    string character_id;
    string account;
    string nickname;
    Sex gender = Sex::Male;
    int age;
};

