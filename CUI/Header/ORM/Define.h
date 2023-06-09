#pragma once
#include "..\..\pch.h"
#define ORMAP(_CLASS_NAME_, ...)                          \
private:                                                  \
friend class BOT_ORM_Impl::InjectionHelper;               \
template <typename Fun>                                   \
inline decltype (auto) __Accept (Fun fn)                  \
{ return fn (__VA_ARGS__); }                              \
template <typename Fun>                                   \
inline decltype (auto) __Accept (Fun fn) const            \
{ return fn (__VA_ARGS__); }                              \
constexpr static const char *__FieldNames = #__VA_ARGS__; \
constexpr static const char *__ClassName =  _CLASS_NAME_; \                       



#define NO_ORMAP "Please Inject the Class with 'ORMAP' first"
#define BAD_TYPE "Only Support Integral, Floating Point and std::string"

#define BAD_COLUMN_COUNT "Bad Column Count"
#define NULL_DESERIALIZE "Get Null Value"

#define NO_FIELD "No Such Field for current Extractor"
#define NOT_SAME_TABLE "Fields are NOT from the Same Table"

namespace BOT_ORM_Impl
{
	class InjectionHelper
	{
		static std::vector<std::string> ExtractFieldName(std::string input)
		{
			std::vector<std::string> ret;
			std::string tmpStr;

			for (char ch : std::move(input) + ",")
			{
				if (isalnum(ch) || ch == '_')
					tmpStr += ch;
				else if (ch == ',')
				{
					if (!tmpStr.empty())
						ret.push_back(tmpStr);
					tmpStr.clear();
				}
			}
			return ret;
		};

	public:
		// Checking Injection
		template <typename T> class HasInjected
		{
			template <typename...> struct make_void { using type = void; };
			template <typename... _Types>
			using void_t = typename make_void<_Types...>::type;

			template <typename, typename = void_t<>>
			struct Test : std::false_type {};
			template <typename U>
			struct Test <U, void_t<decltype (U::__ClassName)>>
				: std::true_type
			{};

		public:
			static constexpr bool value = Test<T>::value;

			static_assert (value, NO_ORMAP);
		};

		// Proxy Function
		template <typename C, typename Fn>
		static inline decltype (auto) Visit(C& obj, Fn fn)
		{
			return obj.__Accept(fn);
		}

		// Field Name Proxy
		template <typename C>
		static inline const std::vector<std::string>& FieldNames(const C&)
		{
			static const auto fieldNames = ExtractFieldName(C::__FieldNames);
			return fieldNames;
		}

		// Table Name Proxy
		template <typename C>
		static inline const std::string& ClassName(const C&)
		{
			static const std::string className{ C::__ClassName };
			return className;
		}
	};
	/*auto Mapper(mysqlx::Schema& db, string& name)
	{
		if (name == "Admin")
		{
			return ORM::DbSet<Admin>(db, name);
		}
		else if (name == "Bag")
		{
			return ORM::DbSet<Bag>(db, name);
		}
		else if (name == "Character")
		{
			return ORM::DbSet<Character>(db, name);
		}
		else if (true)
		{

		}
		else if (true)
		{
		}
		else if (true)
		{

		}
		else if (true)
		{
		}
		else
		{
			cout << NOT_SAME_TABLE << endl;
		}
	}*/
}