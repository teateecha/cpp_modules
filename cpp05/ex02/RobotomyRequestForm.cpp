#include "RobotomyRequestForm.hpp"
#include <iostream>

// Constructor
RobotomyRequestForm::RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm: Default Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: _target(target)
{
	std::cout << "RobotomyRequestForm " << _target << ": Constructor called" << std::endl;
}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
{
	*this = other;
	std::cout << "RobotomyRequestForm " << _target << ": copy-constructed." << std::endl;
}

// Copy assignment operator
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		_target = other._target;
	}
	return (*this);
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm " << _target << ": Destructor called" << std::endl;
}
