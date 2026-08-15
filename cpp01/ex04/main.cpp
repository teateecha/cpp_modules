#include <iostream>
#include <string>
#include <fstream>	//for ofstream and ifstream

static int	complainAndReturn(std::string str, int retu)
{
	if (retu == 0)
		std::cout << str << std::endl;
	else
		std::cerr << str <<std::endl;
	return (retu);
}

///reads from input stream line by line
static int	replace(std::ifstream & inputfile, std::ofstream & output,
		std::string const & s1, std::string const & s2)
{
	std::string				line;
	std::string::size_type	ilength;
	std::string::size_type	olength;
	std::string::size_type	found;

	if (s1.empty())
		return (complainAndReturn("s1 is empty", 1));
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

///reads from inputfilestream, replaces s1 with s2 and writes to outputfilesteram
int	main(int argc, char **argv)
{
	int	retu;
	if (argc != 4)
		return (complainAndReturn("wrong number of arguments", 1));

	std::ifstream inputfile(argv[1]);
	if (!inputfile.is_open())
		return (complainAndReturn("input file not readable", 1));

	std::string	outputName = std::string(argv[1]) + ".replace";
	std::ofstream	output(outputName.c_str());
	if (!output.is_open())
		return (complainAndReturn("output file not created", 1));

	retu = replace (inputfile, output, argv[2], argv[3]);
	inputfile.close();
	output.close();
	return (retu);
}
