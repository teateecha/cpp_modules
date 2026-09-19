#include "Animal.hpp"
#include <iostream>	//for std

// Constructor
Animal::Animal()
	: type("Animal")
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
		type = other.type;
	}
	return *this;
}

// Destructor
Animal::~Animal()
{
	std::cout << "Animal: Destructor called" << std::endl;
}

void	Animal::makeSound(void)
{
	std::cout << "Animal speaking here." << std::endl;
}
