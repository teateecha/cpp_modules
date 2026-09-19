#include "DiamondTrap.hpp"
#include <iostream>	//for std

// Constructor
DiamondTrap::DiamondTrap()
	: ClapTrap() ,  ScavTrap(), FragTrap()
{
	
	std::cout << "DiamondTrap: Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{

}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap& other)
	ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	*this = other;
}

// Copy assignment operator
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return *this;
}

// Destructor
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap: Destructor called" << std::endl;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name: " << _name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}
