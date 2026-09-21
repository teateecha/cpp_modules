#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string iname) : _name(iname) 
{
	std::cout << _name << ": Constructor called" << std::endl;
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
