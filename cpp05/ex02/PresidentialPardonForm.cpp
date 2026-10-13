#include "PresidentialPardonForm.hpp"
#include <iostream>

// Constructor
PresidentialPardonForm::PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm: Default Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string name)
	: _name(name)
{
	std::cout << "PresidentialPardonForm " << _name << ": Constructor called" << std::endl;
}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
{
	*this = other;
	std::cout << "PresidentialPardonForm " << _name << ": copy-constructed." << std::endl;
}

// Copy assignment operator
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		_name = other._name;
	}
	return (*this);
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm " << _name << ": Destructor called" << std::endl;
}
