#include "ScalarConverter.hpp"
#include <iostream>

ScalarConverter::ScalarConverter(void)
{
	std::cout << "ScalarConverter: default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	*this = other;
	std::cout << "ScalarConverter has been copy constructed." << std::endl;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "ScalarConverter: Destructor called" << std::endl;
}

static int	isPrintable(char c)
{
	if (c >= ' ' && c <= '~')
		return (TRUE);
	else 
		return (FALSE);
}

static int	isDigit(char c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	else
	 return (FALSE);
}

static t_type	detectType(std::string input)
{
	if (input.length() == 3 &&  input.find_first_not_of("'"))
		return TYPE_CHAR;

	else if (input.find_first_not_of("0123456789-+.f") == std::string::npos)
	{
			if (has -- or ++ or in wrong place 
			Or f is not in end or two f or ...)
				return (TYPE_INVALID);
			if (....)
				return (TYPE_INT);
			if (....)
				return (TYPE_FLOAT);
			if (....)
				return (TYPE_DOUBLE);
	}
	return (TYPE_INVALID);
}

void	ScalarConverter::convert(std::string input)
{
	t_type	type = detectType(input);
}

