#include "Dog.hpp"
#include <iostream>	//for std

// Constructor
Dog::Dog()
	: Animal()
{
	_type = "Dog";//orverwrite _type initialized by Animal()
	std::cout << "Dog: Constructor called" << std::endl;
}

// Copy constructor
Dog::Dog(const Dog& other)
	: Animal(other)
{
	*this = other;
	std::cout << "Dog: Copy Constructor called" << std::endl;
}

// Copy assignment operator
Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	return *this;
}

// Destructor
Dog::~Dog()
{
	std::cout << "Dog: Destructor called" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "wau wau" << std::endl;
}
