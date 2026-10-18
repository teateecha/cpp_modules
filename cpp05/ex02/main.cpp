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
        std::cerr << "usage: arg1: burocrat name, arg2: burocrat grade, arg3: form name, \
			arg4 form grade required to sign, arg5 form grade required to execute" << std::endl;
        return (1);
    }
    std::cout << "\n --- TEST: ---"  << std::endl;
    std::string name = std::string(argv[1]);
    int grade = atoi(argv[2]);
	try
	{
		Bureaucrat heily = Bureaucrat(name, grade);
		ShrubberyCreationForm sForm(name);
		heily.executeForm(sForm);
		RobotomyRequestForm	rForm(name);
		heily.executeForm(rForm);
		PresidentialPardonForm pForm(name);
		heily.executeForm(pForm);
	}
	catch (const std::exception& e)
	{
		std::cout << "--- hello from main catch block" << std::endl;
		std::cerr << e.what() << std::endl;
	}
	std::cout << " ---- END ---\n\n" <<std::endl;
   return (0);
}
