#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	char	str[] = "Test string.\n";
	char	c;

	while(str[i])
	{
		c = str[i];
		putchar(toupper(c));
		i++;
	}
	return (0);
}


