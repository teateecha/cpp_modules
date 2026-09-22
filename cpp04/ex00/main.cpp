#include <iostream>
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"


int main()
{
	std::cout << "\n--- TEST from Subject ---" << std::endl;
	{
		const Animal*	meta = new Animal();
		const Animal*	j = new Dog();
		const Animal*	i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;

		i->makeSound();//will output the cat sound!
		j->makeSound();
		meta->makeSound();
		delete meta;
		delete j;
		delete i;
	}
	std::cout << "\n--- Wrong Animal TEST ---" << std::endl;
	{
		const WrongAnimal*	meta = new WrongAnimal();
		const WrongAnimal*	i = new WrongCat();

		std::cout << i->getType() << " " << std::endl;

		i->makeSound();//will output the WrongAnimal sound!
		meta->makeSound();
		delete meta;
		delete i;
	}

	return 0;
}
