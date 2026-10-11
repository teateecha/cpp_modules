#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>


const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Form: this grade is too low.");
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Form: his grade is too high.");
}


// Constructor - private to prevent the use
Form::Form()
	: _name("default"), _gradeToSign(LOWEST_LEVEL), _gradeToExec(LOWEST_LEVEL), _sig(false)
{
	std::cout << "Form: Default Constructor called" << std::endl;
}

Form::Form(std::string name, unsigned int gradeToSign, unsigned int gradeToExec)
	: _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec), _sig(false)
{
	if (_gradeToSign > LOWEST_LEVEL || _gradeToExec > LOWEST_LEVEL)
		throw (Form::GradeTooLowException());
	else if (_gradeToSign < HIGHEST_LEVEL || _gradeToExec < HIGHEST_LEVEL)
		throw (Form::GradeTooHighException());
	std::cout << "Form " << _name << ": Constructor called" << std::endl;
}

// Copy constructor
Form::Form(const Form& other)
	: _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec), _sig(other._sig) { std::cout << "Form " << _name << ": copy-constructed." << std::endl;
}

// Copy assignment operator - this function is private to prevent the use
Form& Form::operator=(const Form& other)
{
	std::cerr << "you cannot copy from " << other._name
	<< " because this is a class with const memebers .. .they are not overridable." << std::endl;
	return (*this);
}

// Destructor
Form::~Form()
{
	std::cout << "Form " << _name << ": Destructor called" << std::endl;
}

std::string	Form::getName(void) const
{
	return(_name);
}

unsigned int	Form::getGradeToSign(void) const
{
	return (_gradeToSign);
}

unsigned int	Form::getGradeToExec(void) const
{
	return (_gradeToExec);
}

bool	Form::getSig(void) const
{
	return (_sig);
}

std::ostream&	operator<<(std::ostream& o, Form const& form)
{
	o << form.getName()
		<< ", form grade required to sign: " << form.getGradeToSign()
		<< "\tform grade required to execute: " << form.getGradeToExec()
		<< "\t sign status: " << form.getSig();
	return (o);
}

void	Form::beSigned(unsigned int grade)
{
	if (grade > _gradeToSign)
		throw (Form::GradeTooLowException());
	_sig = true;
}
