#include "ClapTrap.hpp"
#include <iostream>//for std::cout and std::endl

// Constructor
ClapTrap::ClapTrap()
	: _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap: Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << ": Constructor called" << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& other)
{
	*this = other;
	std::cout << "ClapTrap " << _name << ": copy-constructed." << std::endl;
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
	std::cout << "ClapTrap " << _name << ": Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
		std::cout << "ClapTrap "
			<< _name
			<< " cannot attack: no hit points left." << std::endl;
	else if (_energyPoints == 0)
		std::cout << "ClapTrap "
			<< _name
			<< " cannot attack: no energy points left." << std::endl;
	else
	{
		_energyPoints -= 1;
		std::cout << "ClapTrap "
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

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= amount)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	std::cout << "ClapTrap "
		<< _name
		<< " takes "
		<< amount
		<< " points of damage. Remaining hit points: "
		<< _hitPoints
		<< "." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints == 0)
		std::cout << "ClapTrap "
			<< _name
			<< " cannot repair itself: no energy points left." << std::endl;
	else if (_hitPoints == 0)
		std::cout << "ClapTrap "
			<< _name
			<< " cannot repair itself: no hit points left." << std::endl;
	else
	{
		_hitPoints += amount;
		_energyPoints--;
		std::cout << "ClapTrap "
			<< _name
			<< " repairs itself, gaining "
			<< amount
			<< " hit points. Hit points: "
			<< _hitPoints
			<< ". Energy points: "
			<< _energyPoints << std::endl;
	}
}

