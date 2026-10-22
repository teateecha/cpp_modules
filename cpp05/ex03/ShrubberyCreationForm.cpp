#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>//for ofstream and ifstream

#undef SIG
#define SIG 145
#undef EXE
#define EXE 137
// Constructor
ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", SIG, EXE), _target("default")
{
	std::cout << "ShrubberyCreationForm: Default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", SIG, EXE), _target(target)
{
	std::cout << "ShrubberyCreationForm with target " << _target << ": Constructor called" << std::endl;
}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target)
{
	*this = other;
	std::cout << "ShrubberyCreationForm with target " << _target << ": copy-constructed." << std::endl;
}

// Copy assignment operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm with target " << _target << ": Destructor called" << std::endl;
}

void	ShrubberyCreationForm::action(void) const
{
	std::string outputName = std::string(_target + "_shrubbery");
	std::ofstream output;
	output.exceptions(std::ofstream::failbit | std::ofstream::badbit);//makes ofstream throw and exception if it failes to open
	output.open(outputName.c_str());
	output	<< "               ,@@@@@@@," << std::endl
			<< "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl
			<< "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl
			<< "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl
			<< "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl
			<< "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl
			<< "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl
			<< "       |o|        | |         | |" << std::endl
			<< "       |.|        | |         | |" << std::endl
			<< "jgs \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_ https://ascii.co.uk/art/tree" << std::endl;
	output.close();
}
