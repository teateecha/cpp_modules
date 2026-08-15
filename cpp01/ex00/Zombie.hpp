#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>/*for std::string*/

class Zombie
{
	public:
		
		Zombie(std::string iname);
		~Zombie();
		void	announce(void);

	private:
		std::string _name;
};

Zombie*	newZombie(std::string name);
void randomChump(std::string name);

#endif
