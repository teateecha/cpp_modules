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
	return ("char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible");
}

//all ordinary comparisons with nan are false
static void		numberPrint(double result)
{
	if (result >= INT_MIN && result <= static_cast<double>(INT_MAX) + 1.0)
	{
		if (result >= ' '  && result < '~' + 1)
			std::cout << "char: '" <<  static_cast<char>(result) << "'" << std::endl;
		else if (result > -1 && result < 128)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: imposible" << std::endl;
		std::cout << "int: " << static_cast<int>(result) << std::endl;
	}
	else
		std::cout << "char: impossible\nint: impossible" <<std::endl;
	std::cout << std::fixed;
	std::cout << "float: " << static_cast<float>(result) << "f" << std::endl;
	std::cout << "double: "  << result << std::endl;
}

static int	validate(std::string literal)
{
	//TODO
}

int	ScalarConverter::convert(std::string literal)
{
	double	result;
	char*	str_end;
	errno = 0;

	try
	{
		if (std::isspace(literal[0]))
				throw(InvalidException());
		result = std::strtod(literal.c_str(), &str_end);
		if (errno == ERANGE || str_end == literal.c_str()
				|| (*str_end != '\0' && !(str_end[0] == 'f' && str_end[1] == '\0'))
				|| literal.compare(0, 2, "0x") == 0)//CHECK for under-or-overflow and if parsable
			throw (InvalidException());
		numberPrint(result);
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
