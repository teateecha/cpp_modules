#include "Replace.hpp"
#include <string>
#include <fstream>	//for ofstream and ifstream


int	complainAndReturn(std::string str, int retu)
{
	if (retu == 0)
		std::cout << str << std::endl;
	else
		std::cerr << str <<std::endl;
	return (retu);
}



///reads from input stream line by line
int	ft_replace(std::ifstream & inputfile, std::ofstream & output,
		std::string const & s1, std::string const & s2)
{
	std::string				line;
	std::string::size_type	ilength;
	std::string::size_type	olength;
	std::string::size_type	found;

	ilength = s1.length();
	olength = s2.length();
	while (std::getline(inputfile, line))
	{
		found = 0;
		while ((found = line.find(s1, found)) != std::string::npos)
		{
			line.erase(found, ilength);
			line.insert(found, s2);
			found += olength;
		}
		output << line;
		if (!inputfile.eof())
			output << std::endl;
	}
	if (inputfile.bad())//check if reading went wrong
		return (complainAndReturn("reading failed", 1));
	if (output.fail())
		return (complainAndReturn("writing failed", 1));
	return (0);
}
