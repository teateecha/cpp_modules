#ifndef CAT_HPP
#define CAT_HPP
# include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		~Cat();

		void	makeSound(void) const;//has to be public so that it can be called by Animal
};

#endif

