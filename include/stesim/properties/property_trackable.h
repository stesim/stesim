#pragma once

#include "../static_functors.h"

namespace stesim
{

template<typename T, typename C>
class property_trackable
{
public:
	property_trackable() = default;

	property_trackable( const C& callback )
		: m_Callback( callback )
	{
	}

	property_trackable( const C& callback, const T& ref )
		: m_Value( ref ),
		m_Callback( callback )
	{
	}

	property_trackable( const T& ref )
		: m_Value( ref ),
		m_Callback()
	{
	}

	property_trackable( T&& ref )
		: m_Value( std::forward<T>( ref ) ),
		m_Callback()
	{
	}

	const property_trackable<T, C>& operator=( const T& ref )
	{
		m_Value = ref;
		notify_change();
		return *this;
	}

	const property_trackable<T, C>& operator=( T&& ref )
	{
		m_Value = std::forward<T>( ref );
		notify_change();
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

	void set_change_callback( const C& callback )
	{
		m_Callback = callback;
	}

	void notify_change()
	{
		if( m_Callback )
		{
			m_Callback();
		}
	}

private:
	T m_Value;
	C m_Callback;
};

}
