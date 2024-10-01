#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <math.h>

class Fixed
{
	public:
		Fixed();
		Fixed(const int fixedPointVal);
		Fixed(const float floatingPointVal);
		Fixed(const Fixed &copy);
		~Fixed();
		Fixed 			&operator=(const Fixed &copy);
		int				getRawBits()const;
		int				getFractionalBits()const;
		void			setRawBits(int const raw);
		float			toFloat(void)const;
		int				toInt(void)const;

	private:
		int					_fixedPointVal;
		static const int	_fractionalBits;	
};

std::ostream	&operator<<(std::ostream &stream, const Fixed &fixed);

#endif