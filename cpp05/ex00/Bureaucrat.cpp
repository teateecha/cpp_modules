#include "Bureaucrat.hpp"
#include <iostream>


const char*	GradeTooHighException::what(void)
{
		return ("This grade is too high.");
}

const char*	GradeTooLowException::what(void)
{
		return ("This grade is too low.");
}

// Constructor
Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat: Default Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
	: _name(name)
{
	try 
	{
		grade < 1 1;
		grade > 150 1;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	_grade = static_cast<unsigned int>(grade);
	std::cout << "Bureaucrat " << _name << ": Constructor called" << std::endl;
}


// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	*this = other;
	std::cout << "Bureaucrat " << _name << ": copy-constructed." << std::endl;
}

// Copy assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		_name = other._name;
	}
	return *this;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << _name << ": Destructor called" << std::endl;
}

