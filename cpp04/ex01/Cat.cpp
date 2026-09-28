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
	_catBrain = new Brain(*other._catBrain);
	std::cout << "Cat: Copy Constructor called" << std::endl;
}

// Copy assignment operator
Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		*_catBrain = *other._catBrain;
	}
	return *this;
}

// Destructor
Cat::~Cat()
{
	delete _catBrain;
	std::cout << "Cat: Destructor called" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Miau miau." << std::endl;
}



//getter
Brain*	Cat::getBrain(void) const
{
	return (_catBrain);
}
