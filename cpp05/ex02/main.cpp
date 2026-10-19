#include "Bureaucrat.hpp"
#include "AForm.hpp"
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
    std::cout << "\n --- TEST START  ---"  << std::endl;
    std::string name = std::string(argv[1]);
    int grade = atoi(argv[2]);
	try
	{
		Bureaucrat heily = Bureaucrat(name, grade);
		std::cout << "\n \t --shrubbery--" << std::endl;
		ShrubberyCreationForm sForm(name);
		heily.executeForm(sForm);
		heily.signAForm(sForm);
		heily.executeForm(sForm);
		std::cout << "\n \t --robotomy--" << std::endl;
		RobotomyRequestForm	rForm(name);
		heily.executeForm(rForm);
		heily.signAForm(rForm);
		heily.executeForm(rForm);
		std::cout << "\n \t --PresidentialPardonForm--" << std::endl;
		PresidentialPardonForm pForm(name);
		heily.executeForm(pForm);
		heily.signAForm(pForm);
		heily.executeForm(pForm);
		std::cout << "\n\n Destructors:\n" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "--- hello from main catch block" << std::endl;
		std::cerr << e.what() << std::endl;
	}
	std::cout << " ---- TEST END ---\n\n" <<std::endl;
   return (0);
}
