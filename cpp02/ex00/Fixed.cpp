#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

//construct and copy a new object from an existing (other)
Fixed::Fixed(const Fixed& other)// : _value(other._value) this woud be cleaner
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

//copy into an existing object from an other existing object
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_value = other.getRawBits();//only for the subjet output other._value would be simpler
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
