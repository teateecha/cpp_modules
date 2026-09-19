#include <iostream>
#include "DiamondTrap.hpp"

int	main(void)
{
	const std::string	victim = "Victim Tom";

	std::cout << "\n--- DAMAGE / DEATH TEST ---\n";
	ClapTrap felix("Felix");

	felix.attack(victim);
	felix.takeDamage(5);
	felix.beRepaired(1);
	felix.takeDamage(7);
	felix.attack(victim); // no hit points left

	std::cout << "\n--- ENERGY TEST ---\n";
	ClapTrap anna("Anna");

	for (int i = 0; i < 10; i++)
	{
		std::cout << "Attack " << i + 1 << ": ";
		anna.attack(victim);
	}

	anna.beRepaired(5); // no energy points left
	anna.attack(victim); // no energy points left

	std::cout << "\n ----ScavTrap TEST ---\n";
	ScavTrap	sonya("Sonya");

	sonya.attack(victim); //should show 20 damage
	sonya.beRepaired(1);
	sonya.guardGate();

	std::cout << "\n ----FragTrap TEST ---\n";
	FragTrap	finn("Finn");

	finn.highFivesGuys();
	finn.attack(victim);
	finn.beRepaired(30);
	finn.takeDamage(40);
	std::cout << "\n ----DiamondTrap TEST ---\n";
	DiamondTrap d("Didi");
	d.whoAmI();
	d.attack(victim);       // ScavTrap attack
	d.guardGate();
	d.highFivesGuys();
	d.takeDamage(20);
	d.beRepaired(10);

	std::cout << "\n DESTRUCTORS: --- " << std::endl;
	return (0);
}
