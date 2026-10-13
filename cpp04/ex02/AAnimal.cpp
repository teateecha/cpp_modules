#include "AAnimal.hpp"
#include <iostream>	//for std

// Constructor
AAnimal::AAnimal()
	: _type("AAnimal")
{
	std::cout << "AAnimal: Constructor called" << std::endl;
}

// Copy constructor
AAnimal::AAnimal(const AAnimal& other)
{
	*this = other;
	std::cout << "AAnimal: Copy Constructor called" << std::endl;
}

// Copy assignment operator
AAnimal& AAnimal::operator=(const AAnimal& other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}

// Destructor
AAnimal::~AAnimal()
{
	std::cout << "AAnimal: Destructor called" << std::endl;
}

std::string	AAnimal::getType(void) const
{
	return (_type);
}
