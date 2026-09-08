#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int val) : _value(val << _fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float val)
	: _value(roundf(val * (1 << _fractionalBits)))//1 << _fractionalBits = 2^8
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_value = other._value;
	}
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}


float	Fixed::toFloat(void) const
{
	return (static_cast<float>(_value) / (1  << _fractionalBits));
}


int		Fixed::toInt(void) const
{
	return (_value >> _fractionalBits);
}

std::ostream&	operator<<(std::ostream& o, Fixed const& rhs)
{
	o << rhs.toFloat();
	return (o);
}

bool	Fixed::operator>(Fixed const& rhs) const
{
	return (_value > rhs._value);
}

bool	Fixed::operator<(Fixed const& rhs) const
{
	return (_value < rhs._value);
}

bool	Fixed::operator>=(Fixed const& rhs) const
{
	return (_value >= rhs._value);
}

bool	Fixed::operator<=(Fixed const& rhs) const
{
	return (_value <= rhs._value);
}

bool	Fixed::operator==(Fixed const& rhs) const
{
	return (_value == rhs._value);
}

bool	Fixed::operator!=(Fixed const& rhs) const
{
	return (_value != rhs._value);
}

Fixed	Fixed::operator+(Fixed const& rhs) const
{
	Fixed temp;

	temp._value = _value + rhs._value;
	return(temp);
}

Fixed	Fixed::operator-(Fixed const& rhs) const
{
	Fixed temp;

	temp._value = _value - rhs._value;
	return(temp);
}

Fixed	Fixed::operator*(Fixed const& rhs) const
{
	Fixed	temp;

	temp._value = _value * rhs._value;
	temp._value = temp._value >> _fractionalBits;
	return(temp);
}

Fixed	Fixed::operator/(Fixed const& rhs) const
{
	Fixed	temp;

	temp._value = _value << _fractionalBits;
	temp._value = temp._value / rhs._value;
	return(temp);
}


Fixed&	Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp = *this;
	
	this->_value++;
	return (temp);
}

Fixed&	Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp = *this;
	
	this->_value--;
	return (temp);
}


Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	else
	 return (b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a < b)
		return (b);
	else
	 return (a);
}

Fixed const&	Fixed::min(Fixed const& a, Fixed const& b)
{
	if (a < b)
		return (a);
	else
	 return (b);
}

Fixed const&	Fixed::max(Fixed const& a, Fixed const& b)
{
	if (a < b)
		return (b);
	else
	 return (a);
}
