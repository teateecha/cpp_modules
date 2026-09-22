#include "WrongAnimal.hpp"
#include <iostream>	//for std

// Constructor
WrongAnimal::WrongAnimal()
	: _type("WrongAnimal")
{
	std::cout << "WrongAnimal: Constructor called" << std::endl;
}

// Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	*this = other;
}

// Copy assignment operator
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}

// Destructor
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal: Destructor called" << std::endl;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal speaking here." << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (_type);
}
