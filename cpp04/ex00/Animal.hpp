#ifndef ANIMAL_HPP
#define ANIMAL_HPP
# include <string>//for std::string

class Animal
{
	public:
		Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		~Animal();

		std::string	getType(void) const;
		
	protected:
		std::string		_type;
		virtual void	makeSound(void);
};

#endif

