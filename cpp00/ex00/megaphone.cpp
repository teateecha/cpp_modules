#include <ctype.h>
#include <stdio.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	j = 1;
	if (argc == 1)
	{
		write(1, "* LOUD AND UNBEARABLE FEEDBACK NOISE *", 38);
		return (0);
	}
	while (argv[j])
	{
		while(argv[1][i])
		{
			c = argv[1][i];
			putchar(toupper(c));
			i++;
		}
		j++;
	}
	return (0);
}


