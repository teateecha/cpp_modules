#include "WrongCat.hpp"
#include <iostream>	//for std

// Constructor
WrongCat::WrongCat()
	: WrongAnimal()
{
	_type = "WrongCat";
	std::cout << "WrongCat: Constructor called" << std::endl;
}

// Copy constructor
WrongCat::WrongCat(const WrongCat& other)
	: WrongAnimal(other)
{
	*this = other;
}

// Copy assignment operator
WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
	{
		WrongAnimal::operator=(other);
	}
	return *this;
}

// Destructor
WrongCat::~WrongCat()
{
	std::cout << "WrongCat: Destructor called" << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Miau miau." << std::endl;
}
