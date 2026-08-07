#include "Zombie.hpp"

/*TODO research delete[]*/
int	main(void)
{
	Zombie* horde = zombieHorde(5, "Helga");

	for (int i = 0; i < 5; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}
