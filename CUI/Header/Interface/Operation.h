#pragma once
#include"..\..\pch.h"
template<class Dervied>
class Operation abstract
{
public:
	virtual int Add(Dervied t) = 0;
	virtual int Update(Dervied t) = 0;
	virtual int Delete(Dervied t) = 0;
};

