#include "Harl.hpp"
#include <iostream>	// for std::
#include <string>	// for std::string and getline


/// helper: Prompts untill non-empty input removes surrounding whitespace.
static std::string	waitInput(std::string text)
{
	std::string	buff;

	while(buff.empty())
	{
		std::cout << text << " ";
		if (!std::getline(std::cin, buff))
			return (buff) ;
	}
	return (buff);
}

int	main(void)
{
	Harl	harl;

	std::cout << "\n check for every complain:" << std::endl;
	std::cout << "\nDEBUG" << std::endl;
	harl.complain("DEBUG");
	std::cout << "\nINFO" << std::endl;
	harl.complain("INFO");
	std::cout << "\nWARNING" << std::endl;
	harl.complain("WARNING");
	std::cout << "\nERROR" << std::endl;
	harl.complain("ERROR");
	std::cout << "\n that's it Harl is done complaining" << std::endl;

	std::cout << "\n\n your turn now:" << std::endl;
	harl.complain(waitInput("Enter harl level: DEBUG, INFO, WARNING or ERROR: "));
	return (0);
}
