#include "Intern.hpp"
#include <iostream>	//for std
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Constructor
Intern::Intern()
{
	std::cout << "Intern: Constructor called" << std::endl;
}

// Copy constructor
Intern::Intern(const Intern& other)
{
	*this = other;
}

// Copy assignment operator
Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}

// Destructor
Intern::~Intern()
{
	std::cout << "Intern: Destructor called" << std::endl;
}

//exception

const char*	Intern::NoSuchFormException::what(void) const throw()
{
	return("no such form name");
}

AForm*	Intern::_createShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::_createRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::_createPardon(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeForm(std::string name, std::string target)
{
	std::string forms[3] =
		{
			"shrubbery creation",
			"robotomy request",
			"presidential pardon"
		};
	AForm*	(Intern::*functions[3])(std::string);
	functions[0] = &Intern::_createShrubbery;
	functions[1] = &Intern::_createRobotomy;
	functions[2] = &Intern::_createPardon;
	int i = 0;
	while (i < 3 && name != forms[i])
		i++;

	try
	{
		if (i == 3)
			throw(NoSuchFormException());
		AForm*	form = (this->*functions[i])(target);
		std::cout << "Intern creates " << name << " with target " << target << std::endl;
		return (form);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Intern couldn't create form " << name << " because " << e.what() << std::endl;
		return (NULL);
	}
}
