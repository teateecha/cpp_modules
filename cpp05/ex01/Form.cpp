#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("This grade is too low.");
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("This grade is too high.");
}


// Constructor
Form::Form()
	: _name("default"), _gradeToSign(150), _gradeToExec(150), _sig(false)
{
	std::cout << "Form: Default Constructor called" << std::endl;
}

Form(std::string name, unsigned int gradeToSign, unsigned int gradeToExec);
	: _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec), _sig(false)
{
	if (_gradeToSign > LOWEST_LEVEL || _gradeToExec > LOWEST_LEVEL)
		throw (Form::GradeTooLowException);
	else if (_gradeToSign < HIGHEST_LEVEL || _gradeToExec < HIGHEST_LEVEL)
		throw (Form::GradeTooHighException);
	std::cout << "Form " << _name << ": Constructor called" << std::endl;
}

// Copy constructor
Form::Form(const Form& other)
	: _name(other._name), _gradeToSign(other._gradeToSign), gradeToExec(other._gradeToExec), _sig(other._sig)
{
	std::cout << "Form " << _name << ": copy-constructed." << std::endl;
}

// Copy assignment operator
Form& Form::operator=(const Form& other)
{
	std::cout << "you cannot copy from " << other._name
	<< " because this is a class with const memebers .. .they are not overridable." << std::endl;
	return (*this);
}

// Destructor
Form::~Form()
{
	std::cout << "Form " << _name << ": Destructor called" << std::endl;
}

const std::string	Form::getName(void) const
{
	return(_name);
}

const unsigned int	Form::getGradeToSign(void) const
{
	return (_gradeToSign);
}

const unsigned int	Form::getGradeToExec(void) const
{
	return (_gradeToExec);
}

std::ostream&	operator<<(std::ostream& o, Form const& form)
{
	o << form.getName()
		<< ",\nform grade required to sign:\t" << form.getGradeToSign()
		<< "\ngrade required to execute:\t" << form.getGradeToExec()
		<< std::endl;
}

void	Form::beSigned(Bureaucrat buro)
{
	if (buro.getGrade() > _gradeToSign)
		throw (Form::GradeTooLowException);
	_sig = true;
}
