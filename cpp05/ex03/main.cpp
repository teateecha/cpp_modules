#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
#include <iostream>
#include <stdlib.h> //for atoi because stoi is c++11

/*instatiate a Burocrat with a arg1: name and arg2: grade*/
int main(int argc, char **argv)
{
    if (argc != 3)
    {
        std::cerr << "usage: arg1: burocrat name, arg2: burocrat grade" << std::endl;
        return (1);
    }
    std::cout << "\n === TEST START  === " << std::endl;
	try
	{
		Bureaucrat heily = Bureaucrat(argv[1], atoi(argv[2]));
		Intern ini;
		// ------------------ shurbbery -----------------
		std::cout << "\n  ---- SHRUBBERY--" << std::endl;
		AForm*	sForm = ini.makeForm("ShrubberyCreationForm", "Garden");
		if (sForm)
		{
			heily.executeForm(*sForm);//should fail not signed
			heily.signAForm(*sForm);
			heily.executeForm(*sForm);
			delete sForm;
		}
		// ------------------ RobotomyRequestForm -----------------
		std::cout << "\n  ---- RobotomyRequestForm--" << std::endl;
		AForm*	rForm = ini.makeForm("RobotomyRequestForm", "RobertTarget");
		if (rForm)
		{
			heily.executeForm(*rForm);//should fail not signed
			heily.signAForm(*rForm);
			heily.executeForm(*rForm);
			delete rForm;
		}
		// ------------------ PresidentialPardonForm -----------------
		std::cout << "\n  ---- PresidentialPardonForm--" << std::endl;
		AForm*	pForm = ini.makeForm("PresidentialPardonForm", "PaulaTarget");
		if (pForm)
		{
			heily.executeForm(*pForm);//should fail not signed
			heily.signAForm(*pForm);
			heily.executeForm(*pForm);
			delete pForm;
		}
		// ------------------ InvalidForm -----------------
		std::cout << "\n  ---- InvalidForm--" << std::endl;
		AForm*	iForm = ini.makeForm("InvalidForm", "IlayTarget");
		if (iForm)
		{
			delete iForm;
		}
		std::cout << "\n\n Destructors:\n" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "main caught: " << e.what() << std::endl;
	}
	std::cout << " === TEST END ===\n" <<std::endl;
   return (0);
}
