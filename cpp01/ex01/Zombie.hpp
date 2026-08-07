#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>/*for std::string*/

class Zombie
{
	public:
		
		Zombie();/*default constructor*/
		Zombie(std::string iname);
		~Zombie();
		void	announce(void);
		void	setName(std::string newname);

	private:
		std::string _name;
};

Zombie* zombieHorde(int N, std::string name);

#endif
