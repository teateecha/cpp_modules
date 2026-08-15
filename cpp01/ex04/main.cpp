#include <string>

static int	complainAndReturn(std::string str, int retu)
{
	std::cout << str << std::ednl;
	return (retu);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (complainAndReturn("wrong number of arguments"), 0);

	return (0);
}
