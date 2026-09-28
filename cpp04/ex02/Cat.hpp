#ifndef CAT_HPP
#define CAT_HPP
# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
	public:
		Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		~Cat();

		void	makeSound(void) const;//has to be public so that it can be called by Animal
		Brain*	getBrain(void) const;
	private:
		Brain*	_catBrain;
};

#endif

