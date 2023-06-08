#pragma once
#include "..\..\pch.h"
namespace ORM
{
	template<class T>
	class Nullable
	{
        template <typename T2>
        friend bool operator== (const Nullable<T2>& op1, const Nullable<T2>& op2);
        template <typename T2>
        friend bool operator== (const Nullable<T2>& op, const T2& value);
        template <typename T2>
        friend bool operator== (const T2& value, const Nullable<T2>& op);
        template <typename T2>
        friend bool operator== (const Nullable<T2>& op, std::nullptr_t);
        template <typename T2>
        friend bool operator== (std::nullptr_t, const Nullable<T2>& op);
    public:
        Nullable(): m_hasValue(false),m_value(T())
        {}
        Nullable(std::nullptr_t)
            : Nullable()
        {}

        // Null Assignment
        const Nullable<T>& operator= (std::nullptr_t)
        {
            m_hasValue = false;
            m_value = T();
            return *this;
        }

        // Value Construction
        template<typename T2>
        Nullable(const T2& value)
            : m_hasValue(true), m_value(value)
        {}

        // Value Assignment
        template<typename T2>
        const Nullable<T>& operator= (const T2& value)
        {
            m_hasValue = true;
            m_value = value;
            return *this;
        }

        const T& Value() const
        {
            return m_value;
        }
    private:
        bool m_hasValue;
        T m_value;
	};

    // == varialbe
    template <typename T2>
    inline bool operator== (const Nullable<T2>& op1, const Nullable<T2>& op2)
    {
        return op1.m_hasValue == op2.m_hasValue &&
            (!op1.m_hasValue || op1.m_value == op2.m_value);
    }

    // == value
    template <typename T2>
    inline bool operator== (const Nullable<T2>& op, const T2& value)
    {
        return op.m_hasValue && op.m_value == value;
    }
    template <typename T2>
    inline bool operator== (const T2& value, const Nullable<T2>& op)
    {
        return op.m_hasValue && op.m_value == value;
    }

    // == nullptr
    template <typename T2>
    inline bool operator== (const Nullable<T2>& op, std::nullptr_t)
    {
        return !op.m_hasValue;
    }
    template <typename T2>
    inline bool operator== (std::nullptr_t, const Nullable<T2>& op)
    {
        return !op.m_hasValue;
    }
}

