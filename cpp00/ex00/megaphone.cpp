#include <ctype.h>/*for toupper*/
#include <iostream>/*for std*/

int	main(int argc, char **argv)
{
	char	c;
	int		i;
	int		j;

	j = 1;
	if (argc == 1)
	{
		std::cout <<  "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (j < argc)
	{
		i = 0;
		while(argv[j][i])
		{
			c = toupper(argv[j][i]);
			std::cout << c;
			i++;
		}
		j++;
	}
	std::cout << std::endl;
	return (0);
}


