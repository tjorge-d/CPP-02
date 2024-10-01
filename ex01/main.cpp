#include "Fixed.hpp"

int main(void)
{
	std::cout << "---------- TEST 1 ----------\n" << std::endl;
	
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);
	a = Fixed(1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	std::cout << "\n---------- TEST 2 ----------\n" << std::endl;

	Fixed n;
	for(int i = 0; i < 32; i++)
	{
		n.setRawBits((1 << i) << n.getFractionalBits());
		std::cout << "2^" << i << " = " << n.toInt() << "\n";
	}
	return (0);
}