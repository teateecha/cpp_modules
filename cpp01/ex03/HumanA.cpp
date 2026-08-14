#include "HumanA.hpp"
#include <iostream>	//for std

// Constructor
HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weaponA(weapon)
{
	std::cout << "HumanA: Constructor called" << std::endl;
}

// Destructor
HumanA::~HumanA()
{
	std::cout << "HumanA: Destructor called" << std::endl;
}


void	HumanA::attack(void) const
{
	std::cout << _name
			<< " attacks with their "
			<< _weaponA.getType()
			<< std::endl;
}
