#include "HumanB.hpp"
#include <iostream>	//for std
#include <string>//for std::string

// Constructor
HumanB::HumanB(std::string name)
	: _name(name), _weaponB(NULL)
{
	std::cout << "HumanB: Constructor called" << std::endl;
}

// Destructor
HumanB::~HumanB()
{
	std::cout << "HumanB: Destructor called" << std::endl;
}


void	HumanB::attack(void) const
{
	if (_weaponB)
	{
		std::cout << _name
				<< " attacks with their "
				<< _weaponB->getType()
				<< std::endl;

	}
	else
		std::cout << _name << " has no weapon." << std::endl;
}


//takes a reference and assignes the addres to _weapon
//without '&'setWeapon(Weapon weapon)
void	HumanB::setWeapon(Weapon& weapon)
{
	_weaponB = &weapon;
}
