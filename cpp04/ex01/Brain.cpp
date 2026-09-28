#include "Brain.hpp"
#include <iostream>	//for std

// Constructor
Brain::Brain()
{
	std::cout << "Brain: Constructor called" << std::endl;
}

// Copy constructor
Brain::Brain(const Brain& other)
{
	*this = other;
}

// Copy assignment operator
// for loop is necessary for deep copy
Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			_ideas[i] = other._ideas[i];
	}
	return *this;
}

// Destructor
Brain::~Brain()
{
	std::cout << "Brain: Destructor called" << std::endl;
}

