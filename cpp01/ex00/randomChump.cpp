#include "Zombie.hpp"

//allocating on stack
void randomChump(std::string name)
{
	Zombie random(name);
	
	random.announce();
	return ;
}
