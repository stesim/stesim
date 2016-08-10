#pragma once

#include <type_traits>
#include <utility>

namespace stesim
{

template<typename T>
class property_simple
{
public:
	property_simple() = default;

	property_simple( const T& ref )
		: m_Value( ref )
	{
	}

	property_simple( T&& ref )
		: m_Value( std::forward<T>( ref ) )
	{
	}

	const property_simple<T>& operator=( const T& ref )
	{
		m_Value = ref;
		return *this;
	}

	const property_simple<T>& operator=( T&& ref )
	{
		m_Value = std::forward<T>( ref );
		return *this;
	}
	
	operator const T&() const
	{
		return m_Value;
	}

	explicit operator T&()
	{
		return m_Value;
	}

	const T& value() const
	{
		return m_Value;
	}

private:
	T m_Value;
};

}
