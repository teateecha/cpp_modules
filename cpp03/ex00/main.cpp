#include "ClapTrap.hpp"
#include <iostream>

int	main(void)
{
	const std::string	victim = "Victim Tom";

	std::cout << "\n--- DAMAGE / DEATH TEST ---\n";
	ClapTrap felix("Felix");

	felix.attack(victim);
	felix.takeDamage(5);
	felix.beRepaired(1);
	felix.takeDamage(7);
	felix.attack(victim);

	std::cout << "\n--- ENERGY TEST ---\n";
	ClapTrap anna("Anna");

	for (int i = 0; i < 11; i++)
	{
		std::cout << "Attack " << i + 1 << ": ";
		anna.attack(victim);
	}

	return (0);
}
