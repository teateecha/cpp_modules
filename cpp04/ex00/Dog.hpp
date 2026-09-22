#ifndef DOG_HPP
#define DOG_HPP
# include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		~Dog();

		void	makeSound(void) const;//has to be public so that it can be called by Animal

};

#endif

