#include "Fixed.hpp"

const int	Fixed::_fractionalBits = 8;

// CONSTRUCTORS/DESTRUCTOR

Fixed::Fixed() : _fixedPointVal(0)
{
	// std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int fixedPointVal) : _fixedPointVal(fixedPointVal << _fractionalBits)
{
	// std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float floatingPointVal) : _fixedPointVal(roundf(floatingPointVal * (1 << _fractionalBits)))
{
	// std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed &copy)
{
	// std::cout << "Copy constructor called\n";
	*this = copy;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called\n";
}

//OPERATORS

Fixed&	Fixed::operator=(const Fixed &copy)
{
	//std::cout << "Copy assignment operator called\n";
	_fixedPointVal = copy._fixedPointVal;
	return (*this);
}

Fixed&	Fixed::operator++()
{
	_fixedPointVal++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed temp= *this;
	_fixedPointVal++;
	return temp;
}

Fixed&	Fixed::operator--()
{
	_fixedPointVal--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed temp= *this;
	_fixedPointVal--;
	return temp;
}

float Fixed::operator+(const Fixed &copy)const
{
	return ((float)(this->getRawBits() + copy.getRawBits()) \
	/ (1 << this->_fractionalBits));
}

float Fixed::operator-(const Fixed &copy)const
{
	return ((float)(this->getRawBits() - copy.getRawBits()) \
	/ (1 << this->_fractionalBits));
}

float Fixed::operator*(const Fixed &copy)const
{
	return ((float)(this->getRawBits() * copy.getRawBits()) \
	/ (1 << this->_fractionalBits * 2));
}

float Fixed::operator/(const Fixed &copy)const
{
	return ((float)((long)(this->getRawBits() << this->_fractionalBits) / copy.getRawBits()) \
	/ (1 << this->_fractionalBits));
}

bool	Fixed::operator>(const Fixed &copy)const
{
	if (this->getRawBits() > copy.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed &copy)const
{
	if (this->getRawBits() < copy.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed &copy)const
{
	if (this->getRawBits() >= copy.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed &copy)const
{
	if (this->getRawBits() <= copy.getRawBits())
		return (true);
	return (false);
}


bool	Fixed::operator==(const Fixed &copy)const
{
	if (this->getRawBits() == copy.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed &copy)const
{
	if (this->getRawBits() != copy.getRawBits())
		return (true);
	return (false);
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

Fixed&	Fixed::min(Fixed &a, Fixed &b)
{
	//std::cout << "Min\n";
	if (b < a)
		return (b);
	return (a);
}

Fixed&	Fixed::min(const Fixed &a, const Fixed &b)
{
	//std::cout << "Const min\n";
	if (b < a)
		return ((Fixed&) b);
	return ((Fixed&) a);
}

Fixed&	Fixed::max(Fixed &a, Fixed &b)
{
	//std::cout << "Max\n";
	if (b > a)
		return (b);
	return (a);
}

Fixed&	Fixed::max(const Fixed &a, const Fixed &b)
{
	//std::cout << "Const max\n";
	if (b > a)
		return ((Fixed&) b);
	return ((Fixed&) a);
}