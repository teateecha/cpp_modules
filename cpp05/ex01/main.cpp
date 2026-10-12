#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <stdlib.h> //for atoi because stoi is c++11

/*instatiate a Burocrat with a arg1: name and arg2: grade*/
int main(int argc, char **argv)
{
    if (argc != 6)
    {
        std::cerr << "usage: arg1: burocrat name, arg2: burocrat grade, arg3: form name, \
			arg4 form grade required to sign, arg5 form grade required to execute" << std::endl;
        return (1);
    }
    std::cout << "\n --- TEST: ---"  << std::endl;
    std::string name = std::string(argv[1]);
    int grade = atoi(argv[2]);
	std::string formname = std::string(argv[3]);
	int	gradeToSign = atoi(argv[4]);
	int gradeToExecute = atoi(argv[5]);
	try
	{
		Bureaucrat heily = Bureaucrat(name, grade);
		Form formH = Form(formname , gradeToSign, gradeToExecute);
		std::cout << "output:" << std::endl;
		std::cout << heily << std::endl;
		std::cout << formH << std::endl;
	 	std::cout << " --- try signing: --- " << std::endl;
		heily.signForm(formH);
		std::cout << formH << std::endl;
		std::cout << "--- incrementing once and then try signing again: ---" << std::endl;
		heily.increment();
		heily.signForm(formH);
		std::cout << formH << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "--- hello from main catch block" << std::endl;
		std::cerr << e.what() << std::endl;
	}
	std::cout << " ---- END ---\n\n" <<std::endl;
   return (0);
}
