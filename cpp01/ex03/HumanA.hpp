#ifndef HUMANA_HPP
#define HUMANA_HPP
# include <iostream>	//for std
# include <string>	//for std::string
# include "Weapon.hpp"	//for weapon

//HumanA takes a Reference to a weapon
class HumanA
{
	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA();
		void		attack(void) const;

	private:
		std::string	_name;
		Weapon&		_weaponA;
};

#endif
