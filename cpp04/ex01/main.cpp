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
	std::cout << "\n--- Copy TEST ---" << std::endl;
	{
		const Dog	j = Dog();
		const Dog	i = Dog(j);

		std::cout << "j " << j.getType() << " " << std::endl;
		std::cout <<  "i " <<  i.getType() << " " << std::endl;

		i.makeSound();//will output the dog sound!
		j.makeSound();//will output the dog sound!
	}
		std::cout << "\n--- Brain TEST ---" << std::endl;
	{
		const Dog	j = Dog();

		std::cout << "j " << j.getType() << " " << std::endl;
		j._dogBrain._ideas[0] = "I am a Dog";
		j._dogBrain._ideas[1] = "I am an Animal";
		j._dogBrain._ideas[2] = "I am hungry";
		j.makeSound();//will output the dog sound!
		for (size_t i = 0; i < 3; i++)
			std::cout << j._dogBrain._ideas[i] << std::endl;
		j.makeSound();
	}
		std::cout << "\n--- Animal Array TEST ---" << std::endl;
	{
		Animal	pets[20];

		for (int i = 0; i < 10; i++)
			pets[i] = Dog();
		for (int i = 0; i < 20; i++)
			pets[i] = Cat();
		for (int i = 0; i < 20; i++)
			std::cout << i << "\t" << pets[i].getType() << std::endl;
		for (int i = 0; i < 20; i++)
			delete pets[i];
	}
	return 0;
}
