#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <time.h>//time()
#include <stdlib.h>//srand
#undef SIG
#define SIG 72
#undef EXE
#define EXE 45

// Constructor
RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", SIG, EXE), _target("default")
{
	std::cout << "RobotomyRequestForm: Default Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", SIG, EXE), _target(target)
{
	std::cout << "RobotomyRequestForm with target " << _target << ": Constructor called" << std::endl;
}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), _target(other._target)
{
	*this = other;
	std::cout << "RobotomyRequestForm with target " << _target << ": copy-constructed." << std::endl;
}

// Copy assignment operator
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm with target " << _target << ": Destructor called" << std::endl;
}

void	RobotomyRequestForm::action(void) const
{
	std::cout << "DRILL DRILL .... " << std::endl;
	srand(time(NULL));//sets the seed nbr for rand()
	if (rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "robotomization of " << _target << " failed" << std::endl;
}
