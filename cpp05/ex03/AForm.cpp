#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("AForm: grade is too low.");
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("AForm: grade is too high.");
}

const char*	AForm::NotSigndException::what() const throw()
{
	return ("AForm is not signed");
}

// Constructor - private to prevent the use
AForm::AForm()
	: _name("default"), _gradeToSign(LOWEST_LEVEL), _gradeToExec(LOWEST_LEVEL), _sig(false)
{
	std::cout << "AForm: Default Constructor called" << std::endl;
}

AForm::AForm(std::string name, unsigned int gradeToSign, unsigned int gradeToExec)
	: _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec), _sig(false)
{
	if (_gradeToSign > LOWEST_LEVEL || _gradeToExec > LOWEST_LEVEL)
		throw (AForm::GradeTooLowException());
	else if (_gradeToSign < HIGHEST_LEVEL || _gradeToExec < HIGHEST_LEVEL)
		throw (AForm::GradeTooHighException());
	std::cout << "AForm " << _name << ": Constructor called" << std::endl;
}

// Copy constructor
AForm::AForm(const AForm& other)
	: _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec), _sig(other._sig) { std::cout << "AForm " << _name << ": copy-constructed." << std::endl;
}

// Copy assignment operator - this function is private to prevent the use
AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		_sig = other._sig;
	return (*this);
}

// Destructor
AForm::~AForm()
{
	std::cout << "AForm " << _name << ": Destructor called" << std::endl;
}

std::string	AForm::getName(void) const
{
	return(_name);
}

unsigned int	AForm::getGradeToSign(void) const
{
	return (_gradeToSign);
}

unsigned int	AForm::getGradeToExec(void) const
{
	return (_gradeToExec);
}

bool	AForm::getSig(void) const
{
	return (_sig);
}

std::ostream&	operator<<(std::ostream& o, AForm const& form)
{
	o << form.getName()
		<< ", grade required to sign: " << form.getGradeToSign()
		<< ", grade required to execute: " << form.getGradeToExec()
		<< ",  sign status: " << form.getSig();
	return (o);
}

void	AForm::beSigned(Bureaucrat const& buro)
{
	if (buro.getGrade() > _gradeToSign)
		throw (AForm::GradeTooLowException());
	_sig = true;
}

void	AForm::execute(Bureaucrat const & buro) const
{
	if (buro.getGrade() > _gradeToExec)
		throw (AForm::GradeTooLowException());
	else if (_sig == false)
		throw(AForm::NotSigndException());
	action();
}
