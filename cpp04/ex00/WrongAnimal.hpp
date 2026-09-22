#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
# include <string>//for std::string

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal& operator=(const WrongAnimal& other);
		//intentionally non-virtual.
		~WrongAnimal();

		std::string	getType(void) const;
		//missing virtual keyword -> Animal* calls the WrongAnimal::makeSound()
		void	makeSound(void) const;
		
	protected:
		std::string		_type;
};

#endif

