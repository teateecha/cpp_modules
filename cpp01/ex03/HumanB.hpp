#ifndef HUMANB_HPP
#define HUMANB_HPP
# include <iostream>	//for std
# include <string>	//for std::string
# include "Weapon.hpp"	//for weapon

//HumanB takes a Pointer to a weapon
class HumanB
{
	public:
		HumanB(std::string name);
		~HumanB();
		void		attack(void) const;
		void		setWeapon(Weapon& weapon);

	private:
		std::string	_name;
		Weapon		*_weaponB;
};

#endif
