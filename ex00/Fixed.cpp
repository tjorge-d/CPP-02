#include "Fixed.hpp"

const int	Fixed::_fractionalBits = 8;

Fixed::Fixed() : _fixedPointVal(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called\n";
	*this = copy;
}

void	Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &copy)
		_fixedPointVal = copy.getRawBits();
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int	Fixed::getRawBits()const
{
	std::cout << "getRawBits member function called\n";
	return(_fixedPointVal);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	_fixedPointVal = raw;
}