#include <iostream>
#include "Cat.hpp"
#include "Dog.hpp"


int main()
{
	std::cout << "\n--- TEST from Subject ---" << std::endl;
	const Animal*	meta = new Animal();
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound();
	//will output the cat sound! j->makeSound()
	meta->makeSound();
	std::cout << "\n--- operator overload test ---" << std::endl;
	std::cout << "\n--- sound test ---" << std::endl;

	return 0;
}
