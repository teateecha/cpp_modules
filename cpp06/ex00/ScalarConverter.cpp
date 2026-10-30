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

//TODO use strtod
/*
static t_type	detectType(std::string literal)
{
	if (literal.compare("nan") == 0 
		|| literal.compare("-inf") == 0 || literal.compare("-inff") == 0
		|| literal.compare("+inf") == 0 || literal.compare("+inff") == 0)
		return (TYPE_NAN);
	if (literal.length() == 1 &&  literal.find_first_not_of("+-f.") == std::string::npos)//prevent them beeing interpreted as numbers
		return (TYPE_CHAR);
	if ((literal.find_first_of("+-") != std::string::npos && literal.find_last_of("+-") != 0)
		|| literal.find_first_of(".") != literal.find_last_of(".")
		|| literal.find_first_of("f") != literal.find_last_of("f")) //catching -- ++ -+ +- .. ff
		|| (literal.find_first_of("e") != std::string::npos 
			&& literal.find_first_of("-") != std::string::npos
			&& literal[0] != '-'
			&& literal.find_first_of("-") - literal.find_first_of("e") != 1))
		return (TYPE_INVALID);
	if (literal.find_first_not_of("0123456789+-e") == std::string::npos)
		return(TYPE_INT);
	if (literal.find_first_not_of("0123456789+-.e") == std::string::npos)
		return(TYPE_DOUBLE);
	if (literal.find_first_not_of("0123456789+-.ef") == std::string::npos
		&& literal.find_first_of("01234567") != std::string::npos
		&& literal[literal.find_first_of("f") + 1] == '\0'
		&& literal.find_first_of(".") != std::string::npos
		&& literal.compare(".f") != 0)
		return (TYPE_FLOAT);
	return (TYPE_INVALID);
}
*/


const char*	ScalarConverter::InvalidTypeException::what(void) const throw()
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
