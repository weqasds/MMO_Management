#pragma once
#include"..\..\pch.h"
#include"Mapper.h"
namespace ORM 
{
	class DataBase
	{
	public:
		DataBase(mysqlx::Session& coon)
		{
			db = new mysqlx::Schema(coon);
			for(auto table : db->getTables())
			{
				string name = table.getName();

			}
		}
		~DataBase()
		{
			delete db;
			for (auto set : dbsets)
			{
				set.~DbSet();
			}
			delete this;
		}
		
	private:
		mysqlx::Schema* db;
		/*DbSet<Admin> admin;
		DbSet<Bag> bag;
		DbSet<Character> character;
		DbSet<Equip> equip;
		DbSet<Player> player;
		DbSet<Player_Behaviour> player_behaviour;*/
		list<DbSet<Entity*>> dbsets;
	};
}

