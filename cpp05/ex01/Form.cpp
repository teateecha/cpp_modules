#include "Form.hpp"
#include <iostream>

// Constructor
Form::Form()
	: _name("default"), _gradeToSign(150), _gradeToExec(150), _sig(false)
{
	std::cout << "Form: Default Constructor called" << std::endl;
}

Form::Form(std::string name)
	: _name(name)
{
	std::cout << "Form " << _name << ": Constructor called" << std::endl;
}

// Copy constructor
Form::Form(const Form& other)
{
	*this = other;
	std::cout << "Form " << _name << ": copy-constructed." << std::endl;
}

// Copy assignment operator
Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		_name = other._name;
	}
	return (*this);
}

// Destructor
Form::~Form()
{
	std::cout << "Form " << _name << ": Destructor called" << std::endl;
}
