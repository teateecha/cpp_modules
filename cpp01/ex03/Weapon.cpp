#include "Weapon.hpp"
#include <iostream> //for std
#include <string>	//for std::string

Weapon::Weapon(std::string type) : _type(type)
{
	std::cout << "Weapon: constructor called" << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout << "Weapon: Destructor called" << std::endl;
}


std::string const &	Weapon::getType(void) const
{
	return(this->_type);
}

void	Weapon::setType(std::string newtype)
{
	this->_type = newtype;
}
