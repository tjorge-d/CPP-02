#include "Fixed.hpp"

const int	Fixed::_fractionalBits = 8;

// CONSTRUCTORS/DESTRUCTOR

Fixed::Fixed() : _fixedPointVal(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int fixedPointVal) : _fixedPointVal(fixedPointVal << _fractionalBits)
{
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float floatingPointVal) : _fixedPointVal(roundf(floatingPointVal * (1 << _fractionalBits)))
{
	std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called\n";
	*this = copy;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

//OPERATORS

Fixed	&Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called\n";
	_fixedPointVal = copy._fixedPointVal;
	return (*this);
}

//GETTER

int	Fixed::getRawBits()const
{
	return(_fixedPointVal);
}

int	Fixed::getFractionalBits()const
{
	return(_fractionalBits);
}

//SETTER

void	Fixed::setRawBits(int const raw)
{
	_fixedPointVal = raw;
}

//FUNCTIONS

float	Fixed::toFloat(void)const
{
	return((float)_fixedPointVal / (1 << _fractionalBits));
}

int	Fixed::toInt(void)const
{
	return(_fixedPointVal >> _fractionalBits);
}

std::ostream	&operator<<(std::ostream &stream, const Fixed &fixed)
{
	stream << fixed.toFloat();
	return (stream);
}