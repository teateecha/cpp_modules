#include <string>
#include <iostream>

int	main(void)
{
	std::string	stringVAR = "HI THIS IS BRAIN";
	std::string* stringPTR = &stringVAR;
	std::string & stringREF = stringVAR;

	std::cout<< "instance\tadress\t\tvalue\n" << std::endl;
	std::cout << "stringVAR\t" << &stringVAR << "\t" << stringVAR << std::endl;
	std::cout << "stringPTR\t" << stringPTR << "\t" << *stringPTR << std::endl;
	std::cout << "stringREF\t" << &stringREF << "\t"  << stringREF << std::endl;
	return (0);
}
/*
Your program must print:
• The memory address of the string stringVAR.
• The memory address held by stringPTR.
• The memory address held by stringREF.
And then:
• The value of the string variable.
• The value pointed to by stringPTR.
• The value pointed to by stringREF.
*/
