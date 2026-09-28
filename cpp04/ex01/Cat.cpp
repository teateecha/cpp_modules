#include "Cat.hpp"
#include <iostream>	//for std

// Constructor
Cat::Cat()
	: Animal()
{
	_type = "Cat";//orverwrite _type initialized by Animal()
	_catBrain = new Brain();
	std::cout << "Cat: Constructor called" << std::endl;
}

// Copy constructor
Cat::Cat(const Cat& other)
	: Animal(other)
{
	*this = other;
	for (int i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i];
	std::cout << "Cat: Copy Constructor called" << std::endl;
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
	delte[] _catBrain;
	std::cout << "Cat: Destructor called" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Miau miau." << std::endl;
}
