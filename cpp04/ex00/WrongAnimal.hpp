#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
# include <string>//for std::string

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal& operator=(const WrongAnimal& other);
		virtual	~WrongAnimal(); //why

		std::string	getType(void) const;
		void	makeSound(void) const;
		
	protected:
		std::string		_type;
};

#endif

