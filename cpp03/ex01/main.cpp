#include <iostream>
#include "ScavTrap.hpp" //has ClapTrap included

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

	for (int i = 0; i < 10; i++)
	{
		std::cout << "Attack " << i + 1 << ": ";
		anna.attack(victim);
	}

	anna.beRepaired(5);
	anna.attack(victim);

	std::cout << "\n ----ScavTrap TEST ---\n";
	ScavTrap	sonya("Sonya");

	sonya.attack(victim); //should show 20 damage
	sonya.guardGate();

	std::cout << "\n DESTRUCTORS: --- " << std::endl;
	return (0);
}
