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
		
		virtual void	makeSound(void);
	protected:
		std::string		type;
};

#endif

