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

static t_type	detectType(std::string literal)
{
	if (literal.length() == 3 &&  literal[0] == '\'' && isPrintable(literal[1]) && literal[2] == '\'')
		return TYPE_CHAR;

	else if (literal.find_first_not_of("0123456789-+.f") == std::string::npos)
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

virtual const char*	ScalarConverter::InvalidTypeException::what(void) const throw()
{
	return ("char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible");
}

static void		typePrint(void * inputpointer)
{
}

void	ScalarConverter::convert(std::string literal)
{
	try
	{
		t_type	type = detectType(literal);
		switch (type)
		{
			case TYPE_CHAR:
				char input = static_cast<char>litearl[1];
				break;
			case TYPE_INT:
				int input = atoi(literal.c_str);
				break;
			case TYPE_DOUBLE:
				double input = std::stod(literal);//TODO checks
				break;
			case TYPE_FLOAT:
				break;
			case TYPE_NAN:
				break;
			default:
				throw (InvalidTypeException());
		}
		void* inputpointer = static_cast<void*>(input);
		typePrint(inputpointer);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

/*
 * from subject:
 * ./convert 0 char: Non displayable int: 0 float: 0.0f double: 0.0
 * ./convert nan char: impossible int: impossible float: nanf double: nan
 * ./convert 42.0f char: '*' int: 42 float: 42.0f double: 42.0
 */
