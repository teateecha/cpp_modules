#ifndef ANIMAL_HPP
#define ANIMAL_HPP
# include <string>//for std::string

class Animal
{
	public:
		Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		// virtual so deleting through Animal* calls the derived Destructor first
		virtual	~Animal();

		std::string	getType(void) const;
		//enable runtime polymorphism: Animal* calles the derived makeSound()
		virtual void	makeSound(void) const;
		
	protected:
		std::string		_type;
};

#endif

