#ifndef ANIMAL_HPP
#define ANIMAL_HPP
# include <string>//for std::string

class Animal
{
	public:
		Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual	~Animal(); //why

		std::string	getType(void) const;
		virtual void	makeSound(void) const;
		
	protected:
		std::string		_type;
};

#endif

