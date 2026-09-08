#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed();//Default Constructor
		Fixed(const int val);
		Fixed(const float val);
		Fixed(const Fixed& other);// Copy Constructor
		Fixed& 				operator=(const Fixed& other);//Copy assignement operator
		~Fixed();//Destructor

		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;
	private:
		int					_value;
		static const int	_fractionalBits = 8;
};

std::ostream&	operator<<(std::ostream& o, Fixed const& rhs);

#endif
