#include "Bureaucrat.hpp"
#include <iostream>

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("This grade is too low.");
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("This grade is too high.");
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
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else
		{
			_grade = static_cast<unsigned int>(grade);
			std::cout << "Bureaucrat " << _name << ": Constructor called" << std::endl;
		};
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: _name(other._name), _grade(other._grade)
{
	std::cout << "Bureaucrat " << _name << ": copy-constructed." << std::endl;
}

// Copy assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "you cannot copy from " << other._name
	<< " because this is a class with const memebers .. .they are not overridable." << std::endl;
	return (*this);
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << _name << ": Destructor called" << std::endl;
}

const std::string	Bureaucrat::getName(void) const
{
	return (_name);
}

unsigned int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}
