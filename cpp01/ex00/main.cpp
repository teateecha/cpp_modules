#include "Zombie.hpp"
/*new keyword: allocate memory on heap and free it with delete*/
Zombie*	newZombie(std::string name)
{
	return (new Zombie(name));
}

void randomChump(std::string name)
{
	Zombie random(name);
	
	random.announce();
	return ;
}


int	main(void)
{
	Zombie *ayumi = newZombie("Ayumi");
	randomChump("Bob");
	
	ayumi->announce();
	delete ayumi;
	return (0);
}
