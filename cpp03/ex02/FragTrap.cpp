#include "FragTrap.hpp"
#include <iostream>

// Constructor
FragTrap::FragTrap()
	: ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap: Default Constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name)
	: ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << ": Constructor called" << std::endl;
}

// Copy constructor
FragTrap::FragTrap(const FragTrap& other)
	: ClapTrap(other)
{
	std::cout << "FragTrap " << _name << ": copy-constructed." << std::endl;
}

// Copy assignment operator
FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return *this;
}

// Destructor
FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << ": Destructor called" << std::endl;
}


void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " requests a high five!!" << std::endl;
}
