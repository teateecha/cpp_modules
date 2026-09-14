#include "Zombie.hpp"

int	main(void)
{
	Zombie *anna = newZombie("Anna");
	randomChump("Bob");
	
	anna->announce();
	delete anna;
	return (0);
}
