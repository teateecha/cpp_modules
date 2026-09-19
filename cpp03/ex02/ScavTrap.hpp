#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();// Default Constructor
		ScavTrap(std::string name); // Constructor
		ScavTrap(const ScavTrap& other); // Copy constructor
		ScavTrap& operator=(const ScavTrap& other); // operator overload
		~ScavTrap(); // Destructor

		void	attack(const std::string& target);
		void	guardGate();
};

#endif
