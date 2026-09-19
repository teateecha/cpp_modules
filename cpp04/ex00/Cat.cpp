#include "Cat.hpp"
#include <iostream>	//for std

// Constructor
Cat::Cat()
{
	std::cout << "Cat: Constructor called" << std::endl;
}

// Copy constructor
Cat::Cat(const Cat& other)
{
	*this = other;
}

// Copy assignment operator
Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other)
	}
	return *this;
}

// Destructor
Cat::~Cat()
{
	std::cout << "Cat: Destructor called" << std::endl;
}

void	Cat::makeSound(void)
{
	std::cout << "Miau miau." << std::endl;
}
