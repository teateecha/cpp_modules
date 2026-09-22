#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
# include <string>//for std::string

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal& operator=(const WrongAnimal& other);
		~WrongAnimal(); //will always call BaseClass constructor

		std::string	getType(void) const;
		void	makeSound(void) const; //missing virtual keyword -> Compiler confusion of different functions
		
	protected:
		std::string		_type;
};

#endif

