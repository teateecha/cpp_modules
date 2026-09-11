#include <string>
#include <fstream>	//for ofstream and ifstream

#include "Replace.hpp"

///reads from inputfilestream, ft_replaces s1 with s2 and writes to outputfilesteram
int	main(int argc, char **argv)
{
	int	retu;
	if (argc != 4)
		return (complainAndReturn("wrong number of arguments", 1));

	std::ifstream inputfile(argv[1]);
	if (!inputfile.is_open())
		return (complainAndReturn("input file not readable", 1));

	if (std::string(argv[2]).empty())
		return (complainAndReturn("empty strings", 1));

	std::string	outputName = std::string(argv[1]) + ".replace";
	std::ofstream	output(outputName.c_str());
	if (!output.is_open())
		return (complainAndReturn("output file not created", 1));

	retu = ft_replace (inputfile, output, argv[2], argv[3]);
	inputfile.close();
	output.close();
	return (retu);
}
