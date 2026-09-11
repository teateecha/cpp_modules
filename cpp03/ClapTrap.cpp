#include "ClapTrap.hpp"
#include <iostream>	//for std

// Constructor
ClapTrap::ClapTrap()
	: _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap: Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap: Constructor called" << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& other)
{
	*this = other;
}

// Copy assignment operator
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap: Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_energyPoints == 0 || _hitPoints == 0)
		std::cout << "ClapTrap 
			<< _name
			<< " is dead." << std::endl;
	else
	{
		_energyPoints -= 1;
		std::cout << "ClapTrap "
			<< _name
			<< " attacks "
			<< target
			<< ", causing "
			<< _attackDamage
			<< "points of damage!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints < amount)
	{
		std::cout << "ClapTrap "
			<< _name
			<< " is dead." << std::endl;
	}
	else
	{
		_hitPoints -= amount;
		std::cout << "ClapTrap "
			<< _name
			<< " was hit and lost "
			<< amount
			<< " hit points. Remainding hit points: "
			<< _hitPoints
			<< "." << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints == 0 || _hitPoints == 0)
		std::cout << "ClapTrap 
			<< _name
			<< " is dead." << std::endl;
	else
	{
		_hitPoints += amount;
		std::cout << "ClapTrap "
			<< _name
			<< " was repaired and  gained "
			<< amount
			<< " hit points. Now there are "
			<< _hitPoints
			<< " hit points!" << std::endl;
	}
}

