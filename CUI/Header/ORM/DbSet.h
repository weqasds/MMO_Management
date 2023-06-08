#pragma once
#include "..\..\pch.h"
namespace ORM
{
	template<class TEntity>
	class DbSet : Operation<TEntity>
	{
	public:
		virtual int Add(TEntity t) override;
		virtual int Update(TEntity t) override;
		virtual int Delete(TEntity t) override;
		DbSet();
		~DbSet();
	private:
		mysqlx::Table* set;
	};
	template<class TEntity>
	inline int DbSet<TEntity>::Add(TEntity t)
	{
		return 0;
	}
	template<class TEntity>
	inline int DbSet<TEntity>::Update(TEntity t)
	{
		return 0;
	}
	template<class TEntity>
	inline int DbSet<TEntity>::Delete(TEntity t)
	{
		return 0;
	}
	template<class TEntity>
	inline DbSet<TEntity>::DbSet()
	{
		set=new mysqlx::Table()
	}
	template<class TEntity>
	inline DbSet<TEntity>::~DbSet()
	{
	}
}

