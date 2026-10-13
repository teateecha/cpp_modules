#include "ShrubberyCreationForm.hpp"
#include <iostream>

// Constructor
ShrubberyCreationForm::ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm: Default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name)
	: _name(name)
{
	std::cout << "ShrubberyCreationForm " << _name << ": Constructor called" << std::endl;
}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
{
	*this = other;
	std::cout << "ShrubberyCreationForm " << _name << ": copy-constructed." << std::endl;
}

// Copy assignment operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		_name = other._name;
	}
	return (*this);
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm " << _name << ": Destructor called" << std::endl;
}
