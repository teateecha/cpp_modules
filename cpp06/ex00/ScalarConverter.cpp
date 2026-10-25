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

