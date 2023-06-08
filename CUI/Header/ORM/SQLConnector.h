#pragma once
#include"..\..\pch.h"
namespace ORM
{
	class SQLConnector
	{
	public:
		SQLConnector();
		~SQLConnector();

	private:
		mysqlx::Session* session;
		
	};
}

