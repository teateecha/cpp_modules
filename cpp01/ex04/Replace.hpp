#ifndef REPLACE_HPP
#define REPLACE_HPP
#include <iostream>	//for std

int	complainAndReturn(std::string str, int retu);
int	ft_replace(std::ifstream & inputfile, std::ofstream & output,
		std::string const & s1, std::string const & s2);
#endif

