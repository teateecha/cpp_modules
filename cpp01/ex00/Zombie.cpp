#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string iname) : _name(iname) 
{
	std::cout << _name << ": Constructor called\n";
}

Zombie::~Zombie()
{
    std::cout << _name << ": Destructor called" << std::endl;
}

/*dont forget the namespace.*/
void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

/*

Zombie::Zombie(const Zombie& other)
{
	std::cout << "Copy consturctor called" << std::endl;
}

Zombie& Zombie::operator=(const Zombie& other)
{
	std::cout << "Copy assignment operator called" << std::enl;
	if(this != &other)
	{

	}
	return (*this);
}
*/
