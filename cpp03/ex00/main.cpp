#include <iostream>
#include "ClapTrap.hpp"

int	main(void)
{
	const std::string	victim = "Victim Tom";

	{
		std::cout << "\n--- DAMAGE / DEATH TEST ---\n";
		ClapTrap felix("Felix");
		felix.attack(victim);
		felix.takeDamage(5);
		ClapTrap copy_of_felix(felix);
		felix.beRepaired(1);
		felix.takeDamage(7);
		felix.attack(victim); // no hit points left
		copy_of_felix.beRepaired(5);// this will work
		std::cout << "\n DESTRUCTOR: --- " << std::endl;
	}

	std::cout << "\n--- ENERGY TEST ---\n";

	ClapTrap anna("Anna");
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Attack " << i + 1 << ": ";
		anna.attack(victim);
	}

	anna.beRepaired(5); // no energy points left
	anna.attack(victim); // no energy points left

	std::cout << "\n DESTRUCTOR: --- " << std::endl;
	return (0);
}
