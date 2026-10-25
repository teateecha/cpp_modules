#include "ScalarConverter.hpp"
#include <iostream>

// Constructor
ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter: Default Constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(std::string name)
	: _name(name)
{
	std::cout << "ScalarConverter " << _name << ": Constructor called" << std::endl;
}

// Copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	*this = other;
	std::cout << "ScalarConverter " << _name << ": copy-constructed." << std::endl;
}

// Copy assignment operator
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	if (this != &other)
	{
		_name = other._name;
	}
	return (*this);
}

// Destructor
ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter " << _name << ": Destructor called" << std::endl;
}
