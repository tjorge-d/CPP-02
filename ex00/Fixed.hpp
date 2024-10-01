#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &copy);
		Fixed	&operator=(const Fixed &copy);
		~Fixed();
		int		getRawBits()const;
		void	setRawBits(int const raw);

	private:
		int					_fixedPointVal;
		static const int	_fractionalBits;	
};

#endif