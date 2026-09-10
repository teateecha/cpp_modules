#include "Zombie.hpp"

//allocating on heap:
Zombie*	newZombie(std::string name)
{
	return (new Zombie(name));
}
