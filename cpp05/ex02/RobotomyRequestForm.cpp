#include "RobotomyRequestForm.hpp"
#include <iostream>

// Constructor
RobotomyRequestForm::RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm: Default Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string name)
	: _name(name)
{
	std::cout << "RobotomyRequestForm " << _name << ": Constructor called" << std::endl;
}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
{
	*this = other;
	std::cout << "RobotomyRequestForm " << _name << ": copy-constructed." << std::endl;
}

// Copy assignment operator
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		_name = other._name;
	}
	return (*this);
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm " << _name << ": Destructor called" << std::endl;
}
