#include "Cat.hpp"
#include <iostream>	//for std

// Constructor
Cat::Cat()
	: Animal()
{
	_type = "Cat";//orverwrite _type that has been initialized by Animal()
	std::cout << "Cat: Constructor called" << std::endl;
}

// Copy constructor
Cat::Cat(const Cat& other)
	: Animal(other)
{
	*this = other;
}

// Copy assignment operator
Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	return *this;
}

// Destructor
Cat::~Cat()
{
	std::cout << "Cat: Destructor called" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Miau miau." << std::endl;
}
