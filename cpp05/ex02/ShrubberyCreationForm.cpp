#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <iostream>

// Constructor
ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), _taget("default"), _sig = false;
{
	std::cout << "ShrubberyCreationForm: Default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", SIG, EXE), _target(target), _sig = false;
{
	std::cout << "ShrubberyCreationForm with target: " << _target << ": Constructor called" << std::endl;
}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target)
{
	*this = other;
	std::cout << "ShrubberyCreationForm with target: " << _target << ": copy-constructed." << std::endl;
}

// Copy assignment operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		_target = other._target;
	}
	return (*this);
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm with target: " << _target << ": Destructor called" << std::endl;
}
