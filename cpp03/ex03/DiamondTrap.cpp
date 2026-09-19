#include "DiamondTrap.hpp"
#include <iostream>	//for std

// Constructor
DiamondTrap::DiamondTrap()
	: ClapTrap() ,  ScavTrap(), FragTrap()
{
	
	std::cout << "DiamondTrap: Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name), Frag

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap& other)
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

