#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Burocrat: grade is too low");
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Burocrat: grade is too high");
}

// Constructor
Bureaucrat::Bureaucrat()
	: _name("default"), _grade(LOWEST_LEVEL)
{
	std::cout << "Bureaucrat: Default Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
	: _name(name)
{
	if (grade < HIGHEST_LEVEL)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > LOWEST_LEVEL)
		throw Bureaucrat::GradeTooLowException();
	else
	{
		_grade = static_cast<unsigned int>(grade);
		std::cout << "Bureaucrat " << _name << ": Constructor called" << std::endl;
	};
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
	if (this != &other)
	{
		_grade = other._grade;
	}
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

void	Bureaucrat::increment(void)
{
	if (_grade <= HIGHEST_LEVEL)
		throw (Bureaucrat::GradeTooHighException());
	else
		_grade -= 1;
}

void	Bureaucrat::decrement(void)
{
	if (_grade >= LOWEST_LEVEL)
		throw (Bureaucrat::GradeTooLowException());
	else
		_grade += 1;
}

//overload of insertion operator
std::ostream&	operator<<(std::ostream& o, Bureaucrat const& buro)
{
	o << buro.getName() << ", bureaucrat grade " << buro.getGrade() <<  ".";
	return (o);
}

void	Bureaucrat::signAForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << _name << " couldn’t sign " << form.getName()
			<< " because "<< e.what() << "." << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const& form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
