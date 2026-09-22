#ifndef ANIMAL_HPP
#define ANIMAL_HPP
# include <string>//for std::string

class Animal
{
	public:
		Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual	~Animal(); // virtual so that derived Classes constructor gets called

		std::string	getType(void) const;
		virtual void	makeSound(void) const;
		//enable runtime polymorphism Animal* calles the actual derived makeSound()
		
	protected:
		std::string		_type;
};

#endif

