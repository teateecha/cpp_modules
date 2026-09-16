#include "ScavTrap.hpp"
#include <iostream>

// Constructor
ScavTrap::ScavTrap()
	: ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap: Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << ": Constructor called" << std::endl;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap& other)
{
	*this = other;
	std::cout << "ScavTrap " << _name << ": copy-constructed." << std::endl;
}

// Copy assignment operator
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		_name = other._name;
	}
	return *this;
}

// Destructor
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << ": Destructor called" << std::endl;
}



void	ClapTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
		std::cout << "ScavTrap "
			<< _name
			<< " cannot attack: no hit points left." << std::endl;
	else if (_energyPoints == 0)
		std::cout << "ClapTrap "
			<< _name
			<< " cannot attack: no energy points left." << std::endl;
	else
	{
		_energyPoints -= 1;
		std::cout << "ScavTrap "
			<< _name
			<< " attacks "
			<< target
			<< ", causing "
			<< _attackDamage
			<< " points of damage!"
			<< " Energy points remaining: "
			<< _energyPoints << "." << std::endl;
	}
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap" << _name << "is now in Gate keeper mode." << std::endl;
}
