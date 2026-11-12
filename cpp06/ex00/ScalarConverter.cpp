#include "ScalarConverter.hpp"
#include <cctype>//for std::isspace
#include <iomanip>//for setprecision
#include <climits>//for INT_MAX
#include <cstdlib>//for strtod()
#include <cmath>
#include <errno.h>//for errno
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


const char*	ScalarConverter::InvalidException::what(void) const throw()
{
	return ("invalid input");
}

//all ordinary comparisons with nan are false
static void		numberPrint(void* result, t_type type)
{
	switch (type)
	{
		case TYPE_CHAR:
			char *value = static_cast<char *>(result);
		case TYPE_INT:
			int *value = static_cast<int *>(result);
		case TYPE_DOUBLE:
			double *value = static_cast<double *>(result);
		case TYPE_FLOAT:
			float *value = static_cast<float *>(result);
		default:
			throw (InvalidException());
	}

	double test = static_cast<double>(*result);
	if (type <= TYPE_INT || (test >= INT_MIN && test < static_cast<double>(INT_MAX) + 1.0))
	{
		if (*value >= ' '  && *value < '~' + 1)
			std::cout << "char: '" <<  static_cast<char>(*value) << "'" << std::endl;
		else if (*value > -1 && *value < 128)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: imposible" << std::endl;
		std::cout << "int: " << static_cast<int>(*value) << std::endl;
	}
	else std::cout << "char: impossible\nint: impossible" <<std::endl;
	std::cout << std::fixed;
	std::cout << "float: " << static_cast<float>(*value) << "f" << std::endl;
	std::cout << "double: "  << static_cast<double>(*value) << std::endl;
}

static t_type	detectType(std::string literal)
{
	if (literal.length == 0 || std::string::isspace(static_cast<unsigned char>(literal[0])))
		return (TYPE_INVALID);
	if ((literal.length() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0])))
			|| (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\''))//accepts "'1'"
		return (TYPE_CHAR);
	// if (literal.find_first_of("+-") != std::string::npos)//there is at least one + or -
	// {
	// 	if (literal.find_first_of("+-") == 0)
	// 		literal.erase(0,1);//is this removing it from the original or just inside this function?
	// 	if (literal.find_first_of("+-") != std::string::npos
	// 		&& (literal.find_first_of("e") == std::string::npos
	// 		|| literal.find_first_of("e") != literal.find_last_of("e")
	// 		|| literal.find_first_of("+-") - literal.find_first_of("e") != 1))
	// 			return (TYPE_INVALID);
	// }
	if (literal.find_first_not_of("0123456789+e") == std::string::npos)
		return(TYPE_INT);
	if (literal.find_first_not_of("0123456789-+.e") == std::string::npos
			|| literal.compare("nan") == 0
			|| literal.compare("-inf") == 0
			|| literal.compare("+inf") == 0)
		return(TYPE_DOUBLE);
	if ((literal.find_first_not_of("0123456789-+.ef") == std::string::npos
		&& literal.find_first_of("01234567") != std::string::npos
		&& literal[literal.find_first_of("f") + 1] == '\0'
		&& literal.find_first_of(".") != std::string::npos
		&& literal.compare(".f") != 0)
		|| literal.compare("-inff") == 0
		|| literal.compare("+inff") == 0)
		return (TYPE_FLOAT);
	return (TYPE_INVALID);
}

static int	checkOnResult(std::string literal, char* str_end)
{
	if (isspace(literal.c_str()[0])// no leading whitespace
			|| literal.find_first_of("+-") != literal.find_last_of("+-")// no double signes
			|| errno == ERANGE
			|| str_end == literal.c_str()//this happens if strtod fails
			|| (*str_end != '\0' && !(str_end[0] == 'f' && str_end[1] == '\0'))//CHECK for under-or-overflow and if parsable return (FAIL);
			|| literal.compare(0, 2, "0x") == 0)
			return(1);
	else
		return (0);
}


static void	doConversions(void *result, std::string literal, t_type type)
{
	size_t	str_end = 0;
	char*	endptr = "a";

	switch (type)
	{
		case TYPE_CHAR:
		{
			static_cast<char>(*result);
			if (literal.lenght == 3)
				*result = literal[1];
			else if (literal.lenght == 1)
				*result = literal[0];
			else
				throw (InvalidException());
			break ;
		}
		case TYPE_INT:
		{
			double test = str::strtod(literal, &endptr);
			if (test >= INT_MIN && test < static_cast<double>(INT_MAX) + 1.0 || endptr != std::string::npos)
				throw (InvalidException());
			static_cast<int>(*result) = str::stoi(literal, &str_end);
			if (literal[str_end] != '\0')
				throw (InvalidException());
			break ;
		}
		case TYPE_DOUBLE:
		{
			static_cast<double>(*result) = std::strtod(literal, &endptr)
			if (checkOnResult(literal, endptr))
				throw (InvalidException());
		}
		default:
			throw (InvalidException);
			break;
	}
}

int	ScalarConverter::convert(std::string literal)
{
	void*	result;
	char*	str_end;
	t_type	type;
	errno = 0;

	try
	{
		type = detectType(literal);
		if (type == TYPE_INVALID)
			throw (InvalidException());
		doConversions(result, literal, type);
		std::cout << "result is: " << type <<std::endl;
		numberPrint(result, type);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}



	/*
 * from subject:
 * ./convert 0 char: Non displayable int: 0 float: 0.0f double: 0.0
 * ./convert nan char: impossible int: impossible float: nanf double: nan
 * ./convert 42.0f char: '*' int: 42 float: 42.0f double: 42.0
 */



