#include "Animal.hpp"
#include <iostream>	//for std

// Constructor
Animal::Animal()
	: _type("Animal")
{
	std::cout << "Animal: Constructor called" << std::endl;
}

// Copy constructor
Animal::Animal(const Animal& other)
{
	*this = other;
}

// Copy assignment operator
Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}

// Destructor
Animal::~Animal()
{
	std::cout << "Animal: Destructor called" << std::endl;
}

void	Animal::makeSound(void) const
{
	std::cout << "Animal speaking here." << std::endl;
}

std::string	Animal::getType(void) const
{
	return (_type);
}
