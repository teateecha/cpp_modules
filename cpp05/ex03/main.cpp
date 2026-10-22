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
		std::cout << heily << std::endl;
		// ------------------ shurbbery -----------------
		std::cout << "\n  ---- SHRUBBERY--" << std::endl;
		AForm*	sForm = ini.makeForm("shrubbery creation", "Garden");
		if (sForm)
		{
			std::cout << "-- start sForm -- " << *sForm << " -- end sForm -- " << std::endl;
			heily.executeForm(*sForm);//should fail not signed
			heily.signAForm(*sForm);
			heily.executeForm(*sForm);
			delete sForm;
		}
		// ------------------ RobotomyRequestForm -----------------
		std::cout << "\n  ---- RobotomyRequestForm--" << std::endl;
		AForm*	rForm = ini.makeForm("robotomy request", "RobertTarget");
		if (rForm)
		{
			std::cout << "-- start rForm -- " << *rForm << " -- end rForm -- " << std::endl;
			heily.executeForm(*rForm);//should fail not signed
			heily.signAForm(*rForm);
			heily.executeForm(*rForm);
			delete rForm;
		}
		// ------------------ PresidentialPardonForm -----------------
		std::cout << "\n  ---- PresidentialPardonForm--" << std::endl;
		AForm*	pForm = ini.makeForm("presidential pardon", "PaulaTarget");
		if (pForm)
		{
			std::cout << "-- start pForm -- " << *pForm << " -- end pForm -- " << std::endl;
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
			std::cout << "-- start iForm -- " << *iForm << " -- end iForm -- " << std::endl;
			delete iForm;
		}
	}
	catch (const std::exception& e)
	{
		std::cout << "main caught: " << e.what() << std::endl;
	}
	std::cout << " === TEST END ===\n" <<std::endl;
   return (0);
}
