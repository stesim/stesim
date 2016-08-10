#include <stesim/properties/property_simple.h>
#include <stesim/properties/property_trackable.h>

#include <iostream>

using namespace stesim;

void signal()
{
	std::cout << "property value changed" << std::endl;
}

class container
{
public:
	template<typename T, void ( container::*F )()>
	using property = property_trackable<T, fun_mem<container, F>>;

public:
	container()
		: A( this, 0.0f ), B( this, 0 )
	{
	}

private:
	void signalA()
	{
		std::cout << "A changed" << std::endl;
	}

	void signalB()
	{
		std::cout << "B changed" << std::endl;
	}

public:
	property<int, &container::signalA> A;
	property<int, &container::signalB> B;
};

int main( int argc, char* argv[] )
{
	property_simple<int> a( 1.0 );
	std::cout << a << std::endl;

	a = 2.0f;
	std::cout << a << std::endl;

	std::cout << std::endl;

	property_trackable<float, fun_ptr<&signal>> b( 3.14 );
	std::cout << b << std::endl;

	b = a;
	std::cout << b << std::endl;

	b = a + 1.15;
	std::cout << b << std::endl;

	std::cout << std::endl;

	container c;
	std::cout << c.A << std::endl;
	std::cout << c.B << std::endl;
	c.A = 10;
	std::cout << c.A << std::endl;
	c.B = 15;
	std::cout << c.B << std::endl;

	return 0;
}
