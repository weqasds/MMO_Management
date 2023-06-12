#pragma once
#include"..\..\pch.h"
class Entity abstract
{
public:
	virtual string Get_Id() = 0;
	virtual void To_String() = 0;
	virtual bool Equal(const Entity& t) = 0;
	virtual int Get_HashCode() = 0;
	/*virtual bool operator==(const Entity& t) = 0;*/
	/*virtual ~Entity() = 0;*/
};

