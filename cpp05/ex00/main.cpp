#include "Bureaucrat.hpp"
#include <exception>
#include <stdexcept>//for overflow_error
#include <iostream>
#include <stdlib.h> //for atoi because stoi is c++11

/*instatiate a Burocrat with a arg1: name and arg2: grade*/
int main(int argc, char **argv)
{
    if (argc != 3)
    {
        std::cerr << "wrong number of arguments." << std::endl;
        return (1);
    }
    std::cout << "\n --- TEST: ---"  << std::endl;
    std::string name = std::string(argv[1]);
    int grade = atoi(argv[2]);
	try
	{
		if (grade == -1 && argv[2][0] != '-' && argv[2][1] != '1')
			throw (std::overflow_error("Int overflow"));
		else
		{
			Bureaucrat heily = Bureaucrat(name, grade);
			std::cout << "output:\t\t";
			std::cout << heily <<std::endl;
			std::cout << "now incrementing once:\t" << std::endl;
			heily.increment();
			std::cout << "we are still in the try block: output:\t\t";
			std::cout  << heily << std::endl;
			std::cout << "now decrementing twice:\t" << std::endl;
			heily.decrement();
			heily.decrement();
			std::cout << "we are still in the try block: output:\t\t";
			std::cout  << heily << std::endl;
		}
	}
	catch (const std::exception& e)
	{
		std::cout << "we are in the catch block" << std::endl;
		std::cerr << e.what() << std::endl;
	}
	std::cout << " ---- END ---\n\n" <<std::endl;
   return (0);
}
