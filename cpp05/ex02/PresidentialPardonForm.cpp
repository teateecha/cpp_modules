#include "PresidentialPardonForm.hpp"
#include <iostream>
# define SIG 25
# define EXE 5

// Constructor
PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", SIG, EXE), _target("default")
{
	std::cout << "PresidentialPardonForm: Default Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", SIG, EXE), _target(target)
{
	std::cout << "PresidentialPardonForm with target " << _target << ": Constructor called" << std::endl;
}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other), _target(other._target)
{
	*this = other;
	std::cout << "PresidentialPardonForm with target " << _target << ": copy-constructed." << std::endl;
}

// Copy assignment operator
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm with target " << _target << ": Destructor called" << std::endl;
}

void	PresidentialPardonForm::action(void) const
{
	std::cout << _target << " has been pardoned by Zapod Beeblebrox." << std::endl;
}
