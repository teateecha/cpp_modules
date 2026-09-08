#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	public:
		Fixed();//Default Constructor
		Fixed(const int val);
		Fixed(const Fixed& other);// Copy Constructor
		Fixed& 				operator=(const Fixed& other);//Copy assignement operator
		~Fixed();//Destructor

		int					getRawBits(void) const;
		void				setRawBits(int const raw);
	private:
		int					_value;
		static const int	_fractionalBits = 8;
};

#endif
