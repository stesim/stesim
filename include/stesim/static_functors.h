#pragma once

namespace stesim
{

template<void ( *F )()>
class fun_ptr
{
public:
	void operator()() const
	{
		return F();
	}

	operator bool() const
	{
		return true;
	}
};

template<typename T, void ( T::*F )()>
class fun_mem
{
public:
	fun_mem()
		: m_pObject( nullptr )
	{
	}

	fun_mem( T* object )
		: m_pObject( object )
	{
	}

	void operator()() const
	{
		return ( m_pObject->*F )();
	}

	operator bool() const
	{
		return m_pObject;
	}

private:
	T* m_pObject;
};

}
