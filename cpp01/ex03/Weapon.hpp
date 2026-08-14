#ifndef WEAPON_HPP
#define WEAPON_HPP
# include <iostream>
# include <string> //for std::string

class Weapon
{
	public:
		Weapon(std::string type);
		~Weapon(void);
		std::string const &	getType(void) const;//2dn const promise not to change
		void				setType(std::string newtype);

	private:
		std::string	_type;

};

#endif

