#include <iostream>
#include "Bureaucrat.hpp"
#include <stdlib.h>//for atoi because stoi is c++11


/*instatiate a Burocrat with a arg1: name and arg2: grade*/
int main(int argc, char **argv)
{
	if (argc != 3)
	{
		std::cerr << "wrong number of arguments." << std::endl;
		return (1);
	}
	std::string	name = std::string(argv[1]);
	int grade = atoi(argv[2]);
	if (grade == 0 && argv[2][0] != '0')//only very basic check ..this is not the main part of the excersise
		return (1);
	Bureaucrat heily = Bureaucrat(name, grade);
	std::cout << heily.getName() << " " << heily.getGrade() << std::endl;
	return (0);
}
