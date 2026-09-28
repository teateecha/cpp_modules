#include "Dog.hpp"
#include <iostream>	//for std

// Constructor
Dog::Dog()
	: Animal()
{
	_type = "Dog";//orverwrite _type initialized by Animal()
	_dogBrain = new Brain();
	std::cout << "Dog: Constructor called" << std::endl;
}

// Copy constructor
Dog::Dog(const Dog& other)
	: Animal(other)
{
	_dogBrain = new Brain(*other._dogBrain);
	std::cout << "Dog: Copy Constructor called" << std::endl;
}

// Copy assignment operator
Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		_dogBrain = other._dogBrain;
	}
	return *this;
}

// Destructor
Dog::~Dog()
{
	delete _dogBrain;
	std::cout << "Dog: Destructor called" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "wau wau" << std::endl;
}

//getter
Brain*	Dog::getBrain(void) const
{
	return (_dogBrain);
}
